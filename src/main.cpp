#include "Arduino.h"

void setup()
{
  Serial.begin(9600);
  Serial.println("Done with setup");
}

void loop() {
  Serial.println("In loop now");
  delay(1000);
}
