#include "Arduino.h"
#include "Arm.h"

// --------


Arm::Arm(int pin1, int pin2, int pin3){
    Servo1.attach(pin1);
    Servo2.attach(pin2);
    Servo3.attach(pin3);
}

void Arm::moveServo1(int angle){
    // ELBOW
    Servo1.write(angle)
    // write functionality to make this move slower
   
}
 
void Arm::moveServo2(int angle){
    // WRIST
    Servo2.write(angle)
    // write functionality to make this move faster
   
}

void Arm::moveServo3(int angle){
    // CLAW
    Servo3.write(angle)
    // write functionality to make this move faster/slower
   
}
