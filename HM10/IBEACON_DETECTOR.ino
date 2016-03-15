#include <SoftwareSerial.h>
SoftwareSerial BT(7, 8);    // 7 Bluetooth TX, 8 Bluetooth RX

void setup()
{   
	unsigned int total_fail = 0;
	unsigned int fail = 0;
	unsigned int loops = 0;
	float result;
  
	String ibeacon_list;
	String my_ibeacon = ":123B6A1A4E60:-";
  
	BT.begin(9600);
	Serial.begin(9600);

	if(isATReady())
	{
		Serial.println("HM10 Bluetooth module ready :)");    
		while(true)
		{
			loops++;
			ibeacon_list = getIbeaconList();
			BT.flush();

			if(ibeacon_list.indexOf(my_ibeacon)!=-1)
			{
				fail = 0;
			}
			else
			{
				fail++;
				total_fail++;
			}
			result = (float)total_fail * 100 / loops;
			Serial.println(ibeacon_list);
			Serial.print("iBeacon: ");
			Serial.println(my_ibeacon);
			Serial.print("SEGUNDUEK MARTXAN: ");
			Serial.println(millis()/1000);
			Serial.print("LOOP: ");
			Serial.println(loops);            
			Serial.print("FAIL SEGIDUEK: ");
			Serial.println(fail);
			Serial.print("FAIL DANETARA: ");
			Serial.println(total_fail);
			Serial.print("FAIL %: ");
			Serial.println(result, 4);
			Serial.println("-----------------------------------");              
		}
	}
	else
	{
		Serial.println("HM10 Bluetooth module is not ready :(");
	}
}

void loop()
{
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
