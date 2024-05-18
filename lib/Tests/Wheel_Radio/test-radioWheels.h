#ifndef TEST_RADIO_WHEELS_H
#define TEST_RADIO_WHEELS_H

#include <Arduino.h>
#include "Chassis.h"

int speed;
Wheel topRight;
Wheel topLeft;
Wheel bottomLeft;
Wheel bottomRight;
Chassis chassis;

void test_setup() {
  speed = 255;
  topRight.init(3, 28, 29);
  topLeft.init(2, 27, 26);
  bottomLeft.init(4, 22, 23);
  bottomRight.init(5, 25, 24);

  chassis.init(topRight, topLeft, bottomLeft, bottomRight, speed);

  Serial.begin(9600);
  Serial.println("Hi buddies");
}

void test_loop() {
  // test.moveForward();
  chassis.moveLeft();
  delay(2000);

  chassis.stop();
  delay(2000);

  // chassis.moveBackward();
  chassis.moveRight();
  delay(2000);

  chassis.stop();
  delay(1000);
  
  Serial.println("FEPP)");

}

#endif