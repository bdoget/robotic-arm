#include "Transciever.h"

void Transciever::initReciever(int cepin, int cspin) {
    radio = new RF24(cepin,cspin);
    radio->begin();
    radio->openReadingPipe(0, address);
    radio->setPALevel(RF24_PA_LOW);
    radio->startListening();
}

void Transciever::initTransmitter(int cepin, int cspin) {
    radio = new RF24(cepin,cspin);
    radio->begin();
    radio->openWritingPipe(address);
    radio->setPALevel(RF24_PA_LOW);
    radio->stopListening();
}
  
void Transciever::sendData(Data_Package data) {
    radio->write(&data, sizeof(Data_Package));
}

void Transciever::deleteAll() {
    delete radio;
}

void DataReader::setMin(int mins[8]) {
    for (int i=0; i<8;i++) 
        min[i] = mins[i];
}
void DataReader::setMax(int maxs[8]) {
    for (int i=0; i<8;i++) 
        max[i] = maxs[i];
}

int DataReader::digital(Data_Package data, int pin, float thres) {
    // thres between [0,1]
    // Returns 0 if below threshold, 1 if above threshold
    int input = data.pots[pin];
    if (input > (min[pin] + thres*(max[pin]-min[pin])))
        return 1;
    return 0;
}

int DataReader::analog (Data_Package data, int pin) {
    // Returns number from 1-100 scaled by min and max on each pin
    int input = data.pots[pin];
    return floor((input-min[pin])/ (max[pin]-min[pin]));
}

void DataReader::printRaw(Data_Package data) {
    Serial.print("Data: ");
    for (int i=0;i<8;i++) {
        Serial.print(data.pots[i]);
        Serial.print(" ");
    }
    Serial.println();
}

void DataReader::printDigital(Data_Package data, float thres) {
    Serial.print("DataDigital: ");
    for (int i=0;i<8;i++) {
        Serial.print(digital(data,i,thres));
        Serial.print(" ");
    }
    Serial.println();
}

void DataReader::printAnalog(Data_Package data) {
    Serial.print("DataDigital: ");
    for (int i=0;i<8;i++) {
        Serial.print(analog(data,i));
        Serial.print(" ");
    }
    Serial.println();
}
