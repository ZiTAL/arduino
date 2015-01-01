#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // Bluetooth TX -> Arduino RX / Bluetooth RX -> Arduino TX
int KEY = 8;

void setup()
{
  // HC05 KEY pine biztu bidu AT komanduek sartzieko
  pinMode(KEY, OUTPUT);
  digitalWrite(KEY, HIGH);
  delay(100);
  Serial.begin(9600);
  Serial.println("Sartun AT komanduek:");
  BT.begin(9600);
}

void loop()
{
  if (BT.available())
    Serial.write(BT.read());

  if (Serial.available())
    BT.write(Serial.read());
}
