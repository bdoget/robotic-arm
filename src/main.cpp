#include <Arduino.h>
#include "test-wheels.h"

void setup() {
  test_setup();
}

void loop() {
  test_basic_movements();
  test_turn_in_place();
  test_turning();
}
