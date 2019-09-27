#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

// MOTOR

int IN1 = 8;
int IN2 = 7;
int ENA = 6;

// RF
 
const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;
 
char data[5];
int i;
 
void setup()
{
    Serial.begin(9600);

    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);     
   
    radio.begin();
    radio.openReadingPipe(1,pipe);
    radio.startListening();
}
 
void loop()
{
   if (radio.available())
   {
      radio.read(data, sizeof(data)); 
      i = atoi(data);
      if(i==0)
      {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
      }
      else
      {
        if(i>0)
        {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);          
        }
        else
        {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          i = i * -1;          
        }
      }
      analogWrite(ENA, i);
   }
}
