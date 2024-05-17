#ifndef TEST_RADIO_BASIC_H
#define TEST_RADIO_BASIC_H

#include <Arduino.h>
#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>

// RF24 radio(7, 8); // CE, CSN
// const byte address[6] = "00001";
// bool isDouble = true;


// void test_setup() {
//     Serial.begin(9600);
//     Serial.println("Hey");
    
//     radio.begin();
//     radio.openWritingPipe(address);
//     radio.setPALevel(RF24_PA_MIN);
//     radio.stopListening();

// }

// void test_loop() {
//     Serial.println("loop __");


//     if (isDouble) {
//         const double number = 0.3424897;
//         radio.write("D", 1); // Send type identifier for double
//         radio.write(&number, sizeof(number));
//         isDouble = false; // Toggle flag
//     } else {
//         const char text[] = "Hello";
//         radio.write("S", 1); // Send type identifier for string
//         radio.write(text, sizeof(text));
//         isDouble = true; // Toggle flag
//     }
//     // delay(500);

// }



// #include <SPI.h>
// #include <nRF24L01.h>
// #include <RF24.h>

// RF24 radio(7, 8); // CE, CSN

// const byte address[6] = "00001";

// void test_setup() {
//   radio.begin();
//   radio.openWritingPipe(address);
//   radio.setPALevel(RF24_PA_MIN);
//   radio.stopListening();
// }

// void test_loop() {
//   const char text[] = "Hello World";
//   radio.write(&text, sizeof(text));
//   delay(1000);
// }


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
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void test_loop() {
  // Send the whole data from the structure to the receiver
  data.first_pot = analogRead(A0);
  data.second_pot = analogRead(A1);
  radio.write(&data, sizeof(Data_Package));
  delay(500);
}

#endif