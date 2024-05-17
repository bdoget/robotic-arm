#ifndef TEST_RADIO_ARMR_H
#define TEST_RADIO_ARMR_H

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include "Arm.h"
Arm arm;

RF24 radio(40, 41); // CE, CSN
const byte address[6] = "00001";
// Max size for a struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
  int first_pot = 0;
  int second_pot = 0;
};
Data_Package data; //Create a variable with the above structure




void test_setup() {
  arm.init(A3,A2,A1,A4); // place pins in order of this: shoulder,elbow, wrist, claw 

  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_LOW);
  radio.startListening();
}

void test_loop() {
  // Check whether there is data to be received
  if (radio.available()) {
    radio.read(&data, sizeof(Data_Package)); // Read the whole data and store it into the 'data' structure

    Serial.print("first potentiometer: ");
    Serial.print(data.first_pot);
    Serial.print(" second potentiometer: ");
    Serial.print(data.second_pot);
    Serial.println("");

    if (data.first_pot > 500) {
      arm.gotoRest();
    } else {
      arm.goDown();
    }

  }
  // Serial.print("loop");
}




#endif