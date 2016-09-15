int time;
int start;

void setup()
{
  // ikusteko zelan nahiz eta 3 segundu itxaron 0-tik hasten da kontaten
  delay(3000);
  Serial.begin(9600);
  start = millis();  
  time = 0;
}

void loop()
{
  time = (millis() - time - start) / 1000;
  Serial.println(time);
}
