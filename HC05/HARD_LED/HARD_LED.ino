// Bluetooth RX -> Arduino D1 TX
// Bluetooth TX -> Arduino D0 RX

int LED = 13;
int DATA;

void setup()
{
  Serial.begin(9600);
  Serial.println("Pultsa 1 LED-a biztuteko, Pultsa 0 LED-a amatateko");
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (Serial.available())
  {
    DATA = Serial.read();
    if(DATA=='1')
    {
      digitalWrite(LED, HIGH);
      Serial.println("LED-a biztuta!");
    }
    if(DATA=='0')
    {
      digitalWrite(LED, 0);
      Serial.println("LED-a itzalita!");
    }
  }
  delay(100);
}
