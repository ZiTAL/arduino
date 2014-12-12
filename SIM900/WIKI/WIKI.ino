/*
gnu/linux bidez konektateko
minicom -b 19200 -D /dev/ttyACM*
non * 0,1,2 zenbakidxek al dizen ezan.
adibidez: minicom -b 19200 -D /dev/ttyACM0

http://www.geeetech.com/wiki/index.php/Arduino_GPRS_Shield

SIM900 Junperrak Software moduan jarri

Pinak:
SIM900 7 -> Arduino 7
SIM900 8 -> Arduino 8
SIM900 9 -> Arduino 9
*/
#include <SoftwareSerial.h>
SoftwareSerial GPRS(7, 8);
unsigned char buffer[64];           // buffer array for data recieve over serial port
int count = 0;                      // counter for buffer array 
void setup()
{
  GPRS.begin(19200);               // the GPRS baud rate   
  Serial.begin(19200);             // the Serial port of Arduino baud rate.
}
void loop()
{
 if (GPRS.available())              // if date is comming from softwareserial port ==> data is comming from gprs shield
 {
   while(GPRS.available())          // reading data into char array 
   {
     buffer[count++] = GPRS.read(); // writing data into array
     if(count == 64)
       break;
   }
   Serial.write(buffer,count);      // if no data transmission ends, write buffer to hardware serial port
   clearBufferArray();              // call clearBufferArray function to clear the storaged data from the array
   count = 0;                       // set counter of while loop to zero
 }
 if (Serial.available())            // if data is available on hardwareserial port ==> data is comming from PC or notebook
   GPRS.write(Serial.read());       // write it to the GPRS shield
}

void clearBufferArray()            // function to clear buffer array
{
 for (int i=0; i<count;i++)
   buffer[i]=NULL;                 // clear all index of array with command NULL
}
