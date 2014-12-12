/*
SIM900 Junperrak Hardware moduan jarri
RX: SIM900 0 -> Arduino 0
TX: SIM900 1 -> Arduino 1
SIM900 9 -> Arduino 9
*/

void setup()
{
  SIM900power();
  Serial.begin(19200);
  Serial.println();
  delay(5000);
  Serial.println("ATD + +34123456789;"); // deitsu
  delay(15000);
  Serial.println("ATH"); // eskei
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
