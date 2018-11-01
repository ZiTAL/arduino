// Mandotik bidaliko dudan testu baten simulazioa

int b01 = 0; // botoi 01
int p01 = 0; // posizio 01
int b02 = 0; // botoi 02
int p02 = 0; // posizio 02

void setup()
{
  Serial.begin(9600);
}


void loop()
{ 
  String datas = "0:-255:0:-255";
  int datasl = datas.length() + 1;
  
  char data[datasl];
  
  datas.toCharArray(data, datasl);
  int n = sscanf(data, "%d:%d:%d:%d", &b01, &p01, &b02, &p02);

  if(Serial.availableForWrite())
  {
    Serial.print(b01);
    Serial.print(":");
    Serial.print(p01);
    Serial.print(":");
    Serial.print(b02);
    Serial.print(":");
    Serial.print(p02);
    Serial.println();
  }
}