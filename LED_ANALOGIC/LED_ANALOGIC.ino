const int LED01 = 3;
const int POT = 0;

int BRIGHTNESS;

void setup()
{
  Serial.begin(9600);
  pinMode(LED01, OUTPUT);
  // Ez da beharrezkoa Analogiko denak INPUT-ak direlako
  // pinMode(POT, INPUT);
}

void loop()
{
  BRIGHTNESS = analogRead(POT); // 0 - 1023
  BRIGHTNESS = BRIGHTNESS / 4;
  Serial.print("Potentzia: ");
  Serial.println(BRIGHTNESS);
  analogWrite(LED01, BRIGHTNESS); // 0 - 255
}

