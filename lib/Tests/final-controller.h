#ifndef FINAL_CONTROLLER_H
#define FINAL_CONTROLLER_H
/*

index down forward chassis
middle down back chassis
index and middle turn chassis left
middle and pink turn chassis right

index down claw down
middle down claw up
all down claw close (toggle)


*/
#include <Arduino.h>
#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>
#include "Transciever.h"

Data_Package data;
DataReader reader;
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void test_setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
  Serial.begin(9600);
  Serial.println("Done with controller");
}

void test_loop() {
  int maxs[8] = {1022,1012, 1004, 816, 846,799, 0 ,0};
  int mins[8] = {851, 935, 674, 638, 231, 304, 0, 0};
  reader.setMax(maxs);
  reader.setMin(mins);

  // Send the whole data from the structure to the receiver
  data.pots[0] = analogRead(A2); // first index
  data.pots[1] = analogRead(A1); // first mid
  data.pots[2] = analogRead(A0); // first pink
  data.pots[3] = analogRead(A3); // 2nd index
  data.pots[4] = analogRead(A4); // 2nd mid
  data.pots[5] = analogRead(A5); // 2nd pink
  reader.printRaw(data);

  char temp = '0';

  if ((reader.digital(data,0,0.7) == 0) && (reader.digital(data,1,0.7) == 0 )) {
    temp  = 'l';
    Serial.println("Chassis turn left");

  } else if ((reader.digital(data,1,0.7) == 0) && (reader.digital(data,2,0.7) == 0 ))  {
    temp = 'r';
    Serial.println("Chassis right");

  } else if ((reader.digital(data,3,0.7) == 0) && (reader.digital(data,4,0.7) == 1 ) && (reader.digital(data,5,0.7) == 0 )) {
    temp = 'C';
    Serial.println("claw close toggle");

  } else if (reader.digital(data,0,0.7) == 0) {
    temp = 'f';
    Serial.println("Chassis forward");

  } else if (reader.digital(data,1,0.7) == 0) {
    temp = 'b';
    Serial.println("Chassis back");


  } else if (reader.digital(data,3,0.7) == 0) {
    temp = 'D';
    Serial.println("claw down");

  } else if (reader.digital(data,4,0.7) == 1) {
    temp = 'U';
    Serial.println("claw up");
  } 

  radio.write(&temp, sizeof(char));
  
  delay(200);
}


// index down forward chassis
// middle down back chassis
// index and middle turn chassis left
// middle and pink turn chassis right

// index down claw down
// middle down claw up
// all down claw close (toggle)



// 550-440 0-100 flashes of  660 and 300





#endif