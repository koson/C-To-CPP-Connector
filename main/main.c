#include <stdio.h>
#include "led_c_connector.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    while(1)
    {
        LED_ON();
        vTaskDelay(100/portTICK_PERIOD_MS);
        LED_OFF();
        vTaskDelay(100/portTICK_PERIOD_MS);
    }
}