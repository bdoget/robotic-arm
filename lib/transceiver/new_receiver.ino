#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

/*
void loop()
{
  if(radio.available())
  {
    double number;
    radio.read(&number, sizeof(number));
    Serial.println("The number is: ");
    Serial.println(number);
  }
}
*/

void loop() {
  if (radio.available()) {
    char type;
    radio.read(&type, 1); // Read the type identifier
    if (type == 'D') {
      double number;
      radio.read(&number, sizeof(number));
      Serial.println(number);
    } else if (type == 'S') {
      char text[6];
      radio.read(text, sizeof(text));
      Serial.println(text);
    }
  }
  delay(1000);
}

/*
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7,8); // CE and CNS pins

const byte address[6] = "00001"; // pipe "address"

void setup()
{
  Serial.begin(9600); // for printing purposes
  radio.begin();
  radio.setAutoAck(false); // ADDED LINE FOR DEBUGGING PURPOSES
  radio.openReadingPipe(0, address); // opens a writing pipe
  radio.setPALevel(RF24_PA_MAX); // set it to max for max range
  radio.setDataRate(RF24_250KBPS); // good balance between range and data
  radio.startListening(); 
  Serial.print("Done setup");
}


void loop()
{
  char text[32] = "";
  if (radio.available())
  {
    radio.read(&text, sizeof(text));
    String translate_data = String(text);
    Serial.println(translate_data);
    Serial.println("lol");
    if (translate_data == "nrftest")
    {
      Serial.println(translate_data);
      Serial.println("connection has been established!");
      while(true){}
    }
  }
}
*/

/*
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  if (radio.available()) {
    char text[32] = "";
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
*/