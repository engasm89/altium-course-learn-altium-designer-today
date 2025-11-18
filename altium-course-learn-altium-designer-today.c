/*
 * Course: Altium Course Learn Altium Designer Today
 * Platform: Embedded Systems
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Altium Course Learn Altium Designer Today" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Embedded Systems)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/altium-course-learn-altium-designer-today/
 * Repository: https://github.com/engasm89/altium-course-learn-altium-designer-today
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

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

void app_main(void) { // Program entry point
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  xTaskCreate(blink_task, "blink", 2048, NULL, 5, NULL); // Start blink task
  xTaskCreate(log_task, "log", 2048, NULL, 5, NULL); // Start log task
} // End of main function

