#include <Arduino.h>

// Minimal serial control
constexpr uint8_t BLUE_LED_PIN = 14;

void setup() {
    pinMode(BLUE_LED_PIN, OUTPUT);
    digitalWrite(BLUE_LED_PIN, LOW);
    Serial.begin(115200);
    delay(100);
    Serial.println("Serial control ready. Send B or b");
}

void loop() {
    if (Serial.available() > 0) {
        char command = Serial.read();

        if (command == 'B') {
            digitalWrite(BLUE_LED_PIN, HIGH);
            Serial.println("BLUE=1");
        } else if (command == 'b') {
            digitalWrite(BLUE_LED_PIN, LOW);
            Serial.println("BLUE=0");
        }
    }
}

