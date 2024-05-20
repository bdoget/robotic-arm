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

void test_setup() {
  speed = 255;
  // wheel pins: (enablePin, inputPin1, inputPin2)
  topRight.init(8, 23, 22); //
  topLeft.init(11, 25, 24); //
  bottomLeft.init(9, 28, 29); // 
  bottomRight.init(10, 26, 27); //
   
  test.init(topRight, topLeft, bottomLeft, bottomRight, speed);
  Serial.begin(9600);
  Serial.println("Hi buddies");

  test.moveForward();
  delay(2000);
}

void test_loop() {
  // test.moveForward();
  // test.moveLeft(); 
  // delay(2000);

  // test.stop();
  // delay(2000);

  // // test.moveBackward();
  // test.moveRight();
  // delay(2000);

  // test.stop();
  delay(1000);
  
  Serial.println("FEPP)");
}

void test_basic_movements(){
  test.moveForward();
  test.stop();
  delay(2000);

  test.moveBackward();
  test.stop();
  delay(2000);
}


void test_turning(){
  for (int i = 0; i < 3; i++){
    test.turnRight();
    delay(1000);
    test.moveForward();
    delay(2000);
  }

  for (int i = 0; i < 3; i++){
    test.turnLeft();
    delay(1000);
    test.moveForward();
    delay(2000);
  }

}


void test_turning_reverse(){
  for (int i = 0; i < 3; i++){
    test.turnRight();
    delay(1000);
    test.moveBackward();
    delay(2000);
  }

  for (int i = 0; i < 3; i++){
    test.turnLeft();
    delay(1000);
    test.moveBackward();
    delay(2000);
  }
}


void test_turn_in_place(){
  for (int i = 0; i < 4; i++){
    for (int j = 0; j <= 3; j++){
      test.turnLeft();
      delay(1000);
    }
    for (int k = 0; k <= 3; k++){
      test.turnRight();
      delay(1000);
    }
  }
}



#endif