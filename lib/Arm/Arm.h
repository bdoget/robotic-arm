#ifndef Arm_H
#define Arm_H

class Arm {
    public:
        void init(int pinOne, int pinTwo, int pinThree);
        void servoMoveForward(int currentpos, int targetpos);
        void servoMoveBackward(int currentpos, int targetpos);
    

    private:
        int pinOne;
        int pinTwo;
        int pinThree;
};