#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "driver/gpio.h"
void print_StudentID_per_sec(void);
void listen_button_pressed(void);
void init_button(void);

void app_main(void)
{
    init_button();
    xTaskCreate(print_StudentID_per_sec,"Task_Print_ID", 2048, NULL, 2, NULL);
    xTaskCreate(listen_button_pressed,"Task_Button", 2048, NULL, 3, NULL);
    
}

void print_StudentID_per_sec(void){
    while(1){
        printf("1910637 \n");
        vTaskDelay(1000/portTICK_RATE_MS);
        
    }
}

void listen_button_pressed(void){
   while(1){
    if(!gpio_get_level(GPIO_NUM_17)){
        printf("ESP32 \n");
    }
    vTaskDelay(100/portTICK_RATE_MS);
   }

}
void init_button(void){
    gpio_pad_select_gpio(GPIO_NUM_17);
    gpio_set_direction(GPIO_NUM_17, GPIO_MODE_INPUT);
}

