#ifndef TEST_RADIO_ARMC_H
#define TEST_RADIO_ARMC_H

#include <Arduino.h>
#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

// Max size for a struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package {
  int first_pot = 50;
  int second_pot = 100;
};

Data_Package data; // Create a variable with the above structure

void test_setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();
  Serial.begin(9600);
  Serial.println("Done with controller");
}

void test_loop() {
  // Send the whole data from the structure to the receiver
  data.first_pot = analogRead(A0);
  data.second_pot = analogRead(A1);

  Serial.print(data.first_pot);
  Serial.print(" ");
  Serial.print(data.second_pot);
  Serial.println(" ");

  radio.write(&data, sizeof(Data_Package));
  
  delay(100);
}

// 550-440 0-100 flashes of  660 and 300

#endif