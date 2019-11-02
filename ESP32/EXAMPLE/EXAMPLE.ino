char BEACONS[2][18] = {"40:6a:d6:0e:c5:6c", "72:a9:84:52:ce:90"};

void setup()
{
  Serial.begin(115200);
  for(int i=0; i<2; i++)
  {
      String a = BEACONS[i];
      Serial.println(a);
  }
}

void loop()
{

}