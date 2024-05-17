#ifndef TEST_RADIO_BASIC_H
#define TEST_RADIO_BASIC_H

#include <Arduino.h>
#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>

// RF24 radio(7, 8); // CE, CSN
// const byte address[6] = "00001";
// bool isDouble = true;


void test_setup() {
    Serial.begin(9600);
    Serial.println("Hey");
    
    // radio.begin();
    // radio.openWritingPipe(address);
    // radio.setPALevel(RF24_PA_MIN);
    // radio.stopListening();

}

void test_loop() {
    Serial.println("FEPFEPFEP");
    

    // if (isDouble) {
    //     const double number = 0.3424897;
    //     radio.write("D", 1); // Send type identifier for double
    //     radio.write(&number, sizeof(number));
    //     isDouble = false; // Toggle flag
    // } else {
    //     const char text[] = "Hello";
    //     radio.write("S", 1); // Send type identifier for string
    //     radio.write(text, sizeof(text));
    //     isDouble = true; // Toggle flag
    // }

}

#endif