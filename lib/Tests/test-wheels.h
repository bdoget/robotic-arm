#ifndef TEST_WHEELS_H
#define TEST_WHEELS_H

#include <Arduino.h>
#include "Chassis.h"

int speed;
Wheel topRight;
Wheel topLeft;
Wheel bottomLeft;
Wheel bottomRight;
Chassis test;

void test_setup() {
  speed = 100;
  topRight.init(3, 29, 28);
  topLeft.init(2, 26, 27);
  bottomLeft.init(4, 22, 23); // 
  bottomRight.init(5, 25, 24);
  test.init(topRight, topLeft, bottomLeft, bottomRight, speed);
  Serial.begin(9600);
  Serial.println("Hi buddies");

  test.moveForward();
  delay(2000);
}

void test_loop() {
  // test.moveForward();
  // test.moveLeft(); 
  // delay(2000);

  // test.stop();
  // delay(2000);

  // // test.moveBackward();
  // test.moveRight();
  // delay(2000);

  // test.stop();
  delay(1000);
  
  Serial.println("FEPP)");

}

#endif