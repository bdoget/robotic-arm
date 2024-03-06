#include "Chassis.h"

void Chassis::init(Wheel tR, Wheel tL, Wheel bL, Wheel bR, int speed_)
{
    // assumes all wheels have been properly initalized.
    topRight = tR;
    topLeft = tL;
    bottomLeft = bL;
    bottomRight = bR;
    wheelSpeed = speed_;
}

int Chassis::getWheelSpeed(){
// gets the speed of the wheel
    return wheelSpeed;
}

void Chassis::setWheelSpeed(int newSpeed){
// sets the current speed to all wheels
    if (newSpeed < 0){newSpeed = 0;}
    topRight.setSpeed(newSpeed);
    topLeft.setSpeed(newSpeed);
    bottomLeft.setSpeed(newSpeed);
    bottomRight.setSpeed(newSpeed);
}


void Chassis::moveForward(int speed){
/*moves the chassis forward */

    topRight.moveSpeed(speed);
    topLeft.moveSpeed(speed);
    bottomRight.moveSpeed(speed);
    bottomLeft.moveSpeed(speed);

}


void Chassis::moveBackward(int speed){
/*moves the chassis forward */

    topRight.moveSpeed(-speed);
    topLeft.moveSpeed(-speed);
    bottomRight.moveSpeed(-speed);
    bottomLeft.moveSpeed(-speed);

}


void Chassis::moveLeft(int speed){
/*moves the chassis left by adjust the wheels accordingly
left wheels will move in reverse,
right wheel will move forward*/

    topRight.moveSpeed(speed);
    topLeft.moveSpeed(-speed);
    bottomRight.moveSpeed(speed);
    bottomLeft.moveSpeed(-speed);

}


void Chassis::moveRight(int speed){
/*moves the chassis right by adjust the wheels accordingly
right wheels will move in reverse,
left wheel will move forward*/

    topRight.moveSpeed(-speed);
    topLeft.moveSpeed(speed);
    bottomRight.moveSpeed(-speed);
    bottomLeft.moveSpeed(speed);

}


void Chassis::stop(){
//stops the entire chassis from moving.
    topRight.stop();
    topLeft.stop();
    bottomRight.stop();
    bottomLeft.stop();
}