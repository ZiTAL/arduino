#include "Config.h"

Config::CONFIG_STRUCT Config::_instance;

void Config::setup()
{
    load();
    if(_instance.FLAG!=1)
        setDefault();
}

void Config::setDefault()
{
    strcpy(_instance.BEACON_NAME, "WGX_iBeacon");
    _instance.MAX_CLIENTS = 10;
    _instance.SCAN_TIME = 1; // segundo 1
    _instance.SEARCH_TIME = 10 * 1000; // 10 segundo
    _instance.MAX_ERROR = 2;
    _instance.RELAY1 = 0;
    _instance.RELAY2 = 10 * 60 * 1000; // 10 minutu
    _instance.FLAG = 0;
}

void Config::save()
{
    _save(&_instance, sizeof(_instance));
}

void Config::_save(void *data_source, size_t size)
{
    EEPROM.begin(size * 2);
    for(size_t i = 0; i < size; i++)
    {
        char data = ((char *)data_source)[i];
        EEPROM.write(i, data);
    }
    EEPROM.commit();
}

void Config::load()
{
    _load(&_instance, sizeof(_instance));
}

void Config::_load(void *data_dest, size_t size)
{
    EEPROM.begin(size * 2);
    for(size_t i = 0; i < size; i++)
    {
        char data = EEPROM.read(i);
        ((char *)data_dest)[i] = data;
    }
}

String Config::getBeaconName()
{
    String beacon_name = _instance.BEACON_NAME;
    return beacon_name;
}

void Config::setBeaconName(String beacon_name)
{
    beacon_name.toCharArray(_instance.BEACON_NAME, beacon_name.length()+1);
    _instance.FLAG=1;
    save();   
}

void Config::setMaxClients(int max_clients)
{
    _instance.MAX_CLIENTS = max_clients;
    _instance.FLAG=1;
    save();   
}

int Config::getMaxClients()
{
    return _instance.MAX_CLIENTS;
}

void Config::setSearchTime(int search_time)
{
    _instance.SEARCH_TIME = search_time;
    _instance.FLAG=1;
    save();       
}

int Config::getSearchTime()
{
    return _instance.SEARCH_TIME;
}

void Config::setMaxError(int max_error)
{
    _instance.MAX_ERROR = max_error;
    _instance.FLAG=1;
    save();    
}

int Config::getMaxError()
{
    return _instance.MAX_ERROR;
}

void Config::setRelay1(int relay1)
{
    _instance.RELAY1 = relay1;
    _instance.FLAG=1;
    save();        
}

int Config::getRelay1()
{
    return _instance.RELAY1;
}

void Config::setRelay2(int relay2)
{
    _instance.RELAY2 = relay2;
    _instance.FLAG=1;
    save();   
}

int Config::getRelay2()
{
    return _instance.RELAY2;
}

void Config::factoryReset()
{
    setDefault();
    save();
}      