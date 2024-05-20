#ifndef TEST_STEPPER_H
#define TEST_STEPPER_H

#include "Arduino.h"
#include "Arm.h"
#include <Stepper.h>
Arm arm;


// change this to the number of steps on your motor
#define STEPS 512
Stepper motor(STEPS, 3, 6, 4, 5);

void test_setup() {
  Serial.begin(9600);
  Serial.println("Done with setup");
  motor.setSpeed(20);
  arm.init(A3,A4,A1,A2); // place pins in order of this: shoulder,elbow, wrist, claw 
  delay(1000);
}

void test_loop() {
    arm.gotoRest();
    motor.step(1);
    Serial.println("STEP");
    delay(1000);
}

#endif