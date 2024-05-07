#include <stdio.h>
#include <esp_task_wdt.h>

#include "osr_ble.h"

void setup()
{
    osr_ble_init();
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
