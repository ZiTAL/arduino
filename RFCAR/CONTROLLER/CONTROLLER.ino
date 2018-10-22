// https://www.brainy-bits.com/arduino-joystick-tutorial/

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

// JOYSTICK

const int LEFT_X = 0; // arduino analog 0 // joystick X, VRx
const int LEFT_Y = 1; // arduino analog 1 // joystick Y, VRy
const int LEFT_B = 2; // arduino digital 2 // joystick KEY, SW

const int RIGHT_X = 2; // arduino analog 2 // joystick X, VRx
const int RIGHT_Y = 3; // arduino analog 3 // joystick Y, VRy
const int RIGHT_B = 4; // arduino digital 4 // joystick KEY, SW

int LEFT_Y_V;
int LEFT_D;

int LEFT_B_V;
int RIGHT_B_V;

float LEFT_MIN = 75;
float LEFT_MAX = 255;

// RF

const int pinCE = 9;
const int pinCSN = 10;
RF24 radio(pinCE, pinCSN);
 
// Single radio pipe address for the 2 nodes to communicate.
const uint64_t pipe = 0xE8E8F0F0E1LL;

char data[5];

void setup()
{
    //Serial.begin(9600);
    pinMode(LEFT_B, INPUT_PULLUP);
    pinMode(RIGHT_B, INPUT_PULLUP);

    radio.begin();
    radio.openWritingPipe(pipe);    
}

void loop()
{
    LEFT_B_V = digitalRead(LEFT_B);
    RIGHT_B_V = digitalRead(RIGHT_B);
    
    if(LEFT_B_V==0)
        LEFT_B_V = 1;
    else
        LEFT_B_V = 0;

    if(RIGHT_B_V==0)
        RIGHT_B_V = 1;
    else
        RIGHT_B_V = 0;

    LEFT_Y_V = analogRead(LEFT_Y);

    if(LEFT_Y_V<512)
      LEFT_D = 1;

    else
    {
      if(LEFT_Y_V>512)
        LEFT_D = -1;
    }

    if(LEFT_Y_V>=512-5 && LEFT_Y_V<=512+5)
    {
      LEFT_D = 0;
      LEFT_Y_V = 0;
    }
    else
    {
      if(LEFT_D==1)
        LEFT_Y_V = 255 - (LEFT_Y_V / 2);
      else
        LEFT_Y_V = (LEFT_Y_V / 2) / 2 * -1;

      LEFT_Y_V = powerCalc(LEFT_Y_V, LEFT_MIN, LEFT_MAX);
    }
    
    String str = String(LEFT_Y_V);
    int str_len = str.length() + 1;
    
    // Copy it over 
    str.toCharArray(data, str_len);
    radio.write(data, sizeof data);
}

int powerCalc(int v, float min, float max)
{
  float j;
  int r;
  int v2;

  v2 = v;

  if(v2<0)
    v = v * -1;  
  
  j = round(v * ((max - min) / max) + min); 
  r = j;

  if(v2<0)
    r = r * -1;

  return r;
}
