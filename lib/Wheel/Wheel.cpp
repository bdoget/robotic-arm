#include "Wheel.h"
#include "Arduino.h"

// ---------------------------------------------------------------------------
void Wheel::init(int enA_, int in1_, int in2_)
{
    enA = enA_;
    in1 = in1_;
    in2 = in2_;
    pinMode(enA, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    // Serial.println(enA);
}

void Wheel::moveSpeed(int speed)
/* Moves the wheel forward or backward, depending on the speed
param: speed (the designated speed of the wheel)
*/
{
    // Serial.print(speed);
    if (speed >= 0) {
        // Clockwise
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
    } else {
        // Counterclockwise
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
    }
    analogWrite(enA, abs(speed));
}

void Wheel::setSpeed(int newSpeed){
// sets the speed of the wheel
    speed = newSpeed;
}


void Wheel::stop(){
    // just stops the wheel
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    analogWrite(enA, 0);
}