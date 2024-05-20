#ifndef FINAL_H
#define FINAL_H

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Transciever.h"
RF24 radio(53, 48); // CE, CSN 40,41
const byte address[6] = "00001";
Data_Package data; //Create a variable with the above structure
DataReader reader;

#include "Arm.h"
Arm arm;

#include "Chassis.h"
int speed;
Wheel topRight;
Wheel topLeft;
Wheel bottomLeft;
Wheel bottomRight;
Chassis test;

#include <Stepper.h>
#define STEPS 512
// Stepper motor(STEPS, 3, 6, 4, 5);

bool is_claw_closed = false;

void test_setup() {
    // motor.setSpeed(20);

    arm.init(A3,A1,A0,A2); // place pins in order of this: shoulder,elbow, wrist, claw 
    arm.setSpeed(0.05);
    arm.gotoRest();
    arm.moveServo(4,40);
    delay(500);

    speed = 150;
    // wheel pins: (enablePin, inputPin1, inputPin2)
    topRight.init(8, 23, 22); //
    topLeft.init(11, 25, 24); //
    bottomLeft.init(9, 28, 29); // 
    bottomRight.init(10, 26, 27); //
    test.init(topRight, topLeft, bottomLeft, bottomRight, speed);
    test.stop();

    Serial.begin( 9600);
    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_HIGH);
    radio.startListening();

    delay(2000);
}



void box(){
  int fd = 1500;
  int stops = 1000;
  int turn = 650;

  for (int i=0; i < 4; i++) {
    test.moveForward();
    delay(fd);
    test.stop();
    delay(stops);
    test.turnLeft();
    delay(turn);
    test.stop();
    delay(stops);
  }
}

void armStepMove(int n, int step) {
  for (int i=0; i<20; i++) {
    arm.step(1);
    delay(n);
  }
}

void negBox() {
  int fd = 1500;
  int stops = 1000;
  int turn = 650;

  for (int i=0; i < 4; i++) {
    test.moveForward();
    delay(fd);
    test.stop();
    delay(stops);
    test.turnRight();
    delay(turn);
    test.stop();
    delay(stops);
  }


}

void sample() {
    box();
    delay(1000);
    armStepMove(150,1);
    armStepMove(150,-1);
    delay(1000);
    negBox();
    delay(2000);
    armStepMove(300,1);
    armStepMove(300,-1);
    delay(5000);
}



void test_loop() {
  int maxs[8] = {700,900,1022,1022, 800,800,1022,1022};
  int mins[8] = {850, 100,100,300, 100,850, 0, 0};
  reader.setMax(maxs);
  reader.setMin(mins);

  while (1)
    sample();
  char temp = '0';

  // if (radio.available()) {  // Check whether there is data to be received
  //   radio.read(&temp, sizeof(char)); // Read the whole data and store it into the 'data' structure
    // reader.printRaw(data);




  // data.pots[0] = analogRead(A9); // first index broken
  data.pots[1] = analogRead(A5); // first mid
  data.pots[2] = analogRead(A6); // first pink
  data.pots[3] = analogRead(A7); // 2nd ibndex
  data.pots[4] = analogRead(A8); // 2nd mid
  // data.pots[5] = analogRead(A10); // 2nd pink broken
  reader.printRaw(data); 

  // char temp = '0';
 if ((reader.digital(data,1,0.7) == 0) && (reader.digital(data,2,0.7) == 0 ) && (reader.digital(data,3,0.7) == 0 ) && (reader.digital(data,4,0.7) == 0 )) {
    temp = 'C';
  } else if ((reader.digital(data,3,0.7) == 0) && (reader.digital(data,4,0.7) == 1 )) {
    temp  = 'l';
  } else if ((reader.digital(data,3,0.7) == 1) && (reader.digital(data,3,0.7) == 1))  {
    temp = 'r';

  } else if ((reader.digital(data,3,0.7) == 0) && (reader.digital(data,4,0.7) == 0)) {
    temp = 'f';

  } else if ((reader.digital(data,1,0.7) == 0) && (reader.digital(data,2,0.7) == 0)){
    temp = 'b';
  } else if (reader.digital(data,1,0.7) == 0) {
    temp = 'D';
  } else if (reader.digital(data,2,0.7) == 0) {
    temp = 'U';
  } 


  if (temp == '0') {
    test.stop();
  }
  else if (temp == 'l') {
    test.turnLeft();
    Serial.println("Chassis turn left");

  } else if (temp == 'r')  {
    test.turnRight();
    Serial.println("Chassis right");

  } else if (temp == 'C') {
    is_claw_closed = !is_claw_closed;
    if (is_claw_closed) {
      arm.moveServo(3,110);
    } else {
      arm.moveServo(3,40);
    }
    delay(1500);
    Serial.println("claw close toggle");

  } else if (temp == 'f')  {
    test.moveForward();
    Serial.println("Chassis forward");

  } else if (temp == 'b') {
    test.moveBackward();
    Serial.println("Chassis back");
  } else if (temp == 'D') {
    arm.step(1);
    delay(200);
    Serial.println("claw down");

  } else if (temp == 'U')  {
    arm.step(-1);
    delay(200);
    Serial.println("claw up");
  } 


    // if (data.pots[0] > 900) {
    //   arm.moveServo(3,40);
    // } else {
    //   arm.moveServo(3,110);
    // }

    // if (data.pots[1] < 900) {
    //   arm.goDown( );
    // }
    // if (data.pots[2] < 900) {
    //   arm.gotoRest();
    // }
}







#endif