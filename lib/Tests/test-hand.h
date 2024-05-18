#ifndef TEST_HAND_H
#define TEST_HAND_H

#include <Arduino.h>

#define fing0 A0
#define fing1 A1
#define fing2 A2
#define fing3 A3

int F0 = 0;
int F1 = 0;
int F2 = 0;
int F3 = 0;


void test_setup() {
    Serial.begin(9600);
    Serial.println("Hi buddies");
}

void test_loop() {
    Serial.println("FEPP)");
    F0 = analogRead(fing0);
    F1 = analogRead(fing1);
    F2 = analogRead(fing2);
    F3 = analogRead(fing3);

    Serial.print(F0);
    Serial.print(" ");
    Serial.print(F1);
    Serial.print(" ");
    Serial.print(F2);
    Serial.print(" ");
    Serial.print(F3);
    Serial.print(" ");
    Serial.println("");

    delay(300);

  

}

#endif