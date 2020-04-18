#include "Config.h"

Config::CONFIG_STRUCT Config::_info;

void Config::setup()
{
    load();
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
    _info.RELAY1 = 0;
    _info.RELAY2 = 10 * 60 * 1000; // 10 minutu
    _info.FLAG = 0;
}

void Config::save()
{
    _save(&_info, sizeof(_info));
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
    _load(&_info, sizeof(_info));
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
    String beacon_name = _info.BEACON_NAME;
    return beacon_name;
}

void Config::setBeaconName(String beacon_name)
{
    beacon_name.toCharArray(_info.BEACON_NAME, beacon_name.length()+1);
    _info.FLAG=1;
    save();   
}

void Config::setMaxClients(int max_clients)
{
    _info.MAX_CLIENTS = max_clients;
    _info.FLAG=1;
    save();   
}

int Config::getMaxClients()
{
    return _info.MAX_CLIENTS;
}

void Config::setSearchTime(int search_time)
{
    _info.SEARCH_TIME = search_time;
    _info.FLAG=1;
    save();       
}

int Config::getSearchTime()
{
    return _info.SEARCH_TIME;
}

void Config::setMaxError(int max_error)
{
    _info.MAX_ERROR = max_error;
    _info.FLAG=1;
    save();    
}

int Config::getMaxError()
{
    return _info.MAX_ERROR;
}

void Config::setRelay1(int relay1)
{
    _info.RELAY1 = relay1;
    _info.FLAG=1;
    save();        
}

int Config::getRelay1()
{
    return _info.RELAY1;
}

void Config::setRelay2(int relay2)
{
    _info.RELAY2 = relay2;
    _info.FLAG=1;
    save();   
}

int Config::getRelay2()
{
    return _info.RELAY2;
}

void Config::factoryReset()
{
    setDefault();
    save();
}      