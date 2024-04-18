// C++ code
//
int pinOne = 5;
int pinTwo = 4;
int TURNING_SPEED = 150;
int enaPin = 6;
void setup()
{
  pinMode(pinOne, OUTPUT);
  pinMode(pinTwo, OUTPUT);
}

void loop()
{
  moveWheel(pinOne, pinTwo, true);
  delay(1000);
}

void moveWheel(int pin1, int pin2, bool forward){
  if (forward){ // move pin forward or back
  	digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
  }
  else{
  	digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
  }
  analogWrite(enaPin, TURNING_SPEED);
}