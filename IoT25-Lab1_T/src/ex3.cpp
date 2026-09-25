#include <Arduino.h>

// Read the light sensor every 500 ms.
constexpr uint8_t LIGHT_PIN = 33;

unsigned long lastReadMs = 0;

void setup() {
    pinMode(LIGHT_PIN, INPUT);
    Serial.begin(115200);
    delay(100);
    Serial.println("Light sensor started");
}

void loop() {
    unsigned long now = millis();

    if (now - lastReadMs >= 500UL) {
        lastReadMs = now;
        int raw = analogRead(LIGHT_PIN);
        Serial.printf("raw=%d\n", raw);
    }
}

