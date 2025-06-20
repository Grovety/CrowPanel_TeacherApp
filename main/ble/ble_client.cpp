#include "NimBLEDevice.h"
#include "esp_log.h"
#include "ui.h"

static const char *TAG = "BLE_CLIENT";

#define SERVICE_UUID "FFE0"
#define CHARACTERISTIC_UUID "FFE1"

NimBLEAdvertisedDevice *advDevice = nullptr;
NimBLEClient *pClient = nullptr;
NimBLERemoteCharacteristic *pRemoteCharacteristic = nullptr;

extern int correct_counter;
extern int incorrect_counter;
extern bool isPaused;
extern int launch_ind;

void inrCor() {
  correct_counter++;

  char buf[24];
  snprintf(buf, sizeof(buf), "Correct %u", correct_counter);
  lv_label_set_text(ui_LabelCorrect, buf);
}

void inrIncor() {
  incorrect_counter++;

  char buf[24];
  snprintf(buf, sizeof(buf), "Incorrect %u", incorrect_counter);
  lv_label_set_text(ui_LabelIncorrect, buf);
}

void notifyCallback(NimBLERemoteCharacteristic *pRemoteCharacteristic,
                    uint8_t *pData, size_t length, bool isNotify) {
  std::string response((char *)pData, length);
  ESP_LOGI(TAG, "Notify received: %s", response.c_str());

  if (response == "correct" and isPaused == false) {
    inrCor();
  } else if (response == "incorrect" and isPaused == false) {
    inrIncor();
  } else if (response == "complete") {
    pRemoteCharacteristic->writeValue("pause");
  }
}

void connectAndSubscribe() {
  if (!advDevice) {
    ESP_LOGW(TAG, "no device to connect to");
    return;
  }

  pClient = NimBLEDevice::createClient();
  ESP_LOGI(TAG, "BLE client created");

  if (!pClient->connect(advDevice)) {
    ESP_LOGE(TAG, "Couldn't connect");
    NimBLEDevice::deleteClient(pClient);
    return;
  }

  ESP_LOGI(TAG, "Connected to %s",
           pClient->getPeerAddress().toString().c_str());

  NimBLERemoteService *pService = pClient->getService(SERVICE_UUID);
  if (!pService) {
    ESP_LOGE(TAG, "service was not found");
    pClient->disconnect();
    return;
  }

  pRemoteCharacteristic = pService->getCharacteristic(CHARACTERISTIC_UUID);
  if (!pRemoteCharacteristic) {
    ESP_LOGE(TAG, "Характеристика не найдена");
    pClient->disconnect();
    return;
  }

  if (pRemoteCharacteristic->canNotify()) {
    if (pRemoteCharacteristic->subscribe(true, notifyCallback)) {
      ESP_LOGI(TAG, "Characteristic not found");
      lv_obj_clear_flag(ui_ImageBLE, LV_OBJ_FLAG_HIDDEN);

      std::string launchCommand = "launch " + std::to_string(launch_ind);
      if (pRemoteCharacteristic->canWrite()) {
        pRemoteCharacteristic->writeValue(launchCommand);
        ESP_LOGI(TAG, "%s", launchCommand.c_str());
      } else {
        ESP_LOGW(TAG, "characteristic does not support recording");
      }
    } else {
      ESP_LOGE(TAG, "Error when subscribing");
    }
  }
}

class MyScanCallbacks : public NimBLEScanCallbacks {
  void onResult(const NimBLEAdvertisedDevice *advertisedDevice) override {
    ESP_LOGI(TAG, "Device found: %s", advertisedDevice->toString().c_str());

    if (advertisedDevice->isAdvertisingService(NimBLEUUID(SERVICE_UUID))) {
      ESP_LOGI(TAG, "The necessary service is found, stop scanning...");
      advDevice = new NimBLEAdvertisedDevice(*advertisedDevice);
      NimBLEDevice::getScan()->stop();

      esp_timer_handle_t delay_timer;
      const esp_timer_create_args_t delay_args = {
          .callback = [](void *) { connectAndSubscribe(); },
          .name = "connect_delay"};
      esp_timer_create(&delay_args, &delay_timer);
      esp_timer_start_once(delay_timer, 200 * 1000);
    }
  }
};

extern "C" void ble_client_init() {
  NimBLEDevice::init("");

  NimBLEScan *pScan = NimBLEDevice::getScan();
  pScan->setScanCallbacks(new MyScanCallbacks());
  pScan->setInterval(45);
  pScan->setWindow(15);
  pScan->setActiveScan(true);

  ESP_LOGI(TAG, "Scan for 10 seconds...");
  pScan->start(16000, connectAndSubscribe);
  ESP_LOGI(TAG, "scan is over");
}

extern "C" void ble_send_message(const char *message) {
  if (pRemoteCharacteristic && pRemoteCharacteristic->canWrite()) {
    pRemoteCharacteristic->writeValue((uint8_t *)message, strlen(message));
    ESP_LOGI("BLE", "message was sent: %s", message);
  } else {
    ESP_LOGW("BLE", "Unable to send: no feature or recording is available");
  }
}