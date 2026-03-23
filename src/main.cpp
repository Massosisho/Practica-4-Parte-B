#include <Arduino.h>

#define LED 2

void taskON(void *parameter);
void taskOFF(void *parameter);

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

  xTaskCreate(taskON, "LED ON", 2048, NULL, 1, NULL);
  xTaskCreate(taskOFF, "LED OFF", 2048, NULL, 1, NULL);
}

void loop() {
  // vacío
}

void taskON(void *parameter) {
  for (;;) {
    digitalWrite(LED, HIGH);
    Serial.println("LED ON");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void taskOFF(void *parameter) {
  for (;;) {
    digitalWrite(LED, LOW);
    Serial.println("LED OFF");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}