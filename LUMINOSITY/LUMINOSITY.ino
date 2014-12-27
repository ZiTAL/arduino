int VAL;
int SENSOR = 0;
     
void setup()
{
  Serial.begin(9600);
}
     
void loop()
{
  VAL = analogRead(SENSOR);
  Serial.println(VAL);
}
