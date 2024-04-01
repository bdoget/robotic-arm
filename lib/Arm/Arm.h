#ifndef Arm_H
#define Arm_H
#include <Servo.h>




// NEEDED: A call to the arm class that includes the pins of each servo
//         SERVO 1: elbow
//         SERVO 2: wrist
//         SERVO 3: claw
//
// INFO: Three functions for each servo. Each function will need an angle to move the servo to. 

class Arm {
    public:
        Arm(int pin1, int pin2, int pin3){
            Servo1.attach(pin1);
            Servo2.attach(pin2);
            Servo3.attach(pin3);        
        }
        void moveServo1;
        void moveServo2;
        void moveServo3;
    

    private:
        Servo Servo1;
        Servo Servo2;
        Servo Servo3;
    
};



