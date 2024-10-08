#include <esp_chip_info.h>
#include <esp_flash.h>
#include <esp_log.h>
#include <esp_task_wdt.h>
#include <stdio.h>
#include "osr_ble.h"
#include "sdkconfig.h"

#define TAG "app"

void esp32_info() {
  esp_chip_info_t chip_info;
  uint32_t flash_size;
  esp_chip_info(&chip_info);
  printf("This is %s chip with %d CPU core(s), %s%s%s%s, ", CONFIG_IDF_TARGET,
         chip_info.cores,
         (chip_info.features & CHIP_FEATURE_WIFI_BGN) ? "WiFi/" : "",
         (chip_info.features & CHIP_FEATURE_BT) ? "BT" : "",
         (chip_info.features & CHIP_FEATURE_BLE) ? "BLE" : "",
         (chip_info.features & CHIP_FEATURE_IEEE802154)
             ? ", 802.15.4 (Zigbee/Thread)"
             : "");

  unsigned major_rev = chip_info.revision / 100;
  unsigned minor_rev = chip_info.revision % 100;
  printf("silicon revision v%d.%d, ", major_rev, minor_rev);
  if (esp_flash_get_size(NULL, &flash_size) != ESP_OK) {
    printf("Get flash size failed");
    return;
  }

  printf(
      "%" PRIu32 "MB %s flash\n", flash_size / (uint32_t)(1024 * 1024),
      (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");

  printf("Minimum free heap size: %" PRIu32 " bytes\n",
         esp_get_minimum_free_heap_size());
}

void setup() {
  osr_ble_init();
  ESP_LOGI(TAG, "Setup done!");
}

void loop(void* args) {
  while (1) {
    vTaskDelay(pdMS_TO_TICKS(1000));
    ESP_LOGI(TAG, "Hello World!");
  }
}

void app_main() {
  setup();
  xTaskCreatePinnedToCore(loop, "loop", 4096, NULL, 5, NULL, 1);
}
