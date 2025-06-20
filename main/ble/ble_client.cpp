#include "NimBLEDevice.h"
#include "esp_log.h"
#include "ui.h"

static const char *TAG = "BLE_CLIENT";

// UUID'ы сервиса и характеристики
#define SERVICE_UUID        "FFE0"
#define CHARACTERISTIC_UUID "FFE1"

NimBLEAdvertisedDevice* advDevice = nullptr;
NimBLEClient* pClient = nullptr;
NimBLERemoteCharacteristic* pRemoteCharacteristic = nullptr;

extern int correct_counter;
extern int incorrect_counter;
extern bool isPaused;
extern int launch_ind;

void inrCor(){
    correct_counter++;

    char buf[24];
    snprintf(buf, sizeof(buf), "Correct %u", correct_counter);
    lv_label_set_text(ui_LabelCorrect, buf);

}

void inrIncor(){
    incorrect_counter++;

    char buf[24];
    snprintf(buf, sizeof(buf), "Incorrect %u", incorrect_counter);
    lv_label_set_text(ui_LabelIncorrect, buf);

}

void notifyCallback(NimBLERemoteCharacteristic* pRemoteCharacteristic,
                    uint8_t* pData, size_t length, bool isNotify) {
    std::string response((char*)pData, length);
    ESP_LOGI(TAG, "Notify received: %s", response.c_str());

    if (response == "correct" and isPaused==false) {
        inrCor();
    } else if (response == "incorrect" and isPaused==false) {
        inrIncor();
    }
    else if (response == "complete") {
        pRemoteCharacteristic->writeValue("pause");
    }  
}

void connectAndSubscribe() {
    if (!advDevice) {
        ESP_LOGW(TAG, "Нет устройства для подключения");
        return;
    }

    pClient = NimBLEDevice::createClient();
    ESP_LOGI(TAG, "Создан BLE-клиент");

    if (!pClient->connect(advDevice)) {
        ESP_LOGE(TAG, "Не удалось подключиться");
        NimBLEDevice::deleteClient(pClient);
        return;
    }

    ESP_LOGI(TAG, "Подключено к %s", pClient->getPeerAddress().toString().c_str());

    NimBLERemoteService* pService = pClient->getService(SERVICE_UUID);
    if (!pService) {
        ESP_LOGE(TAG, "Сервис не найден");
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
            ESP_LOGI(TAG, "Подписка успешна");
            lv_obj_clear_flag(ui_ImageBLE, LV_OBJ_FLAG_HIDDEN);

            std::string launchCommand = "launch " + std::to_string(launch_ind);
            if (pRemoteCharacteristic->canWrite()) {
                pRemoteCharacteristic->writeValue(launchCommand);
                ESP_LOGI(TAG, "%s", launchCommand.c_str());
            } else {
                ESP_LOGW(TAG, "Характеристика не поддерживает запись");
            }
        } else {
            ESP_LOGE(TAG, "Ошибка при подписке");
        }
    }
}

class MyScanCallbacks : public NimBLEScanCallbacks {
    void onResult(const NimBLEAdvertisedDevice* advertisedDevice) override {
        ESP_LOGI(TAG, "Найдено устройство: %s", advertisedDevice->toString().c_str());

        if (advertisedDevice->isAdvertisingService(NimBLEUUID(SERVICE_UUID))) {
            ESP_LOGI(TAG, "Найден нужный сервис, останавливаем сканирование...");
            advDevice = new NimBLEAdvertisedDevice(*advertisedDevice);  // создаём копию
            NimBLEDevice::getScan()->stop();  // остановить сканирование

             esp_timer_handle_t delay_timer;
            const esp_timer_create_args_t delay_args = {
            .callback = [](void*) { connectAndSubscribe(); },
            .name = "connect_delay"
             };
            esp_timer_create(&delay_args, &delay_timer);
            esp_timer_start_once(delay_timer, 200 * 1000);  // 200 мс
        }
    }
};


extern "C" void ble_client_init() {
    NimBLEDevice::init("");

    NimBLEScan* pScan = NimBLEDevice::getScan();
    pScan->setScanCallbacks(new MyScanCallbacks());
    pScan->setInterval(45);
    pScan->setWindow(15);
    pScan->setActiveScan(true);

    ESP_LOGI(TAG, "Сканирование на 10 секунд...");
    pScan->start(16000, connectAndSubscribe);  // Время в секундах
    ESP_LOGI(TAG, "Сканирование окончено");
}

extern "C" void ble_send_message(const char* message) {
    if (pRemoteCharacteristic && pRemoteCharacteristic->canWrite()) {
        pRemoteCharacteristic->writeValue((uint8_t*)message, strlen(message));
        ESP_LOGI("BLE", "Отправлено сообщение: %s", message);
    } else {
        ESP_LOGW("BLE", "Невозможно отправить: нет характеристики или запись недоступна");
    }
}