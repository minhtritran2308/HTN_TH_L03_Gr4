#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
void print_StudentID_per_sec(void);
void print_StudentID_per_sec_2(void);
void func_high_prio(void);
void app_main(void)
{
    xTaskCreate(print_StudentID_per_sec,"Task_Print_ID", 2048, NULL, 2, NULL);
    xTaskCreate(print_StudentID_per_sec_2,"Task_Print_ID_2", 2048, NULL, 2, NULL);
    xTaskCreate(func_high_prio,"Task_High_Prio", 2048, NULL, 3, NULL);
}

void print_StudentID_per_sec(void){
    while(1){
        printf("1910637 \n");
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}
void print_StudentID_per_sec_2(void){
    while(1){
        printf("271001 \n");
        vTaskDelay(1000/portTICK_RATE_MS);
    }
}

void func_high_prio(void){
    while(1){
        printf("High Prio \n");
        vTaskDelay(3000/portTICK_RATE_MS);
    }
}

