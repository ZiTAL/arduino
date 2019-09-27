int IN1 = 8;
int IN2 = 7;
int ENA = 6;

int ENA_D = 0;
int ENA_V = 175;

int m = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);  
}

void loop()
{
  m = millis();
  if(m%100==0)
  {
    if(ENA_V>=255)
    {
      ENA_V = 0;
      if(ENA_D==0)
      {
        ENA_D = 1;
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);            
        delay(1000);
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);                
      }
      else
      {
        ENA_D = 0;
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);            
        delay(1000);
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);                        
      }
    }
    Serial.print("ENA_D: ");
    Serial.println(ENA_D);
    Serial.print("ENA_V: ");
    Serial.println(ENA_V);

    analogWrite(ENA, ENA_V);
    //ENA_V++;
  }
}
