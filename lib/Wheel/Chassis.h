#ifndef Chassis_H
#define Chassis_H
#include "Wheel.h"


class Chassis{
    public:
    void init(Wheel tR, Wheel tL, Wheel bL, Wheel bR, int speed_);
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void turnRight();
    void turnLeft();
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