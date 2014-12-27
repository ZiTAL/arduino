const int LED01 = 3;
const int SENSOR = 0;

int BRIGHTNESS;

void setup()
{
  Serial.begin(9600);
  pinMode(LED01, OUTPUT);
  // Ez da beharrezkoa Analogiko denak INPUT-ak direlako
  // pinMode(SENSOR, INPUT);
}

void loop()
{
  BRIGHTNESS = analogRead(SENSOR); // 0 - 1023
  BRIGHTNESS = BRIGHTNESS / 4; // 0 - 255 eskalaratu
  BRIGHTNESS = 255 - BRIGHTNESS; // alderantzizkatu
  Serial.print("Argitasuna: ");
  Serial.println(BRIGHTNESS);
  analogWrite(LED01, BRIGHTNESS); // 0 - 255
}

