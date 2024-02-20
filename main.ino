// #include "Arduino.h"

void setup() {
    Serial.begin(9600);
}

void loop() {
    while(true) {
        Serial.println("hello");
    }
}