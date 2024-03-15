#include <Arduino.h>  // If you're not using Arduino, you can remove this line
#include "Arm.h"
#include "Arm.cpp"

// Define pin numbers for the servos
const int servoPin1 = 9;
const int servoPin2 = 10;
const int servoPin3 = 11; // Assuming there are three servos

// Function prototypes
void testArm();

int main() {
    // Initialize the Arm
    Arm arm(servoPin1, servoPin2, servoPin3);

    // Run tests
    testArm();

    return 0;
}

void testArm() {
    // Test moveForward method
    Serial.println("Moving arm forward...");
    arm.moveForward(0, 180); // Move from 0 to 180 degrees
    delay(2000); // Wait for 2 seconds

    // Test moveBackward method
    Serial.println("Moving arm backward...");
    arm.moveBackward(180, 0); // Move from 180 to 0 degrees
    delay(2000); // Wait for 2 seconds
}
