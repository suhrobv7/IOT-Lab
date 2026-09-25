#include <Arduino.h>

// Blink RED LED
// The red LED on D26 toggles on and off every 500 ms.
constexpr uint8_t RED_LED_PIN = 26;

bool redState = false;
unsigned long lastToggleMs = 0;

void setup() {
    pinMode(RED_LED_PIN, OUTPUT);
    digitalWrite(RED_LED_PIN, LOW);
    Serial.begin(115200);
    delay(100);
    Serial.println("System ready");
}

void loop() {
    unsigned long now = millis();

    if (now - lastToggleMs >= 500UL) {
        lastToggleMs = now;
        redState = !redState;
        digitalWrite(RED_LED_PIN, redState ? HIGH : LOW);

        if (redState) {
            Serial.println("RED ON");
        } else {
            Serial.println("RED OFF");
        }
    }
}

