#ifndef TEST_ARM_H
#define TEST_ARM_H

#include "Arduino.h"
#include "Arm.h"
Arm arm;

void test_setup() {
  Serial.begin(9600);
  Serial.println("Done with setup");
  arm.init(A3,A4,A1,A2); // place pins in order of this: shoulder,elbow, wrist, claw 
  arm.setSpeed(0.05);
  delay(1000);
}

void test_loop() {
    for (int i=0; i<20; i++) {
        arm.step(1);
        delay(1000);
    }
    for (int i=0; i<20; i++) {
        arm.step(-1);
        delay(1000);
    }

//   arm.goDown();
//   delay(2000);
//   arm.gotoRest();
//   delay(2000);

}


#endif