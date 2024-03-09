#include "Arduino.h"
#include "Arm.h"

// --------

void Arm::init(int pinOne, int pinTwo, int pinThree)
{
    pinOne = pinOne;
    pinTwo = pinTwo;
    pinThree = pinThree;
    


}


void Arm::moveForward(int currentpos)
{
    for (pos = 0; pos <= 180; pos += 25) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
}
 }



void Arm::moveBackward(int currentpos);
{
    for (pos = 0; pos <= 180; pos -= 25)
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos);
    servo_10.write(pos);
    // wait 15 ms for servo to reach the position
    delay(15); // Wait for 15 millisecond(s)
}