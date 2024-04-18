#include "Arduino.h"
#include "Servo.h"

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

void setup() {
  servo1.attach(A5); // claw
  servo2.attach(A1); // shoulder
  servo3.attach(A3); // wrist
  servo4.attach(A2); // elbow

  Serial.begin(9600);
  Serial.print("Done Setup");
}

void writeAll(int num){
  servo1.write(num);
  servo2.write(num);
  servo3.write(num);
  servo4.write(num);
  Serial.print("Go to num: ");
  Serial.println(num);
  delay(2000);
}

void gotoRest() {
  servo1.write(0);
  servo2.write(0);
  servo3.write(90);
  servo4.write(0);
}

void loop() {
  // writeAll(45);
  // writeAll(135);
  writeAll(0);
  writeAll(45);
  writeAll(90);
}
