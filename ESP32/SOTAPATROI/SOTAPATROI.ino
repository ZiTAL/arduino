/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini
*/

#include <EEPROM.h>
#include <ArduinoJson.h>

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#define R1 17

String BEACON = "6f:ef:c0:f4:c9:98";
char BEACONS[2][18] = {"40:6a:d6:0e:c5:6c", "40:6a:d6:0e:c5:6c"};
bool FOUND = false;

int SCAN_TIME = 1; //In seconds
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice advertisedDevice)
    {
      String response = advertisedDevice.toString().c_str();
      if(response.indexOf(BEACON)!=-1)
        FOUND = true;
      //Serial.printf("Device: %s \n", response);
    }
};

void setup()
{
  Serial.begin(115200);

  pinMode(R1, OUTPUT);
  digitalWrite(R1, LOW);

  BLEDevice::init("SOTAPATROI");
  pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  pBLEScan->setInterval(50);
  pBLEScan->setWindow(49);  // less or equal setInterval value
}

void loop()
{
  FOUND = false;
  BLEScanResults foundDevices = pBLEScan->start(SCAN_TIME, false);
  if(FOUND==false)
  {
    digitalWrite(R1, HIGH);
    Serial.println("Beacon disconnected");
    while(true)
    {

    }
  }
  else
  {
    Serial.println("Beacon found!");
  }
  
    
/*
  Serial.print("Devices count: ");
  Serial.print(foundDevices.getCount());
  Serial.println("");
  Serial.println("----------------");

  // delete results fromBLEScan buffer to release memory
*/  
  pBLEScan->clearResults();
}
