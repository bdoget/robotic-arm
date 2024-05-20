#ifndef TEST_ARM_H
#define TEST_ARM_H

#include "Arduino.h"
#include "Arm.h"
Arm arm;

void test_setup() {
  Serial.begin(9600);
  Serial.println("Done with setup");
  arm.init(A3,A2,A1,A4); // place pins in order of this: shoulder,elbow, wrist, claw 
  delay(1000);
}

void test_loop() {
  arm.goDown();
  delay(2000);
  arm.gotoRest();
  delay(2000);

  // for (int i=0; i < 4; i++) {}
  // arm.gotoRest();
  // delay(3000);
  // arm.goDown();
  // // arm.moveServo(1,30);
  // delay(3000);
  // arm.moveServo(1,120);
  // delay(3000);


  // arm.moveServo(0 ,0);
  // delay(1000);
  // arm.moveServo(0,90);
  // Serial.println("looped NEW");
  // delay(1000);
}


void test_pick_up() {
 /// FIRST GO TO STARTING POINT
  arm.moveServo(0,0);
  delay(1000);
  arm.moveServo(1,90);
  delay(1000);
  arm.moveServo(2,90);
  delay(1000);
  arm.moveServo(3,0);
  delay(1000);

  Serial.println("LETS PICK UP!");


  // Move shoulder down 
  Serial.println("First move shoulder");
  arm.moveServo(0,80);
  delay(1000);

  // Move elbow down
  Serial.println("Then move elbow");
  arm.moveServo(0,20);
  delay(1000);

  // Move wrist down
  Serial.println("Then move wrist");
  arm.moveServo(0,20);
  delay(1000);


 // close claw
  Serial.println("Then close claw");
  arm.moveServo(0,90);
  delay(1000);

  Serial.println("looped Done");
  delay(1000);

}

void test_minimum_stay() {
 /// EVERYTHING SHOULD STAY AT MINIMUM

  for (int i=0; i < 4; i++) {

    arm.moveServo(i,0); // goes to minimum
    delay(1000);
    if (i == 0){
      arm.moveServo(i, 140); // SHOULD STAY AT MINIMUM
    }
    else if (i == 1 || i == 2){
      arm.moveServo(i, 200); // SHOULD STAY AT MINIMUM
    }
    else if (i == 3){
      arm.moveServo(i, 91); // SHOULD STAY AT MINIMUM
    }
    arm.moveServo(0,75);
    delay(1000);

  }
  Serial.println("looped Done");
  delay(1000);
}


void test_raise_hand(){
    arm.moveServo(0, 0);
    delay(1000);
    arm.moveServo(1, 90);
    delay(1000);
    arm.moveServo(2, 90);
    delay(1000);
}



#endif