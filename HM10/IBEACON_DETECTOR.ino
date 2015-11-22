#include <SoftwareSerial.h>
SoftwareSerial BT(7, 8);    // 7 Bluetooth TX, 8 Bluetooth RX

void setup()
{
  String ibeacon_list;
  String my_ibeacon = "DISC:4C000215:74278BDAB64445208F0C720EAF059935:FFE0FFE1C5:78A5048CECAC";
  
  BT.begin(9600);
  Serial.begin(9600);
  
  if(isATReady())
  {
    Serial.println("Ready");
    while(true)
    {
      ibeacon_list = getIbeaconList();
      BT.flush();
      Serial.println(ibeacon_list);
      Serial.println("iBeacon: 4C000215:74278BDAB64445208F0C720EAF059935:FFE0FFE1C5:78A5048CECAC");
      if(ibeacon_list.indexOf(my_ibeacon)!=-1)
      {
        Serial.println("ABANTE!");
      }
      else
      {
        Serial.println("Deskonektata! Erreliek salta!!!");
        while(true)
        {
          // do nothing
        }
      }
      delay(500);
    }
  }
  else
  {
    Serial.println("Not ready :(");
  }
}

void loop()
{
}

boolean isATReady()
{
  String bt_response = "";
  int loops = 10;
  int i = 0;
  
  do
  {
    BT.print("AT");
    delay(1);
    bt_response = getBt();
    delay(10);

    if(i==loops)
    {
      BT.flush();
      return false;
    }
    i++;
  }
  while(bt_response!=String("OK"));
  
  BT.flush();

  if(i<loops)
    return true;
  else
    return false;
}

String getIbeaconList()
{
  String response;
  BT.flush();
  BT.write("AT+DISI?");
  delay(10);
/*
  Response example:
  OK+DISISOK+DISC:4C000215:74278BDAB64445208F0C720EAF059935:FFE0FFE1C5:78A5048CECAC:-053OK+DISC:4C000215:74278BDAB64445208F0C720EAF059935:FFE0FFE1C5:78A50485AF2D:-050OK+DISCE
*/
  do
  {
    response += getBt();
    delay(10);    
  }
  while(response.startsWith(String("OK+DISIS"))==true && response.endsWith(String("OK+DISCE"))==false);

  return response;
}

String getBt()
{
  String response;
  char a;

  if (BT.available())
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
