# 📘 Practice 4 – Part B: LED Control with FreeRTOS

## 📌 Overview

This part of the practice extends multitasking on the ESP32 using FreeRTOS by controlling a physical LED. The goal is to observe how multiple tasks interact when accessing the same hardware resource.

---

## 🎯 Objectives

* Implement multitasking with FreeRTOS
* Control a LED using multiple tasks
* Understand concurrent access to shared resources
* Identify synchronization issues

---

## ⚙️ Technologies Used

* ESP32 Dev Module
* PlatformIO (VS Code)
* Arduino Framework
* FreeRTOS
* LED + (recommended) resistor

---

## 🧠 Concept

In this part, two independent tasks attempt to control the same LED:

* One task turns the LED ON
* Another task turns the LED OFF

Since both tasks run concurrently and are not synchronized, they compete for control of the LED, leading to unpredictable behavior.

---

## 🔌 Hardware Setup

```
GPIO 2 ── LED ── GND
```

> ⚠️ Note: A resistor (220Ω–330Ω) is recommended to protect the LED and ESP32.

---

## 💻 Code

```cpp
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
  // Not used
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
```

---

## ▶️ Expected Behavior

* The LED does not blink consistently
* It may flicker or behave unpredictably
* Serial output shows alternating "LED ON" and "LED OFF"

---

## 🔍 Explanation

Both tasks run simultaneously and try to control the same LED without coordination. Since there is no synchronization mechanism, the final LED state depends on which task executes last.

This creates a **race condition**, a common issue in multitasking systems.

---

## 📚 Conclusion

This part demonstrates how multitasking can lead to conflicts when shared resources are not properly managed, highlighting the importance of synchronization in real-time systems.

---

## 👤 Author

Miguel Massó
