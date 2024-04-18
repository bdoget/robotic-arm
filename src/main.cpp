#include "Arduino.h"
#include "Servo.h"

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  servo1.attach(A5); // claw
  servo2.attach(A1); // shoulder
  servo3.attach(A3); // wrist
  servo4.attach(A2); // elbow
  servo5.attach(12);

  Serial.begin(9600);
  Serial.print("Done Setup");
}

void writeAll(int num){
  servo1.write(num);
  servo2.write(num);
  servo3.write(num);
  servo4.write(num);
  servo5.write(num);
  Serial.print("Go to num: ");
  Serial.println(num);
  delay(2000);
}

// void test(int num) {
//   switch (num) {

//   }
// }

void loop() {
  // writeAll(45);
  // writeAll(135);
  writeAll(0);
  writeAll(45);
  writeAll(90);
}
