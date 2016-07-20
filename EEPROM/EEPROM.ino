
#include <EEPROM.h> //Se implementa la librería EEPROM
/*
void setup()
{
  int j = 0;
  for (int i = 0; i < 1024; i++)
  {
    EEPROM.write(i, j);
    if(j==10)
      j=0;
  }
}

void loop()
{
}
*/

byte valor;
 
void setup()
{
  Serial.begin(9600);
/*  
  int j = 1;
  for (int i = 0; i < 1024; i++)
  {
    EEPROM.write(i, j);
    j++;
    if(j>255)
      j = 1;
  }  
*/  
  for (int i = 0; i < 1024; i++)
  {
    int j  = EEPROM.read(i);
    Serial.print(i);
    Serial.print("\t");
    Serial.print(j);
    Serial.print("\t");
    Serial.print((char)j);    
    Serial.println();
  }
}
 
void loop()
{
}
