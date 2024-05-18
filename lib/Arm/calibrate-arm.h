#ifndef CALIBRATE_ARM_H
#define CALIBRATE_ARM_H

#include <Arduino.h>
#include <Servo.h>

Servo test;

void test_setup() {
  test.attach(A0);
}

void test_loop() {
  // test.write(0);
  delay(1500);
  test.write(90);
  // delay(1500);
  // test.write(180);
  // delay(1500);

}

#endif