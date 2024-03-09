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
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  for (int i = 90; i < 255; i++){
    analogWrite(enA, i);
    delay(100);
  }
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  for (int i = 255; i >90; i--){
    analogWrite(enA, i);
    delay(100);
  }
  delay(500);
 }
}
void setup()
{
  speed = 150;
  topRight.init(4,2,3);
  topLeft.init(7,5,6);
  bottomLeft.init(10,8,9);
  bottomRight.init(13,11,12);
  test.init(topRight, topLeft, bottomLeft, bottomRight, speed);
  Serial.begin(9600);
}

void loop() {
  Serial.println("FEP FEP FEP FEP FEP FEP");
  testRun(13, 11, 12);
  test.moveForward(speed);
  test.stop();
  test.turnLeft(speed);
  test.stop();
  test.turnRight(speed);
  test.moveLeft(speed);
  delay(1000);
}
