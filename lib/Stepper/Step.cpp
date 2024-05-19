#include "Arduino.h"
#include <Stepper.h>
/*
CircuitMagic.com
*/


int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

// change this to the number of steps on your motor
#define STEPS 512

Stepper motor(STEPS, in1Pin, in2Pin, in3Pin, in4Pin);

void setup()
{

Serial.begin(9600);
motor.setSpeed(20);
}

void loop()
{

motor.step(1);
Serial.println("STEP");

}