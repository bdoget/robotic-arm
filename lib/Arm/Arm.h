#ifndef Arm_H
#define Arm_H

class Arm {
    public:
        void init(int pinOne, int pinTwo, int pinThree);
        void moveForward(int currentpos, int targetpos);
        void moveBackward(int currentpos, int targetpos);
    

    private:
        int pinOne;
        int pinTwo;
        int pinThree;
};