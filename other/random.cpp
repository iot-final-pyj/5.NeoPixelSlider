#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#define ledPin 15 
#define ledNum 8

Adafruit_NeoPixel pixels(ledNum, ledPin, NEO_GRB + NEO_KHZ800);

void setup() {
    Serial.begin(115200);
    pixels.begin();
    delay (2000);
    Serial.println("starting");
}

void loop () {
    int R, G, B;
    pixels.clear();
    for (int i = 0; i < ledNum; i++) {
        R = random(0, 255);
        G = random(0, 255);
        B = random(0, 255);
        pixels.setPixelColor(i, pixels.Color(R, G, B)) ;
    }
    pixels.show();
    delay(500);
}