/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini

   https://github.com/moononournation/Arduino_BLE_Scanner/blob/master/Arduino_BLE_Scanner.ino
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int scanTime = 1; //In seconds
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice daylight)
    {
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
    }
};

void setup()
{
  Serial.begin(115200);

  BLEDevice::init("BLE");
  pBLEScan = BLEDevice::getScan(); //create new scan
  pBLEScan->setAdvertisedDeviceCallbacks(new MyAdvertisedDeviceCallbacks());
  pBLEScan->setActiveScan(true); //active scan uses more power, but get results faster
  pBLEScan->setInterval(100);
  pBLEScan->setWindow(99);  // less or equal setInterval value
}

void loop()
{
  BLEScanResults foundDevices = pBLEScan->start(scanTime, false);
  Serial.print("Devices count: ");
  Serial.print(foundDevices.getCount());
  Serial.println("");
  Serial.println("#########################################");

  // delete results fromBLEScan buffer to release memory
  pBLEScan->clearResults();
}
