#include <Arduino.h>
#include "test-wheels.h"

void setup() {
  Serial.println("Start with setup");
  test_setup();
  Serial.println("Setup done");
}

void loop() {
  test_loop();
}

