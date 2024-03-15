#include "Arduino.h"
#include "Arm.h"

// --------

void Arm::init(int pinOne, int pinTwo, int pinThree)
{
    pinOne = pinOne;
    pinTwo = pinTwo;
    pinThree = pinThree;


}


// Below, we need current pos of each servo stored elsewhere, then passed
// into functions below, the target pos will be returned. 

float Arm::servoMoveForward(float currentpos, float targetpos)
{
    for (pos = currentpos; pos <= targetpos; pos += 25) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
    return target pos

    // TODO: change currentpos to target pos
}
 }



float Arm::servoMoveBackward(float currentpos, float targetpos);
{
    for (pos = currentpos; pos >= targetpos; pos -= 25)
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
    
    return targetpos
}


///////// TEST  ///////////
