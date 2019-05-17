/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

int scanTime = 1; //In seconds
BLEScan* pBLEScan;

class MyAdvertisedDeviceCallbacks: public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice advertisedDevice)
    {
      Serial.printf("Device: %s \n", advertisedDevice.toString().c_str());
    }
};

void setup()
{
  Serial.begin(115200);

  BLEDevice::init("SOTAPATROI");
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
  Serial.println("----------------");
  Serial.print(foundDevices.getCount());

  // delete results fromBLEScan buffer to release memory
  pBLEScan->clearResults();
}
