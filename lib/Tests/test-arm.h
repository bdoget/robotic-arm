#ifndef TEST_ARM_H
#define TEST_ARM_H

#include "Arduino.h"
#include "Arm.h"
Arm arm;

void test_setup()
{
  Serial.begin(9600);
  Serial.println("Done with setup");
  arm.init(A3,A2,A1,A4); // place pins in order of this: shoulder,elbow, wrist, claw 
  delay(1000);
}

void test_loop() {

  // for (int i=0; i < 4; i++) {}
  arm.gotoRest();
  delay(3000);
  arm.goDown();
  // arm.moveServo(1,30);
  delay(3000);
  // arm.moveServo(1,120);
  // delay(3000);


  // arm.moveServo(0 ,0);
  // delay(1000);
  // arm.moveServo(0,90);
  // Serial.println("looped NEW");
  // delay(1000);
}
#endif
