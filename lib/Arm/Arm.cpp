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

    for (int i=0; i < 4; i++) {
        maxs[i] = 180;
        mins[i] = 0;
    }
    
    phase = 0;
    time = 0;
    dt = 0.05;

    gotoRest();
    delay(1000);

    Serial.print("setup done");
}

void Arm::moveServo(int servoNum, int angle){
    if (!(servoNum >= 0 && servoNum < 4 && angle <= maxs[servoNum] && angle >= mins[servoNum])) {
        Serial.println("Invalid servo num or angle exceeded min or max");
        return;
    }
    servos[servoNum].write(angle);
}

void Arm::gotoRest() {
    moveServo(0,90);
    moveServo(1 ,120);
    moveServo(2, 90);
    // moveServo(3, 90);
}

void Arm::goDown() {
    moveServo(0, 130);
    moveServo(1, 0);
    moveServo(2, 40);
    // moveServo(3, 90); 
}

int Arm::lerp(int start, int stop, float time) {
    return start + (stop-start)*time;
}

void Arm::step(int dir) {
    int rest[3] = {90,120,90};
    int down[3] = {130,0,40};


    if (time+dt*dir > 1 || time+dt*dir < 0) 
        return;
    time += dt*dir;

    for (int i=0; i<3;i++) {
        int end = lerp(rest[i],down[i],time);
        servos[i].write(end);
    }

}

void Arm::setSpeed(float dtA) {
    dt = dtA;
}

