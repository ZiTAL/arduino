/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini

   https://github.com/moononournation/Arduino_BLE_Scanner/blob/master/Arduino_BLE_Scanner.ino
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int MAX_CLIENTS = 10;
int SCAN_TIME = 1; //In seconds
char BEACONS[10][18];
int INDEX = 0;
BLEScan* BLE_SCAN;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice d)
    {
      String address = d.getAddress().toString().c_str();
      address.toCharArray(BEACONS[INDEX], 18);
      INDEX++;
/*      
      Serial.printf("Device: %s \n", d.toString().c_str());
      Serial.printf("Address: %s \n", d.getAddress().toString().c_str());

      if(d.haveName())
        Serial.printf("Name: %s \n", d.getName().c_str());

      if(d.haveAppearance())
        Serial.printf("Appearance: %d \n", (int)d.getAppearance());

      if(d.haveManufacturerData())
      {
        std::string md = d.getManufacturerData();
        uint8_t *mdp = (uint8_t *)d.getManufacturerData().data();
        char *pHex = BLEUtils::buildHexData(nullptr, mdp, md.length());
        Serial.printf("ManufacturerData: %s \n", pHex);
        free(pHex);
      }

      if(d.haveServiceUUID())
        Serial.printf("ServiceUUID: %s \n", d.getServiceUUID().toString().c_str());

      if(d.haveTXPower())
        Serial.printf("TxPower: %d \n", (int)d.getTXPower());

      Serial.println("-----------------------------------------");
*/      
    }
};

void setup()
{
  Serial.begin(115200);

  BLEDevice::init("BLE");
  BLE_SCAN = BLEDevice::getScan(); //create new scan
  BLE_SCAN->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  BLE_SCAN->setActiveScan(true); //active scan uses more power, but get results faster
  BLE_SCAN->setInterval(100);
  BLE_SCAN->setWindow(99);  // less or equal setInterval value
}

void loop()
{
  int m = millis();
  BLEScanResults foundDevices = BLE_SCAN->start(SCAN_TIME, false);

  // delete results fromBLEScan buffer to release memory
  BLE_SCAN->clearResults();

  Serial.print("Time on:");
  Serial.print(m);
  Serial.println("");
  Serial.println("Devices list: ");
  for(int i=0; i<10; i++)
  {
      String a = BEACONS[i];
      if(a!="")
        Serial.println(a);
      a = "";
      a.toCharArray(BEACONS[i], 18);
  }  
  INDEX = 0;

  Serial.print("Devices count: ");
  Serial.print(foundDevices.getCount());
  Serial.println("");
  Serial.println("#########################################");  
}
