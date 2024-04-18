#include "Arduino.h"
#include "Arm.h"

Arm arm;

// Servo servo1;

void setup()
{
  Serial.begin(9600);
  Serial.println("Done with setup");
  arm.init(A0,A1,A2,A3); // place pins in order of this: elbow, wrist, claw 
  delay(1000);
}

void loop() {
  //arm.moveServo(0,0);
  //delay(1000);
  //arm.moveServo(0,85);
  //delay(1000);

  for (int i=0; i < 1; i++) {

    arm.moveServo(0,0);
    delay(1000);
    arm.moveServo(0,75);
    delay(1000);

    //arm.moveServo(1,90);
    //delay(1000);

    //arm.moveServo(2,90);
    //delay(1000);
    //arm.moveServo(3,0);
    //delay(1000);


    
  }
  Serial.println("looped Done");
  delay(1000);
}
