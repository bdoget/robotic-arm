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
  speed = 25;
  topRight.init(3, 29, 28);
  topLeft.init(2, 26, 27);
  bottomLeft.init(4, 22, 23); // 
  bottomRight.init(5, 25, 24);
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

  test.moveLeft();
  test.stop();
  delay(2000);

  test.moveRight();
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