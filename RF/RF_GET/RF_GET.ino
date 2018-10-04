#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
char data[16];

void setup()
{
   Serial.begin(9600);
   radio.begin();
   radio.openReadingPipe(1, pipe);
   radio.startListening();
}

void loop()
{
   if (radio.available())
   {
      radio.read(data, 16); 
      Serial.println(data);
   }
}
