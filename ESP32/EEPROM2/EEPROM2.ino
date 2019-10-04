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
  unsigned long start_time = millis();
  unsigned long end_time;  
  unsigned long current_time;
  
  Serial.begin(115200);
  Serial.print("EEPROM: ");
  Serial.println(start_time);
  
  if (!EEPROM.begin(EEPROM_SIZE))
  {
    Serial.println("failed to initialise EEPROM");
  }
  else
  {
    // write();
    read();

    end_time = millis();
    current_time = end_time - start_time;

    Serial.print("Elapsed time: ");
    Serial.println(current_time);
  }
}

void loop()
{
    
}

void write()
{
    Serial.println("write:");
    for (int i = 0; i < EEPROM_SIZE; i++)
    {
      EEPROM.write(i, 1);
      Serial.println(i);
    } 
    EEPROM.commit();  
}

void read()
{
    Serial.printf("read:");
    for (int i = 0; i < EEPROM_SIZE; i++)
    {
      EEPROM.read(i);
      //Serial.println(i);
    }
    EEPROM.end();  
}