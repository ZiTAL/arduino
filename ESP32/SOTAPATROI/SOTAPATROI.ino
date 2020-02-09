#include <ArduinoJson.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>

#define APP_NAME "SOTAPATROI"

// beacon-aren izena, etorkizunean "SOTAPATROI"
#define BEACON_NAME "WGX_iBeacon"

// gehienezko beacon kopurua
#define BEACON_MAX_CLIENTS 5

// zenbat denboraz beacon bila segundutan
#define BEACON_SCAN_TIME 1

// hasieran zenbat milisegundoz izango den beacon bila
#define BEACON_SEARCH_TIME 5000

#define BEACON_MAX_ERROR 2

// scan mota SET/GET
String BEACON_SCAN_TYPE = "SET";

// hasierako zerrendako BLE objetua
BLEScan* BLE;

StaticJsonDocument<512> DOC;
JsonArray BEACONS = DOC.createNestedArray("beacons");
JsonObject FOUNDS = DOC.createNestedObject("founds");
JsonObject ERRORS = DOC.createNestedObject("errors");

void setup()
{    
    Serial.begin(115200);
    Serial.printf("Sotapatroi 0.2\n");

    int m = millis();

    initBeaconList();
    Serial.printf("Searching beacons:\n");
    while(millis()<m+BEACON_SEARCH_TIME)
    {
        Serial.printf(".");
        getBeaconList();
    }
    Serial.println("");

    if(BEACONS.size()>0)
    {
        BEACON_SCAN_TYPE = 'GET';
        serializeJsonPretty(DOC, Serial);
    }
    else
        Serial.println("No beacon found!");
}

void loop()
{
    if(BEACONS.size()>0)
    {
        resetBeaconList();
        getBeaconList();
        setErrorBeaconsNotFound();
        if(isError())
        {
            while(true)
            {

            }
        }
        serializeJsonPretty(DOC, Serial);
        Serial.println();
        Serial.println(millis());
    }
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
            if(BEACONS.size()<BEACON_MAX_CLIENTS && name.indexOf(BEACON_NAME)!=-1 && !inJsonArray(mac, BEACONS))
            {
                BEACONS.add(mac);
                ERRORS[mac] = 0;
            }
        }
        else
        {
            if(inJsonArray(mac, BEACONS))
            {
                FOUNDS[mac] = 1;
                ERRORS[mac] = 0;
            }
        }
    }
};

void initBeaconList()
{
    BLEDevice::init(APP_NAME);
    //create new scan
    BLE = BLEDevice::getScan();
    BLE->setAdvertisedDeviceCallbacks(new BLEgetListCallback());
    //active scan uses more power, but get results faster
    BLE->setActiveScan(true);
/*    
    BLE->setInterval(100);
    // less or equal setInterval value
    BLE->setWindow(99);
*/
}

void getBeaconList()
{
    BLEScanResults foundDevices = BLE->start(BEACON_SCAN_TIME, false);
    BLE->clearResults();
}

bool inJsonArray(String str, JsonArray array)
{
    int l = array.size();
    for(int i=0; i<l; i++)
    {
        String v = array[i];
        if(str==v)
            return true;
    }
    return false;
}

void resetBeaconList()
{
    for(int i=0; i<BEACONS.size(); i++)
    {
        String mac = BEACONS[i];
        FOUNDS[mac] = 0;
    }    
}

void setErrorBeaconsNotFound()
{
    // if mac not found error + 1;
    for(int i=0; i<BEACONS.size(); i++)
    {
        String mac = BEACONS[i];
        int c = ERRORS[mac];

        if(FOUNDS[mac]==0)
            ERRORS[mac] = c+1;
    }
}

bool isError()
{
    for(int i=0; i<BEACONS.size(); i++)
    {
        String mac = BEACONS[i];
        int c = ERRORS[mac];

        if(c>BEACON_MAX_ERROR)
            return true;
    }
    return false;
}