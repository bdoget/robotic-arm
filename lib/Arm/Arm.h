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
        void init(int pin1, int pin2, int pin3, int pin4);
        void moveServo(int servoNum, int angle);
        void gotoRest();
        void goDown();
        int lerp(int start, int stop, float time);
        void step(int dir);
        void setSpeed(float dt);

    private:
        Servo servos[4];
        int mins[4];
        int maxs[4]; 

        int phase = 0;
        float time = 0;
        float dt = 0;

        int rest[3] = {90,120,90};
        int down[3] = {130,0,40};
    
};

#endif

