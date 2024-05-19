#include <Arduino.h>
#include "test-arm.h"

void setup() {
  Serial.println("Start with setup");
  test_setup();
  Serial.println("Setup done");
}

void loop() {
  test_claw();
}

