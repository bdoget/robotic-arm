#ifndef TEST_RADIO_ARMR_H
#define TEST_RADIO_ARMR_H

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include "Transciever.h"

#include "Arm.h"
Arm arm;

RF24 radio(40, 41); // CE, CSN
const byte address[6] = "00001";

Data_Package data; //Create a variable with the above structure
DataReader reader;

void test_setup() {
  arm.init(A3,A2,A1,A4); // place pins in order of this: shoulder,elbow, wrist, claw 

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void test_loop() {

  // while(1) {
  //   // arm.gotoRest();
  //   // delay(2000);
  //   // arm.goDown();
  //   // delay(2000);
  //   arm.moveServo(3,40);
  //   Serial.println(40);
  //   delay(2000);
  //   arm.moveServo(3,100);
  //   Serial.println(100);
  //   delay(2000);
  // }

  // Check whether there is data to be received
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
    reader.printRaw(data);

    if (data.pots[0] > 900) {
      arm.moveServo(3,40);
    } else {
      arm.moveServo(3,110);
    }

    if (data.pots[1] < 900) {
      arm.goDown( );
    }
    if (data.pots[2] < 900) {
      arm.gotoRest();
    }
  }

}




#endif