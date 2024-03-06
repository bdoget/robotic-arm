#ifndef Chassis_H
#define Chassis_H
#include "Wheel.h"


class Chassis{
    public:
    void init(Wheel tR, Wheel tL, Wheel bL, Wheel bR, int speed_);
    void moveForward(int speed);
    void moveBackward(int speed);
    void moveLeft(int speed);
    void moveRight(int speed);
    int getWheelSpeed();
    void setWheelSpeed(int newSpeed);
    void stop();
    

    private:
        Wheel topRight;
        Wheel topLeft;
        Wheel bottomLeft;
        Wheel bottomRight;

        int wheelSpeed = 0;
};




#endif