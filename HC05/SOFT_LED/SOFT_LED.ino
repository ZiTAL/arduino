#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // Bluetooth TX, Bluetooth RX
int LED = 13;
int KEY = 8;
int DATA;

void setup()
{
  digitalWrite(KEY, HIGH);  
  delay(100);
  Serial.begin(9600);
  BT.begin(9600);
  BT.println("Pultsa 1 LED-a biztuteko, Pultsa 0 LED-a amatateko");
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (BT.available())
  {
    DATA = BT.read();
    if(DATA=='1')
    {
      digitalWrite(LED, HIGH);
      BT.println("LED-a biztuta!");
    }
    if(DATA=='0')
    {
      digitalWrite(LED, 0);
      BT.println("LED-a itzalita!");
    }
  }
  delay(100);
}
