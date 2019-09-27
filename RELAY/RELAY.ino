/*
Jumper in JD-VCC and VCC PINS or weld it
*/

#define R1 17
#define R2 16
#define R3 27
#define R4 14
 
void setup()
{
  pinMode(R1, OUTPUT);
  digitalWrite(R1, LOW);
  pinMode(R2, OUTPUT);
  digitalWrite(R2, LOW);
  pinMode(R3, OUTPUT);
  digitalWrite(R3, LOW);  
  pinMode(R4, OUTPUT);
  digitalWrite(R4, LOW);  
}
 
void loop()
{
  digitalWrite(R1, HIGH);
  digitalWrite(R2, HIGH);  
  digitalWrite(R3, HIGH);    
  digitalWrite(R4, HIGH);    
  delay(500);
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);  
  digitalWrite(R3, LOW);    
  digitalWrite(R4, LOW);    
  delay(500);
 }
