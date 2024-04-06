#include "Arduino.h"
#include "Arm.h"

Arm arm;

// Servo servo1;

void setup()
{
  Serial.begin(9600);
  Serial.println("Done with setup");


  arm.init(A0,2,3);
  arm.moveServo1(0);

  // servo1.attach(A0);
  // servo1.write(0);

  delay(1000);
}

void loop() {
  for (int i=0; i < 1; i++) {
    arm.moveServo1(90);
    // servo1.write(0);
    delay(1000);
    arm.moveServo1(180);

    // servo1.write(90);
    delay(1000);
    arm.moveServo1(0);

    // servo1.write(180);

    delay(1000);
  }
  Serial.println("looped Done");
  delay(1000);
}
