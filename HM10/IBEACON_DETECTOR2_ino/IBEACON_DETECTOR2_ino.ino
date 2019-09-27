/*
OK+DISIS
OK+DISC:
4C000215:FDA50693A4E24FB1AFCFC6EB07647825:2733DCB2C5:ED47D2B7B2FF:-057
OK+DISC:
4C000215:FDA50693A4E24FB1AFCFC6EB07647825:2733DCB2C5:D4A48E265664:-053
OK+DISCE
*/

#include <SoftwareSerial.h>
SoftwareSerial BT(7, 8); // 7 Bluetooth TX, 8 Bluetooth RX

String _ibeacons[10][70];

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);  

  if(!isATReady())
  {
    Serial.println("HM10 not ready :(");
    while(true)
    {
    }
  }  
  Serial.println("Sotapatroi: ");
}

void loop()
{
  String response;
  String ibeacon;
  String MAC;
  String POW;
  
  int i = 0;
  int j = 0;
  int len;

  Serial.print("SEGUNDUEK MARTXAN: ");
  Serial.println(millis()/1000);  

  response = getIbeaconList();
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
        MAC = "";
        for(j=53;j<65;j++)
        {
          MAC = MAC + (String)ibeacon[j];
        }
        POW = "";
        for(j=67;j<70;j++)
        {
          POW = POW + (String)ibeacon[j];
        }                
        Serial.print(MAC);
        Serial.print(" ");        
        Serial.println(POW.toInt());
      }
    }
  }
}

boolean isATReady()
{
	String bt_response = "";
	int loops = 100;
	int i = 0;
  
	do
	{
		BT.print("AT");
		delay(10);
		bt_response = getBt();

		if(i==loops)
		{
			BT.flush();
			return false;
		}
		i++;
	}
	while(bt_response!=String("OK"));
  
	BT.flush();
	return true;
}

String getBt()
{
	String response;
	char a;

	if(BT.available())
	{
		while(BT.available())
		{
			a = BT.read();
			response += a;
			delay(1);
		}
	}
	return response;
}

String getIbeaconList()
{
	String response = "";
	BT.flush();
	BT.write("AT+DISI?");
	delay(10);
	//OK+DISISOK+DISC:4C000215:74278BDAB64445208F0C720EAF059935:FFE0FFE1C5:78A5048CECAC:-053OK+DISC:4C000215:74278BDAB64445208F0C720EAF059935:FFE0FFE1C5:78A50485AF2D:-050OK+DISCE
	do
	{
		response += getBt(); 
	}
	while(response.startsWith(String("OK+DISIS"))==true && response.endsWith(String("OK+DISCE"))==false);

	return response;
}
