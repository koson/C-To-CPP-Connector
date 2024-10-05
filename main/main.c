#include <stdio.h>
#include "led_c_connector.h"
#include "sevensegment_c_connector.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


uint8_t counter = 0;
TaskHandle_t xSevenSegmentHandle = NULL;
TaskHandle_t xCounterHandle = NULL;
void vTaskCounter(void *Parameters)
{
    while (1)
    {
        if(counter++ > 99)
            counter = 0;
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

void vTaskScanSevenSegment(void *Parameters)
{
    while (1)
    {
        s1_displayNumber(counter / 10);
        s1_displayOn();
        vTaskDelay(10 / portTICK_PERIOD_MS);
        s1_displayOff();

        s2_displayNumber(counter % 10);
        s2_displayOn();
        vTaskDelay(10 / portTICK_PERIOD_MS);
        s2_displayOff();
    }
}

void app_main(void)
{
    xTaskCreate(vTaskScanSevenSegment, "Seven Seg", 
        1024, NULL, 10, &xSevenSegmentHandle);
    xTaskCreate(vTaskCounter, "Counter", 
        1024, NULL, 5, &xCounterHandle);
}