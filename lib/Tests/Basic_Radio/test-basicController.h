#ifndef TEST_RADIO_BASIC_CONTROLLER_H
#define TEST_RADIO_BASIC_CONTROLLER_H

#include <Arduino.h>
#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}


void loop() {
  if (radio.available()) {
    char type;
    radio.read(&type, 1); // Read the type identifier
    if (type == 'D') {
      double number;
      radio.read(&number, sizeof(number));
      Serial.println(number);
    } else if (type == 'S') {
      char text[6];
      radio.read(text, sizeof(text));
      Serial.println(text);
    }
  }
  delay(1000);
}




#endif