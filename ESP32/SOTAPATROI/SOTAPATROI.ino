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
#define BEACON_SCAN_TIME 2

// hasieran zenbat milisegundoz izango den beacon bila
#define BEACON_SEARCH_TIME 5000

#define BEACON_MAX_ERROR 2

#define RELAY01 17
#define RELAY02 17

#define RELAY02_TIMEOUT 5000


// scan mota SET/GET
String BEACON_SCAN_TYPE = "SET";

// hasierako zerrendako BLE objetua
BLEScan* BLE;

typedef struct
{ 
    String mac;
    int found;
    int error;
} BEACONS_STRUCT;

BEACONS_STRUCT BEACONS[BEACON_MAX_CLIENTS];

void setup()
{    
    Serial.begin(115200);
    Serial.printf("Sotapatroi 0.2\n");

    int m = millis();

    prepareRelays();
    initBeaconList();
    Serial.printf("Searching beacons:\n");
    while(millis()<m+BEACON_SEARCH_TIME)
    {
        Serial.printf(".");
        getBeaconList();
    }
    Serial.println("");
    if(getBeaconsLength()>0)
        BEACON_SCAN_TYPE = "GET";
    else
        Serial.println("Beacons not found!");
}

void loop()
{
    if(getBeaconsLength()>0)
    {
        resetBeaconList();
        getBeaconList();
        setBeaconError();

        for(int i=0; i<BEACON_MAX_CLIENTS; i++)
        {
            if(BEACONS[i].mac!="")
            {
                Serial.print("mac: ");
                Serial.print(BEACONS[i].mac);
                Serial.print(" - ");
                Serial.print("found: ");
                Serial.print(BEACONS[i].found);
                Serial.print(" - ");
                Serial.print("error: ");
                Serial.print(BEACONS[i].error);
                Serial.println();
            }
        }        

        if(isError())
        {
            Serial.println("Launched RELAY01!");
            digitalWrite(RELAY01, HIGH);
            
            int m = millis();
            Serial.println("Waiting for launch RELAY02...");
            while(millis()<m+RELAY02_TIMEOUT)
            {
                if(millis()%1000==0)
                    Serial.print(".");
                delay(5);
            }
                
            Serial.println("Launched RELAY02!");
            digitalWrite(RELAY02, HIGH);
            while(true)
            {

            }
        }
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
            int beacons_length = getBeaconsLength();
            if(beacons_length<BEACON_MAX_CLIENTS && name.indexOf(BEACON_NAME)!=-1 && getBeaconIndex(mac)==-1)
            {
                BEACONS[beacons_length].mac = mac;
                BEACONS[beacons_length].found = 1;
                BEACONS[beacons_length].error = 0;
            }
        }
        else
        {
            int index = getBeaconIndex(mac);
            if(index>-1)
            {
                BEACONS[index].found = 1;
                BEACONS[index].error = 0;
            }
        }
    }
};

void prepareRelays()
{
    pinMode(RELAY01, OUTPUT);
    digitalWrite(RELAY01, LOW);
    pinMode(RELAY02, OUTPUT);
    digitalWrite(RELAY02, LOW);
}

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

int getBeaconIndex(String mac)
{
    for(int i=0; i<BEACON_MAX_CLIENTS; i++)
    {
        if(BEACONS[i].mac==mac)
            return i;
    }
    return -1;
}

void resetBeaconList()
{
    for(int i=0; i<BEACON_MAX_CLIENTS; i++)
    {
        if(BEACONS[i].mac!="")
            BEACONS[i].found = 0;
    }
}

int getBeaconsLength()
{
    int c = 0;
    for(int i=0; i<BEACON_MAX_CLIENTS; i++)
    {
        if(BEACONS[i].mac!="")
            c++;
    }
    return c;
}

void setBeaconError()
{
    // if mac not found error + 1;
    for(int i=0; i<BEACON_MAX_CLIENTS; i++)
    {
        if(BEACONS[i].mac!="" && BEACONS[i].found==0)
            BEACONS[i].error = BEACONS[i].error+1;
    }
}

bool isError()
{
    bool error = false;
    for(int i=0; i<BEACON_MAX_CLIENTS; i++)
    {
        if(BEACONS[i].mac!="" && BEACONS[i].error >= BEACON_MAX_ERROR)
        {
            error = true;
            Serial.print("Beacon not found: ");
            Serial.print(BEACONS[i].mac);
            Serial.println();
        }
    }
    return error;
}