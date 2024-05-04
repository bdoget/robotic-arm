#include <Arduino.h>
#include "Chassis.h"

int speed;
Wheel topRight;
Wheel topLeft;
Wheel bottomLeft;
Wheel bottomRight;
Chassis test;

void testRun(int enA, int pin1, int pin2){
  pinMode(enA, OUTPUT);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  /*
  write HI, LO to pin1 and 2
  0-255 on enable
  wrtite Lo, Hi to p12
  255-0 on enable
  */
 while (true){
  Serial.println("FEP FEP FEP FEP FEP FEP");
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  for (int i = 90; i <= 255; i++){
    analogWrite(enA, i);
    delay(10);
  }
  delay(500);
  for (int i = 255; i >=0; i--){
    analogWrite(enA, i);
    delay(10);
  }
  delay(500);
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  for (int i = -255; i <=0; i++){
    analogWrite(enA, abs(i));
    delay(10);
  }
  delay(500);
  for (int i = -90; i >= -255; i--){
    analogWrite(enA, abs(i));
    delay(10);
  }
  analogWrite(enA, 0);
  delay(500);

 }
}
void setup()
{
  speed = 150;
  topRight.init(3, 29, 28);
  topLeft.init(2, 27, 26);
  bottomLeft.init(4, 22, 23);
  bottomRight.init(5, 24, 25);
  test.init(topRight, topLeft, bottomLeft, bottomRight, speed);
  Serial.begin(9600);
}

void loop() {
  test.moveForward();
  test.stop();
  test.turnLeft();
  test.stop();
  test.turnRight();
  test.moveLeft();
  delay(1000);
}


/*
#include "Arduino.h"
#include "Arm.h"
Arm arm;

void setup()
{
  Serial.begin(9600);
  Serial.println("Done with setup");
  arm.init(A0,A1,A2,A3); // place pins in order of this: elbow, wrist, claw 
  delay(1000);
}

void loop() {

  for (int i=0; i < 1; i++) {

    arm.moveServo(0,0);
    delay(1000);
    arm.moveServo(0,75);
    delay(1000);
    
  }
  Serial.println("looped Done");
  delay(1000);
}
*/