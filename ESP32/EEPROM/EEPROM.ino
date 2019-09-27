/*
   EEPROM Write

   Stores random values into the EEPROM.
   These values will stay in the EEPROM when the board is
   turned off and may be retrieved later by another sketch.
*/

#include "EEPROM.h"

// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int addr = 0;
#define EEPROM_SIZE 4096
void setup()
{
  Serial.begin(115200);
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM"); delay(1000000);
  }

  // Write
  Serial.println("EEPROM: Write start");
  for (int i = 0; i < EEPROM_SIZE; i++)
  {
    Serial.print(i);Serial.println(": 1");
    EEPROM.write(i, 1);
  }
  EEPROM.commit();
  Serial.println("EEPROM: Write end");  

  // Read  
  Serial.println("EEPROM: Read start");
  for (int i = 0; i < EEPROM_SIZE; i++)
  {
    Serial.print(i);Serial.print(": ");
    Serial.println(byte(EEPROM.read(i)));
  }
  Serial.println("EEPROM: Read end");
  EEPROM.end();
}

void loop()
{
    
}
