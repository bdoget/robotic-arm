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
    if (newSpeed < 0){newSpeed *= -1;}
    topRight.setSpeed(newSpeed);
    topLeft.setSpeed(newSpeed);
    bottomLeft.setSpeed(newSpeed);
    bottomRight.setSpeed(newSpeed);
}


void Chassis::moveForward(){
/*moves the chassis forward */

    topRight.moveSpeed(wheelSpeed);
    topLeft.moveSpeed(wheelSpeed);
    bottomRight.moveSpeed(wheelSpeed);
    bottomLeft.moveSpeed(wheelSpeed);

}


void Chassis::moveBackward(){
/*moves the chassis forward */

    topRight.moveSpeed(-wheelSpeed);
    topLeft.moveSpeed(-wheelSpeed);
    bottomRight.moveSpeed(-wheelSpeed);
    bottomLeft.moveSpeed(-wheelSpeed);

}


void Chassis::moveRight(){
/*moves the chassis left by adjust the wheels accordingly
topRight/bottomLeft counter,
topLeft/bottomRight clockwise*/

    topRight.moveSpeed(-wheelSpeed);
    topLeft.moveSpeed(wheelSpeed);
    bottomRight.moveSpeed(wheelSpeed);
    bottomLeft.moveSpeed(-wheelSpeed);

}


void Chassis::moveLeft(){
/*moves the chassis right by adjust the wheels accordingly
topRight/bottomLeft clockwise,
topLeft/bottomRight counter
*/

    topRight.moveSpeed(wheelSpeed);
    topLeft.moveSpeed(-wheelSpeed);
    bottomRight.moveSpeed(-wheelSpeed);
    bottomLeft.moveSpeed(wheelSpeed);
}


void Chassis::turnRight(){
/*moves the chassis right by adjust the wheels accordingly
right wheels will move forward,
left wheel will move in reverse*/

    topRight.moveSpeed(wheelSpeed);
    topLeft.moveSpeed(-wheelSpeed);
    bottomRight.moveSpeed(wheelSpeed);
    bottomLeft.moveSpeed(-wheelSpeed);
}


void Chassis::turnLeft(){
/*moves the chassis right by adjust the wheels accordingly
right wheels will move in reverse,
left wheel will move forward*/

    topRight.moveSpeed(-wheelSpeed);
    topLeft.moveSpeed(wheelSpeed);
    bottomRight.moveSpeed(-wheelSpeed);
    bottomLeft.moveSpeed(wheelSpeed);
}



void Chassis::stop(){
//stops the entire chassis from moving.
    topRight.stop();
    topLeft.stop();
    bottomRight.stop();
    bottomLeft.stop();
}