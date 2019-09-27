
// Demonstration Arduino sketch for four digit, seven segment display with enclosure
// http://tronixlabs.com/display/led/numeric/four-digit-seven-segment-display-module-and-enclosure/

#include <EEPROM.h>

int latchPin = 9;   // connect to LOAD pin
int clockPin = 10;   // connect to SCLK pin
int dataPin = 11;    // connect to SDI pin

int sum = 7;
int sumState = 0;
int rest = 8;
int restState = 0;

/*
int LED_SEG_TAB[]={
  0x00, 0x01, 0x02, 0x03, 0x08, 0x09, 0x11, 0x18, 0x19, 0x25, 0x31, 0x39, 0x40, 0x41, 0x48, 0x49, 0x61, 0x63, 0x71,
// 8.   8     0.    0     9.    9     A     9.    9     2     P     º     6.    6     5.    5     E     C     F

  0x83, 0x87, 0x91, 0x98, 0x99, 0xbf, 0xe3, 0xef, 0xf3, 0xfd, 0xfe, 0xff, 0x0c, 0x0d, 0x1a, 0x1b, 0x9e, 0x9f
// U    J     H     4.    4     '     L     _     I     -     .     hutsik 3.   3     7.    7     1.    1
};
*/

int LED_SEG_TAB[] =
{
  0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1b, 0x01, 0x19
//  0   1     2      3    4     5     6     7     8     9  
};


void setup() 
{
  Serial.begin(9600);
  
  //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(sum, INPUT);
  pinMode(rest, INPUT);

  // resetMemory();
}

void loop() 
{
  int left = 0;
  int right = 0;  

  int i = readMemory();
  sumState = digitalRead(sum);
  restState = digitalRead(rest);

  // reset
  if(sumState == HIGH && restState == HIGH)
  {
    left = 0;
    right = 0;  
  }
  else
  {
    //Serial.println(i);
    if (sumState == HIGH)
    {  
      i++;
      if(i>99)
        i = 99;
    }
    else if (restState == HIGH)
    {  
      i--;
      if(i<0)
        i = 0;
    }  
  
    left = i / 10;
    right = i % 10;
  }

  writeMemory(left, right);
  
  digitalWrite(latchPin, LOW);  
  shiftOut(dataPin, clockPin, LSBFIRST, LED_SEG_TAB[right]);
  shiftOut(dataPin, clockPin, LSBFIRST, LED_SEG_TAB[left]);
  digitalWrite(latchPin, HIGH);

  delay(100);
}

int readMemory()
{
  int i;
  
  int left = EEPROM.read(0);
  int right = EEPROM.read(1);

  i = left * 10 + right;
  return i;
}

void writeMemory(int left, int right)
{
  EEPROM.write(0, left);
  EEPROM.write(1, right);  
}

void resetMemory()
{
  writeMemory(0, 0);
}
