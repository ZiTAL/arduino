#include "Config.h"

Config::CONFIG_STRUCT Config::_info;

void Config::setup()
{
    getInfo();
    if(_info.FLAG!=1)
        setDefault();
}

void Config::setDefault()
{
    //strcpy(_info.BEACON_NAME, "SOTAPATROI");
    strcpy(_info.BEACON_NAME, "WGX_iBeacon");
    _info.MAX_CLIENTS = 10;
    _info.SCAN_TIME = 1; // segundo 1
    _info.SEARCH_TIME = 10 * 1000; // 10 segundo
    _info.MAX_ERROR = 2;
    _info.RELAY1_TIMEOUT = 0;
    _info.RELAY2_TIMEOUT = 10 * 60 * 1000; // 10 minutu
    _info.FLAG = 0;
}

void Config::getInfo()
{
    load(&_info, sizeof(_info));
}

void Config::save(void *data_source, size_t size)
{
    EEPROM.begin(size * 2);
    for(size_t i = 0; i < size; i++)
    {
        char data = ((char *)data_source)[i];
        EEPROM.write(i, data);
    }
    EEPROM.commit();
}

void Config::load(void *data_dest, size_t size)
{
    EEPROM.begin(size * 2);
    for(size_t i = 0; i < size; i++)
    {
        char data = EEPROM.read(i);
        ((char *)data_dest)[i] = data;
    }
}

void Config::print()
{
    Serial.println(_info.BEACON_NAME);
    Serial.println(_info.MAX_CLIENTS);
    Serial.println(_info.SCAN_TIME);
    Serial.println(_info.MAX_ERROR);
    Serial.println(_info.RELAY1_TIMEOUT);
    Serial.println(_info.RELAY2_TIMEOUT);
}

void Config::edit()
{
    strcpy(_info.BEACON_NAME, "SOTAPATROI2");   
    _info.FLAG = 1;
    save(&_info, sizeof(_info));
}

String Config::getBeaconName()
{
    String beacon_name = _info.BEACON_NAME;
    return beacon_name;
}