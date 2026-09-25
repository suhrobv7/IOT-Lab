#include <Arduino.h>

// Button toggles GREEN LED
constexpr uint8_t GREEN_LED_PIN = 27;
constexpr uint8_t BUTTON_PIN = 25;

bool greenState = false;
bool lastButtonState = LOW;

void setup() {
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    digitalWrite(GREEN_LED_PIN, LOW);
    Serial.begin(115200);
    delay(100);
    Serial.println("Waiting for button press...");
}

void loop() {
    bool buttonState = digitalRead(BUTTON_PIN);

    // Only change state on a button press edge.
    if (buttonState == HIGH && lastButtonState == LOW) {
        greenState = !greenState;
        digitalWrite(GREEN_LED_PIN, greenState ? HIGH : LOW);
        Serial.println(greenState ? "GREEN=1" : "GREEN=0");
        delay(50); // Reduce repeated trigger noise from the button.
    }

    lastButtonState = buttonState;
}

