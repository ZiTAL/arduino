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
#define BEACON_ADDRESS_LENGTH 19
// zenbat denboraz beacon bila segundutan
#define BEACON_SCAN_TIME 1
// hasieran zenbat milisegundoz izango den beacon bila
#define BEACON_SET_SCAN_TIME 5000

// scan mota SET/GET
String BEACON_SCAN_TYPE = "SET";

// hasierako zerrendako BLE objetua
BLEScan* BLE;

// hasierako beacon zerrenda
int BEACON_SET_INDEX = 0;
// Zenbat beacon izango ditugun gehienez eta beacon bakoitzaren helbidearen tamaina
char BEACON_SET_LIST[BEACON_MAX_CLIENTS][BEACON_ADDRESS_LENGTH];

// loop-eko beacon zerrenda
int BEACON_GET_INDEX = 0;
// Zenbat beacon izango ditugun gehienez eta beacon bakoitzaren helbidearen tamaina
char BEACON_GET_LIST[BEACON_MAX_CLIENTS][BEACON_ADDRESS_LENGTH];

void setup()
{    
    Serial.begin(115200);
    Serial.printf("Sotapatroi 0.2\n");

    int m = millis();

    // Hasieran lortutako beacon-ak zerrendan sartu: BEACON_SET_LIST
    BEACON_SCAN_TYPE = "SET";
    initBeaconList();
    Serial.printf("Searching beacons:\n");
    while(millis()<m+BEACON_SET_SCAN_TIME)
    {
        Serial.printf(".");
        getBeaconList();
    }
    Serial.println("");

    printArray(BEACON_SET_LIST);
    Serial.printf("Device count: %d\n", BEACON_SET_INDEX);

    BEACON_SCAN_TYPE = "GET";
}

void loop()
{
    for(int i=0; i<BEACON_MAX_CLIENTS; i++)
    {
      String b = "                  ";
      b.toCharArray(BEACON_GET_LIST[i], BEACON_ADDRESS_LENGTH);
    }
    BEACON_GET_INDEX = 0;
    getBeaconList();

    printArray(BEACON_GET_LIST);
    Serial.printf("Device count: %d\n", BEACON_GET_INDEX);    
}

class BLEgetListCallback: public BLEAdvertisedDeviceCallbacks
{
    void onResult(BLEAdvertisedDevice beacon)
    {
        String mac = beacon.getAddress().toString().c_str();
        String name = "";
        if(beacon.haveName())
            name = beacon.getName().c_str();

        if(BEACON_SCAN_TYPE=="SET")
        {
            if(BEACON_SET_INDEX<BEACON_MAX_CLIENTS && name.indexOf(BEACON_NAME)!=-1 && !inArray(mac, BEACON_SET_LIST))
            {
                mac.toCharArray(BEACON_SET_LIST[BEACON_SET_INDEX], BEACON_ADDRESS_LENGTH);
                BEACON_SET_INDEX++;
            }
        }
        else
        {
            Serial.println(mac);
            if(BEACON_GET_INDEX<BEACON_MAX_CLIENTS && name.indexOf(BEACON_NAME)!=-1 && !inArray(mac, BEACON_GET_LIST))
            {
                mac.toCharArray(BEACON_GET_LIST[BEACON_GET_INDEX], BEACON_ADDRESS_LENGTH);
                BEACON_GET_INDEX++;
            }
        }
    }
};

void initBeaconList()
{
    BLEDevice::init("BLE_LIST");
    //create new scan
    BLE = BLEDevice::getScan();
    BLE->setAdvertisedDeviceCallbacks(new BLEgetListCallback());
    //active scan uses more power, but get results faster
    BLE->setActiveScan(true);
    BLE->setInterval(100);
    // less or equal setInterval value
    BLE->setWindow(99);
}

void getBeaconList()
{
    BLEScanResults foundDevices = BLE->start(BEACON_SCAN_TIME, false);
    BLE->clearResults();
}

int printArray(char array[BEACON_MAX_CLIENTS][BEACON_ADDRESS_LENGTH])
{
    int count = 0;
    String obj = "";
    for(int i=0; i<sizeof(array); i++)
    {
        obj = String(array[i]);
        obj.trim();
        if(obj!="")
            Serial.println(obj);
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

/*
char resetArray(char array[BEACON_MAX_CLIENTS][BEACON_ADDRESS_LENGTH])
{
    for(int i=0; i<sizeof(array); i++)
    {
        String b = "";
        for(int j=0; j<sizeof(array[i]); j++)
            b = b + " ";
        b.toCharArray(array[i], BEACON_ADDRESS_LENGTH);
    }
    return array;
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

void stopSetBeaconList()
{
    BLE->stop();
}
*/