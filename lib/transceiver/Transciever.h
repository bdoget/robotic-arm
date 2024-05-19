#ifndef Transciever_H
#define Transciever_H

#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// NEEDED: A call to the arm class that includes the pins of each servo

//         SERVO 1: elbow
//         SERVO 2: wrist
//         SERVO 3: claw
//
// INFO: Three functions for each servo. Each function will need an angle to move the servo to. 

struct Data_Package {
    int pots[8] = {0,0,0,0, 0,0,0,0};
};

// Data_Package data; // Create a variable with the above structure


class Transciever {
    public:
        RF24* radio = NULL;
        const byte address[6] = "00001";

        void initReciever(int cepin, int cspin);
        void initTransmitter(int cepin, int cspin);
        void sendData(Data_Package data);
        
        void deleteAll();

    private:
};

class DataReader {
    public:
        int min[8];
        int max[8];
        void setMin(int mins[8]);
        void setMax(int maxs[8]);
        
        int digital(Data_Package data, int pin, float thres); // Returns 0 if below threshold, 1 if above threshold
        int analog (Data_Package data, int pin); // Returns number from 1-100 scaled by min and max on each pin
        void printRaw(Data_Package data);
        void printDigital(Data_Package data, float thres);
        void printAnalog(Data_Package data);
    private:
};

#endif