#include "Arduino.h"
#include "Arm.h"
#include <Servo.h>

// --------


void Arm::init(int pin1, int pin2, int pin3, int pin4){
// place pins in order of this: shoulder,elbow, wrist, claw 
    servos[0].attach(pin1);
    servos[1].attach(pin2);
    servos[2].attach(pin3);
    servos[3].attach(pin4);

    maxs[0] = 180;
    maxs[1] = 180;
    maxs[2] = 180;
    maxs[3] = 180;

    for (int i=0; i < 4; i++)
        mins[i] = 0;
    

    Serial.print("setup done");
}

void Arm::moveServo(int servoNum, int angle){
    // if (servoNum >= 0 && servoNum < 4 && angle <= maxs[servoNum] && angle >= mins[servoNum]) {
    //     servos[servoNum].write(angle);
    // }
    // else {
    //     Serial.println("Invalid servo num or angle exceeded min or max");
    // }
    servos[servoNum].write(angle);

}

void Arm::gotoRest() {
    moveServo(0,90);
    moveServo(1 ,120);
    moveServo(2, 90);
    moveServo(3, 90);
}

void Arm::goDown() {
    moveServo(0, 130);
    // moveServo(1, -30);
    moveServo(1, 0);
    moveServo(2, 40);
    // moveServo(3, 90);
}


