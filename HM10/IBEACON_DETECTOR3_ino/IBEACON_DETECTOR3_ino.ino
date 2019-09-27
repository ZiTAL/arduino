/*
OK+DISIS
OK+DISC:
4C000215:FDA50693A4E24FB1AFCFC6EB07647825:2733DCB2C5:ED47D2B7B2FF:-057
OK+DISC:
4C000215:FDA50693A4E24FB1AFCFC6EB07647825:2733DCB2C5:D4A48E265664:-053
OK+DISCE
*/

char IBEACONS[100][12];
int POWERS[100][3];

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  String response;
  String ibeacon;
  char MAC[13];
  char POW[4];
  
  int i = 0;
  int j = 0;
  int z = 0;
  int len;
  
  response = "OK+DISISOK+DISC:4C000215:FDA50693A4E24FB1AFCFC6EB07647825:2733DCB2C5:ED47D2B7B2FF:-057OK+DISC:4C000215:FDA50693A4E24FB1AFCFC6EB07647825:2733DCB2C5:D4A48E265664:-053OK+DISCE";
  len = response.length();

  for(i=0;i<len;i++)
  {
    // OK+DISC:
    if((String)response[i]==(String)"O" && (String)response[i+1]==(String)"K" && (String)response[i+2]==(String)"+" && (String)response[i+3]==(String)"D"
      && (String)response[i+4]==(String)"I" && (String)response[i+5]==(String)"S" && (String)response[i+6]==(String)"C" && (String)response[i+7]==(String)":")
    {
      i = i+8;
      ibeacon = "";
      for(j=0;j<70;j++)
      {
        ibeacon = ibeacon + (String)response[i];
        i++;
      }
      i--;
      if(ibeacon.length()==70)
      {
        z = 0;
        for(j=53;j<65;j++)
        {
          MAC[z] = (char)ibeacon[j];
          z++;
        }
        z = 0;
        for(j=67;j<70;j++)
        {
          POW[z] = (char)ibeacon[j];
          z++;
        }
        Serial.println((String)MAC);
        Serial.println((String)POW);        
      }
    }
  }
}
