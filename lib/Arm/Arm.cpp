#include "Arduino.h"
#include "Arm.h"

// --------

void Arm::init(int pinOne)
{
    pinOne = pinOne;

}


// Below, we need current pos of each servo stored elsewhere, then passed
// into functions below, the target pos will be returned. 

float Arm::servoMoveForward(float targetpos)
{
    servoBase.write(targetpos)
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
    return targetpos
}
 


