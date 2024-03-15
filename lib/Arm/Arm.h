#ifndef Arm_H
#define Arm_H
#include <Servo.h>

class Arm {
    public:
        void init(int pinOne, int pinTwo, int pinThree);
        Servo1.attach(pinOne);
        Servo2.attach(pinTwo);
        Servo3.attach(pinThree);
        void servoMoveForward(int currentpos, int targetpos);
        void servoMoveBackward(int currentpos, int targetpos);
    

    private:
        int pinOne;
        int pinTwo;
        int pinThree;
        Servo Servo1;
        Servo Servo2;
        Servo Servo3;
    
};



