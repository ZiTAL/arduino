/*Note: this code is a demo for how to using gprs shield to send sms message, dial a voice call and 
 send a http request to the website, upload data to pachube.com by TCP connection,

 The microcontrollers Digital Pin 7 and hence allow unhindered
 communication with GPRS Shield using SoftSerial Library. 
 IDE: Arduino 1.0 or later
 Replace the following items in the code:
 1.Phone number, don't forget add the country code
 2.Replace the Access Point Name
 3. Replace the Pachube API Key with your personal ones assigned
 to your account at cosm.com
 */
#include <SoftwareSerial.h>
#include <String.h>
SoftwareSerial mySerial(7, 8);
void setup()
{
 mySerial.begin(19200);               // the GPRS baud rate   
 Serial.begin(19200);    // the GPRS baud rate 
 delay(500);
 SendTextMessage();
}
void loop()
{
}
///SendTextMessage()
///this function is to send a sms message
void SendTextMessage()
{
 mySerial.print("AT+CMGF=1\r");    //Because we want to send the SMS in text mode
 delay(100);
 mySerial.println("AT + CMGS = \"+34123456789\"");//send sms message, be careful need to add a country code before the cellphone number
 delay(100);
 mySerial.println("Arduino SMS3 Test!");//the content of the message
 delay(100);
 mySerial.println((char)26);//the ASCII code of the ctrl+z is 26
 delay(100);
 mySerial.println();
}
