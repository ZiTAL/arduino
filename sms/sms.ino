#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);
 
void setup()
{
  SIM900.begin(19200);
  SIM900power();  
  delay(20000);  // give time to log on to network.
}
 
void SIM900power()
// software equivalent of pressing the GSM shield "power" button
{
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(5000);
}
 
void sendSMS()
{
  SIM900.print("AT+CMGF=1\r");                                                        // AT command to send SMS message
  delay(100);
  SIM900.println("AT + CMGS = \"+34123456789\"");                                     // recipient's mobile number, in international format
  
  delay(100);
  SIM900.println("Hello, world. This is a text message from an Arduino Uno.");        // message to send
  delay(100);
  SIM900.println((char)26);                       // End AT command with a ^Z, ASCII code 26
  delay(100);
  SIM900.println();
  delay(5000);                                     // give module time to send SMS
  SIM900power();                                   // turn off module
}
 
void loop()
{
  sendSMS();
  do {} while (1);
}
