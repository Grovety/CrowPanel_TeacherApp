
#include "waveshare_rgb_lcd_port.h"
#include "ui.h"
#include "driver/gpio.h"

#include "driver/i2c.h"
#include <stdio.h>

#include "ble_client.h"
#include "nvs_flash.h"
#include "nvs.h"

#include "esp_log.h"

#define I2C_MASTER_SDA_IO    15   
#define I2C_MASTER_SCL_IO    16   
#define I2C_MASTER_FREQ_HZ   400000  
#define I2C_MASTER_PORT      I2C_NUM_1  
#define TCA9534_ADDR         0x18  

uint32_t seconds_counter = 0;
int correct_counter = 0;
int incorrect_counter = 0;
extern int launch_ind;
extern bool is_timer;
extern int base_time;
extern bool isReset;
extern bool isPaused;
extern int timer_ind;

lv_timer_t* my_timer = NULL;

int load_int(const char *key, int default_value) {
    nvs_handle_t handle;
    esp_err_t err = nvs_open("storage", NVS_READONLY, &handle);
    if (err != ESP_OK) return default_value;

    int32_t val = 0;
    if (nvs_get_i32(handle, key, &val) == ESP_OK) {
        nvs_close(handle);
        return val;
    } else {
        nvs_close(handle);
        ESP_LOGE(TAG, "Load error");
        return default_value;
    }
}

void save_score(int game_time, int game_mode, int score, int total) {
    char key_last_score[32];
    char key_last_total[32];
    char key_best_score[32];
    char key_best_total[32];

    snprintf(key_last_score, sizeof(key_last_score), "s%d%d_ls", game_time, game_mode);
    snprintf(key_last_total, sizeof(key_last_total), "s%d%d_lt", game_time, game_mode);
    snprintf(key_best_score, sizeof(key_best_score), "s%d%d_bs", game_time, game_mode);
    snprintf(key_best_total, sizeof(key_best_total), "s%d%d_bt", game_time, game_mode);

    ESP_LOGI("SCORE", "Saving scores for game_time=%d, game_mode=%d", game_time, game_mode);
    ESP_LOGI("SCORE", "Keys: last_score='%s', last_total='%s', best_score='%s', best_total='%s'",
             key_last_score, key_last_total, key_best_score, key_best_total);
    ESP_LOGI("SCORE", "New score: %d/%d", score, total);

    nvs_handle_t nvs;
    esp_err_t err = nvs_open("storage", NVS_READWRITE, &nvs);
    if (err != ESP_OK) {
        ESP_LOGE("SCORE", "NVS open failed! err=0x%x", err);
        return;
    }

    // Save last score and total
    err = nvs_set_i32(nvs, key_last_score, score);
    if (err != ESP_OK) ESP_LOGE("SCORE", "Failed to set last_score: err=0x%x", err);
    else ESP_LOGI("SCORE", "Last score saved: %d", score);

    err = nvs_set_i32(nvs, key_last_total, total);
    if (err != ESP_OK) ESP_LOGE("SCORE", "Failed to set last_total: err=0x%x", err);
    else ESP_LOGI("SCORE", "Last total saved: %d", total);

    // Compare and save best only if current score is higher
    int32_t best_score = 0;
    err = nvs_get_i32(nvs, key_best_score, &best_score);
    if (err == ESP_OK) {
        ESP_LOGI("SCORE", "Current best score: %ld", best_score);
    } else {
        ESP_LOGI("SCORE", "No previous best score found (err=0x%x)", err);
    }

    if (err != ESP_OK || score > best_score) {
        ESP_LOGI("SCORE", "New best score! Updating best score and total.");
        err = nvs_set_i32(nvs, key_best_score, score);
        if (err != ESP_OK) ESP_LOGE("SCORE", "Failed to set best_score: err=0x%x", err);
        else ESP_LOGI("SCORE", "Best score saved: %d", score);

        err = nvs_set_i32(nvs, key_best_total, total);
        if (err != ESP_OK) ESP_LOGE("SCORE", "Failed to set best_total: err=0x%x", err);
        else ESP_LOGI("SCORE", "Best total saved: %d", total);
    } else {
        ESP_LOGI("SCORE", "Current score %d is not higher than best score %ld, not updating best.", score, best_score);
    }

    err = nvs_commit(nvs);
    if (err != ESP_OK) {
        ESP_LOGE("SCORE", "Failed to commit NVS changes: err=0x%x", err);
    } else {
        ESP_LOGI("SCORE", "NVS commit successful");
    }
    nvs_close(nvs);
}

char* get_score_string(int game_time, int game_mode, bool best) {
    static char result[32];  // Статическая строка, чтобы вернуть указатель

    char key_score[32];
    char key_total[32];
    int32_t score = 0, total = 0;

    snprintf(key_score, sizeof(key_score), "s%d%d_%s", game_time, game_mode, best ? "bs" : "ls");
    snprintf(key_total, sizeof(key_total), "s%d%d_%s", game_time, game_mode, best ? "bt" : "lt");

    nvs_handle_t nvs;
    esp_err_t err = nvs_open("storage", NVS_READONLY, &nvs);
    if (err == ESP_OK) {
        nvs_get_i32(nvs, key_score, &score);
        nvs_get_i32(nvs, key_total, &total);
        nvs_close(nvs);
    }

    snprintf(result, sizeof(result), "%ld/%ld", score, total);
    return result;
}

static void timer_update_cb(lv_timer_t *timer)
{
    if(is_timer==false){
        seconds_counter++;

        uint32_t minutes = seconds_counter / 60;
        uint32_t seconds = seconds_counter % 60;

        char buf[24];
        snprintf(buf, sizeof(buf), "Time %02lu:%02lu", minutes, seconds);

        lv_label_set_text(ui_LabelTime, buf);
    }
    else if(seconds_counter!=0){
        seconds_counter--;

        uint32_t minutes = seconds_counter / 60;
        uint32_t seconds = seconds_counter % 60;

        char buf[24];
        snprintf(buf, sizeof(buf), "Time %02lu:%02lu", minutes, seconds);

        lv_label_set_text(ui_LabelTime, buf);
    }
    else{
        lv_timer_pause(my_timer);

        char result[64];
        snprintf(result, sizeof(result), "score %d/%d", correct_counter, correct_counter+incorrect_counter);
        save_score(timer_ind,launch_ind,correct_counter,correct_counter+incorrect_counter);
        lv_label_set_text(ui_Label4, result);

        seconds_counter=base_time;
        uint32_t minutes = seconds_counter / 60;
        uint32_t seconds = seconds_counter % 60;

        lv_label_set_text(ui_LabelPause,"Continue");
		lv_obj_clear_state(ui_Dropdown1, LV_STATE_DISABLED);  
		lv_obj_clear_flag(ui_ButtonReset, LV_OBJ_FLAG_HIDDEN);
		isPaused=true;

        char buf[24];
        snprintf(buf, sizeof(buf), "Time %02lu:%02lu", minutes, seconds);

        lv_label_set_text(ui_LabelTime, buf);

        correct_counter=0;

        snprintf(buf, sizeof(buf), "Correct %u", correct_counter);
        lv_label_set_text(ui_LabelCorrect, buf);

        incorrect_counter=0;

        snprintf(buf, sizeof(buf), "Incorrect %u", incorrect_counter);
        lv_label_set_text(ui_LabelIncorrect, buf);

        lv_obj_add_flag(ui_ButtonReset, LV_OBJ_FLAG_HIDDEN);
        lv_label_set_text(ui_LabelPause,"Start");
        ble_send_message("pause");
        isReset=true;
        lv_obj_clear_flag(ui_BasePanel, LV_OBJ_FLAG_HIDDEN);

        const char* last_score_str = get_score_string(timer_ind, launch_ind, false);
        const char* best_score_str = get_score_string(timer_ind, launch_ind, true);

        ESP_LOGI("SCORE", "Last score string: '%s'", last_score_str);
        ESP_LOGI("SCORE", "Best score string: '%s'", best_score_str);

        char result1[64];
        snprintf(result1, sizeof(result1), "Last: %s", last_score_str);
        lv_label_set_text(ui_LabelLast, result1);

        char result2[64];
        snprintf(result2, sizeof(result2), "Best: %s", best_score_str);
        lv_label_set_text(ui_LabelBest, result2);
    }
}

void create_timer_ui(void)
{
    my_timer = lv_timer_create(timer_update_cb, 1000, NULL);
}

void i2c_master_init() {
    i2c_config_t config = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_MASTER_SDA_IO,
        .scl_io_num = I2C_MASTER_SCL_IO,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_MASTER_FREQ_HZ
    };
    i2c_param_config(I2C_MASTER_PORT, &config);
    i2c_driver_install(I2C_MASTER_PORT, config.mode, 0, 0, 0);
}

esp_err_t i2c_write_register(uint8_t reg_addr, uint8_t data) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (TCA9534_ADDR << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd, reg_addr, true);
    i2c_master_write_byte(cmd, data, true);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(I2C_MASTER_PORT, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}

esp_err_t i2c_read_register(uint8_t reg_addr, uint8_t *data) {
    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (TCA9534_ADDR << 1) | I2C_MASTER_WRITE, true);
    i2c_master_write_byte(cmd, reg_addr, true);
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (TCA9534_ADDR << 1) | I2C_MASTER_READ, true);
    i2c_master_read_byte(cmd, data, I2C_MASTER_NACK);
    i2c_master_stop(cmd);
    esp_err_t ret = i2c_master_cmd_begin(I2C_MASTER_PORT, cmd, 1000 / portTICK_PERIOD_MS);
    i2c_cmd_link_delete(cmd);
    return ret;
}



void app_main()
{
    i2c_master_init();
    vTaskDelay(pdMS_TO_TICKS(50)); 
    
    uint8_t config_val = 0xFF; 
    i2c_read_register(0x03, &config_val);
    config_val &= ~(1 << 1);
    config_val &= ~(1 << 2);
    config_val &= ~(1 << 3);
    config_val &= ~(1 << 4);
    i2c_write_register(0x03, config_val);
    
    uint8_t output_val = 0x00;
    i2c_read_register(0x01, &output_val);
    output_val |= (1 << 1);

    gpio_set_direction(GPIO_NUM_1, GPIO_MODE_OUTPUT);
    gpio_set_level(GPIO_NUM_1, 0);

    output_val &= ~(1 << 2);
    vTaskDelay(pdMS_TO_TICKS(20));
    output_val |= (1 << 2);

    vTaskDelay(pdMS_TO_TICKS(100));
    gpio_set_direction(GPIO_NUM_1, GPIO_MODE_INPUT);

    i2c_write_register(0x01, output_val);

    gpio_reset_pin(19);
    gpio_set_direction(19, GPIO_MODE_OUTPUT);

    waveshare_esp32_s3_rgb_lcd_init();

    create_timer_ui();
    
    ESP_LOGI(TAG, "Display LVGL demos");
    if (lvgl_port_lock(-1)) {
        ui_init();
        lvgl_port_unlock();
    }
    lv_timer_pause(my_timer);
    ble_client_init();

    esp_err_t ret = nvs_flash_init();

    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_LOGW(TAG, "NVS flash corrupted or version changed, erasing...");
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }

    ESP_ERROR_CHECK(ret);
    ESP_LOGI(TAG, "NVS initialized successfully");

    launch_ind=load_int("launch",1);
    timer_ind=load_int("timer",1);

    if(timer_ind!=1){
        is_timer=true;
    }

    switch (timer_ind) {
        case 1:
            base_time=0;
            is_timer=false;
            break;
        case 2:
            base_time=180;
            is_timer=true;
            break;
        case 3:
            base_time=300;
            is_timer=true;
            break;
        case 4:
            base_time=600;
            is_timer=true;
            break;
        case 5:
            base_time=10;
            is_timer=true;
            break;
        default:
            base_time=0;
            is_timer=true;
            break;
	}

    seconds_counter=base_time;
    uint32_t minutes = seconds_counter / 60;
    uint32_t seconds = seconds_counter % 60;

    char buf[24];
    snprintf(buf, sizeof(buf), "Time %02lu:%02lu", minutes, seconds);
	lv_label_set_text(ui_LabelTime, buf);
    
    lv_dropdown_set_selected(ui_Dropdown1,launch_ind-1);
    lv_dropdown_set_selected(ui_Dropdown2,timer_ind-1);

    const char* last_score_str = get_score_string(timer_ind, launch_ind, false);
    const char* best_score_str = get_score_string(timer_ind, launch_ind, true);

    char result[64];
    snprintf(result, sizeof(result), "Last: %s", last_score_str);
    lv_label_set_text(ui_LabelLast, result);

    char result2[64];
    snprintf(result2, sizeof(result2), "Best: %s", best_score_str);
    lv_label_set_text(ui_LabelBest, result2);
}
