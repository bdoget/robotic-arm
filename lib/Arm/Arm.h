#ifndef Arm_H
#define Arm_H

class Arm {
    public:
        void init(int pinOne, int pinTwo, int pinThree);
        void moveForward(int currentpos);
        void moveBackward(int currentpos);
    

    private:
        int pinOne;
        int pinTwo;
        int pinThree;
};