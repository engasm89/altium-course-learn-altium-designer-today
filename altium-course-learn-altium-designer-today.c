// Minimal ESP-IDF app showing task structure akin to Altium design workflows
#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "driver/gpio.h" // GPIO
#include "esp_log.h" // Logging

#define LED GPIO_NUM_2 // LED
static const char *TAG = "ALTIUM"; // Log tag

static void blink_task(void *arg) { // Blink task
  while (true) { // Continuous loop
    gpio_set_level(LED, 1); // LED ON
    vTaskDelay(pdMS_TO_TICKS(200)); // 200ms
    gpio_set_level(LED, 0); // LED OFF
    vTaskDelay(pdMS_TO_TICKS(200)); // 200ms
  } // End loop
} // End task

static void log_task(void *arg) { // Logging task
  int step = 0; // Workflow step counter
  while (true) { // Continuous loop
    ESP_LOGI(TAG, "Workflow step %d: schematic->layout->DRC->fabrication", step++); // Log
    vTaskDelay(pdMS_TO_TICKS(1000)); // 1s
  } // End loop
} // End task

void app_main(void) { // Entry
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  xTaskCreate(blink_task, "blink", 2048, NULL, 5, NULL); // Start blink task
  xTaskCreate(log_task, "log", 2048, NULL, 5, NULL); // Start log task
} // End app_main

