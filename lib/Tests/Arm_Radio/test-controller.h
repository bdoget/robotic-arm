#ifndef TEST_RADIO_ARMC_H
#define TEST_RADIO_ARMC_H

#include <Arduino.h>
#include "Transciever.h"

Transciever radio;
Data_Package data;
DataReader reader;

void test_setup() {
  radio.initTransmitter(7,8);
  Serial.begin(9600);
  Serial.println("Done with controller");
}

void test_loop() {
  // Send the whole data from the structure to the receiver
  data.pots[0] = analogRead(A0);
  data.pots[1] = analogRead(A1);
  data.pots[2] = analogRead(A2);
  data.pots[3] = analogRead(A3);
  reader.printRaw(data);

  radio.sendData(data);
  delay(100);
}

// 550-440 0-100 flashes of  660 and 300

#endif