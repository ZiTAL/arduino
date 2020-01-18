/*
   Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleScan.cpp
   Ported to Arduino ESP32 by Evandro Copercini

   https://github.com/moononournation/Arduino_BLE_Scanner/blob/master/Arduino_BLE_Scanner.ino
*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

// beacon-aren izena, etorkizunean "SOTAPATROI"
#define BEACON_NAME "WGX_iBeacon"

// gehienezko beacon kopurua
#define BEACON_MAX_CLIENTS 5
// beacon-aren karaktere kopurua
#define BEACON_ADDRESS_LENGTH 18
// zenbat denboraz beacon bila segundutan
#define BEACON_SCAN_TIME 1
// hasieran zenbat milisegundoz izango den beacon bila
#define BEACON_SET_SCAN_TIME 5000

// beacon zerrenda
int BEACON_SET_INDEX = 0;
// Zenbat beacon izango ditugun gehienez eta beacon bakoitzaren helbidearen tamaina
char BEACON_SET_LIST[BEACON_MAX_CLIENTS][BEACON_ADDRESS_LENGTH];

// hasierako zerrendarako 
BLEScan* BLE_SET_LIST;

// momentuko zerrendarako (hasierakoarekin alderatzeko)
BLEScan* BLE_GET_LIST;

void setup()
{    
    Serial.begin(115200);
    Serial.printf("Sotapatroi 0.2\n");

    int m = millis();
    // Hasieran lortutako beacon-ak zerrendan sartu: BEACON_SET_LIST
    setBeaconListInit();
    Serial.printf("Searching beacons:\n");
    while(millis()<m+BEACON_SET_SCAN_TIME)
    {
        Serial.printf(".");
        setBeaconList();
    }
    Serial.println("");
    BLE_SET_LIST->stop();

    printArray(BEACON_SET_LIST);
    Serial.printf("Device count: %d", BEACON_SET_INDEX);
}

void loop()
{
}

class BLEsetListCallback: public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice beacon)
    {
        String mac = beacon.getAddress().toString().c_str();
        String name = "";
        if(beacon.haveName())
            name = beacon.getName().c_str();

        if(BEACON_SET_INDEX<BEACON_MAX_CLIENTS && name.indexOf(BEACON_NAME)!=-1 && !inArray(mac, BEACON_SET_LIST))
        {
            mac.toCharArray(BEACON_SET_LIST[BEACON_SET_INDEX], BEACON_ADDRESS_LENGTH);
            BEACON_SET_INDEX++;
        }
    }
};

void setBeaconListInit()
{
    BLEDevice::init("BLE_SET_LIST");
    //create new scan
    BLE_SET_LIST = BLEDevice::getScan();
    BLE_SET_LIST->setAdvertisedDeviceCallbacks(new BLEsetListCallback());
    //active scan uses more power, but get results faster
    BLE_SET_LIST->setActiveScan(true);
    BLE_SET_LIST->setInterval(100);
    // less or equal setInterval value
    BLE_SET_LIST->setWindow(99);

    BEACON_SET_INDEX = 0;
}

void setBeaconList()
{
    BLEScanResults foundDevices = BLE_SET_LIST->start(BEACON_SCAN_TIME, false);
    BLE_SET_LIST->clearResults();
}

int printArray(char array[BEACON_MAX_CLIENTS][BEACON_ADDRESS_LENGTH])
{
    int count = 0;
    for(int i=0; i<sizeof(array); i++)
    {
        String obj = array[i];
        if(obj!="")
            Serial.println(obj);
    }
    return count;
}

int arrayLength(char array[BEACON_MAX_CLIENTS][BEACON_ADDRESS_LENGTH])
{
    int count = 0;
    for(int i=0; i<sizeof(array); i++)
    {
        String obj = array[i];
        if(obj!="")
            count++;
    }
    return count;    
}

bool inArray(String str, char array[BEACON_MAX_CLIENTS][BEACON_ADDRESS_LENGTH])
{
    for(int i=0; i<sizeof(array); i++)
    {
        String b = array[i];
        if(str==b)
            return true;
    }
    return false;
}