#ifndef TEST_TEST_H
#define TEST_TEST_H

#include <Arduino.h>

void test_setup() {
    Serial.begin(9600);
    Serial.println("Hey");
}

void test_loop() {
    Serial.println("FEPFEPFEP");
}

#endif