#ifndef TEST_ARM_H
#define TEST_ARM_H

#include "Arduino.h"
#include "Arm.h"
Arm arm;

void test_setup()
{
  Serial.begin(9600);
  Serial.println("Done with setup");
  arm.init(A0,A1,A2,A3); // place pins in order of this: elbow, wrist, claw 
  delay(1000);
}

void test_loop() {

  for (int i=0; i < 1; i++) {

    arm.moveServo(0,0);
    delay(1000);
    arm.moveServo(0,75);
    delay(1000);
    
  }
  Serial.println("looped Done");
  delay(1000);
}
#endif
