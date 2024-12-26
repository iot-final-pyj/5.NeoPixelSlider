#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define ledPin 15
#define ledNum 8

Adafruit_NeoPixel pixels(ledNum, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin();
}

void loop() {
    pixels.clear();
    for (int i = 0; i < ledNum; i++) {
        pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    }
    pixels.show();
    delay(500);
    pixels.clear();
    for (int i = 0; i < ledNum; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 255, 0));
    }
    pixels.show();
    delay(500);
    pixels.clear();
    for (int i = 0; i < ledNum; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 255));
    }
    pixels.show();
    delay(500);
}

