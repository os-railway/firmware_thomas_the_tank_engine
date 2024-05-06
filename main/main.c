#include <stdio.h>
#include <esp_task_wdt.h>
#include <nvs.h>
#include <nvs_flash.h>

void nvs_init()
{
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);
}

void setup()
{
    nvs_init();
}

void loop()
{
    ESP_ERROR_CHECK(esp_task_wdt_reset());
}

void app_main()
{
    setup();
    while (1)
    {
        loop();
    }
}
