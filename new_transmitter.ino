#include <SPI.h> 
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
bool isDouble = true;

void setup()
{
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop()
{
  if (isDouble)
  {
    const double number = 0.3424897;
    radio.write("D", 1); // Send type identifier for double
    radio.write(&number, sizeof(number));
    isDouble = false; // Toggle flag
  } 
  else
  {
    const char text[] = "Hello";
    radio.write("S", 1); // Send type identifier for string
    radio.write(text, sizeof(text));
    isDouble = true; // Toggle flag
  }
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
