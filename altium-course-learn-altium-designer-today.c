#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "driver/gpio.h" // GPIO

#define LED GPIO_NUM_2 // LED

void app_main(void) { // Entry
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  while (true) { gpio_set_level(LED, 1); vTaskDelay(pdMS_TO_TICKS(300)); gpio_set_level(LED, 0); vTaskDelay(pdMS_TO_TICKS(300)); } // Blink
} // End

