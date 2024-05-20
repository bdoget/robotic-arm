#ifndef TEST_RADIO_ARMR_H
#define TEST_RADIO_ARMR_H

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

void test_setup() {
  arm.init(A3,A4,A1,A2); // place pins in order of this: shoulder,elbow, wrist, claw 

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();
}

void test_loop() {
  if (radio.available()) {  // Check whether there is data to be received
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure
    reader.printRaw(data);

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

}




#endif