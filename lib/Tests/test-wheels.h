#ifndef TEST_WHEELS_H
#define TEST_WHEELS_H

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
void test_setup() {
  speed = 255;
  topRight.init(3, 28, 29);
  topLeft.init(2, 27, 26);
  bottomLeft.init(4, 22, 23); // 
  bottomRight.init(5, 25, 24);
  test.init(topRight, topLeft, bottomLeft, bottomRight, speed);
  Serial.begin(9600);
  Serial.println("Hi buddies");
}

void test_loop() {
  // test.moveForward();
  test.moveLeft();
  delay(2000);

  test.stop();
  delay(2000);

  // test.moveBackward();
  test.moveRight();
  delay(2000);

  test.stop();
  delay(1000);
  
  Serial.println("FEPP)");

}

#endif