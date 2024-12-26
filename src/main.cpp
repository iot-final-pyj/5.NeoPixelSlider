#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define ledPin 15 
#define ledNum 8

Adafruit_NeoPixel pixels(ledNum, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
    pixels.begin();
}

void waterDrop(int i, int R, int G, int B, int maxTail = 4, int tail = 1) {
    int divider = exp(tail);
    pixels.setPixelColor(i, pixels.Color(R/divider, G/divider, B/divider));
    if (i < ledNum && tail < maxTail) {
        waterDrop(++i, R, G, B, maxTail, ++tail);
    }
}

void loop () {
    int R = random(0, 255);
    int G = random(0, 255);
    int B = random(0, 255);
    for (int i = 7; i >= 0 ; i--) {
        pixels.clear();
        waterDrop(i, R, G, B);
        pixels.show();
        delay(100);
    }
}