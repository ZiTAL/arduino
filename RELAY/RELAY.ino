/*
Jumper in JD-VCC and VCC PINS or weld it
*/

#define IN1 8
 
void setup()
{
  pinMode(IN1, OUTPUT);
  digitalWrite(IN1, LOW);
}
 
void loop()
{
  digitalWrite(IN1, HIGH);
  delay(500);
  digitalWrite(IN1, LOW);
  delay(500);
 }
