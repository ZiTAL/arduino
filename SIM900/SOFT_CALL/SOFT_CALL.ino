/*
SIM900 Junperrak Software moduan jarri

Pinak:
SIM900 7 -> Arduino 7
SIM900 7 -> Arduino 7
SIM900 9 -> Arduino 9
*/

#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 8);

void setup()
{
  SIM900power();
  SIM900.begin(19200);
  SIM900.println();
  delay(5000);
  SIM900.println("ATD + +34123456789;"); // deitsu
  delay(15000);
  SIM900.println("ATH"); // eskei
  SIM900power();
}

void loop()
{
}
// Software bidez biztu/amata
void SIM900power()
{
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
  delay(5000);
}
