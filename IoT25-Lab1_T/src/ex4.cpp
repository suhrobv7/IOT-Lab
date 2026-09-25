#include <Arduino.h>

// Light sensor -> LED band
constexpr uint8_t RED_LED_PIN = 26;
constexpr uint8_t GREEN_LED_PIN = 27;
constexpr uint8_t BLUE_LED_PIN = 14;
constexpr uint8_t YELLOW_LED_PIN = 12;
constexpr uint8_t LIGHT_PIN = 33;

int lastBandIndex = -1;

const char* getBandName(int raw) {
    if (raw <= 1023) {
        return "BLUE";
    }
    if (raw <= 2047) {
        return "GREEN";
    }
    if (raw <= 3071) {
        return "YELLOW";
    }
    return "RED";
}

void setBandLED(int raw) {
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);

    if (raw <= 1023) {
        digitalWrite(BLUE_LED_PIN, HIGH);
    } else if (raw <= 2047) {
        digitalWrite(GREEN_LED_PIN, HIGH);
    } else if (raw <= 3071) {
        digitalWrite(YELLOW_LED_PIN, HIGH);
    } else {
        digitalWrite(RED_LED_PIN, HIGH);
    }
}

void setup() {
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(LIGHT_PIN, INPUT);

    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);

    Serial.begin(115200);
    delay(100);
    Serial.println("Light band monitor started");
}

void loop() {
    int raw = analogRead(LIGHT_PIN);
    const char* band = getBandName(raw);

    // Only report when the detected light band changes.
    int bandIndex = 0;
    if (strcmp(band, "BLUE") == 0) bandIndex = 1;
    else if (strcmp(band, "GREEN") == 0) bandIndex = 2;
    else if (strcmp(band, "YELLOW") == 0) bandIndex = 3;
    else bandIndex = 4;

    setBandLED(raw);

    if (bandIndex != lastBandIndex) {
        Serial.printf("band=%s\n", band);
        lastBandIndex = bandIndex;
    }

    delay(100);
}

