#include <Arduino.h>

// Snapshot on button press
constexpr uint8_t BUTTON_PIN = 25;
constexpr uint8_t LIGHT_PIN = 33;
constexpr uint8_t YELLOW_LED_PIN = 12;

bool lastButtonState = LOW;
bool snapshotReady = true;

void setup() {
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LIGHT_PIN, INPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    digitalWrite(YELLOW_LED_PIN, LOW);
    Serial.begin(115200);
    delay(100);
    Serial.println("Press button to take snapshot");
}

void loop() {
    bool buttonState = digitalRead(BUTTON_PIN);

    if (buttonState == HIGH && lastButtonState == LOW && snapshotReady) {
        int raw = analogRead(LIGHT_PIN);
        Serial.printf("snapshot=%d\n", raw);

        digitalWrite(YELLOW_LED_PIN, HIGH);
        delay(100);
        digitalWrite(YELLOW_LED_PIN, LOW);

        snapshotReady = false;
    }

    if (buttonState == LOW) {
        snapshotReady = true;
    }

    lastButtonState = buttonState;
}

