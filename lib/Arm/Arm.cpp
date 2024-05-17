#include "Arduino.h"
#include "Arm.h"
#include <Servo.h>

// --------


void Arm::init(int pin1, int pin2, int pin3, int pin4){

    servos[0].attach(pin1);
    servos[1].attach(pin2);
    servos[2].attach(pin3);
    servos[3].attach(pin4);

    maxs[0] = 90;
    maxs[1] = 90;
    maxs[2] = 90;
    maxs[3] = 120;

    for (int i=0; i < 4; i++)
        mins[i] = 0;
    

    Serial.print("setup done");
}

void Arm::moveServo(int servoNum, int angle){
    if (servoNum >= 0 && servoNum < 4 && angle <= maxs[servoNum] && angle >= mins[servoNum]) {
        servos[servoNum].write(angle);
    }
    else {
        Serial.print("Invalid servo num or angle exceeded min or max");
    }
}

void Arm::gotoRest() {
    moveServo(0,90);
    moveServo(1 ,90);
    moveServo(2, 90);
    moveServo(3, 90);

}


