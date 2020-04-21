#ifndef CONFIG_H
#define CONFIG_H
#include <EEPROM.h>

class Config
{
    public:
      static void setup();
      static void load();
      static void save();
      static void setDefault();
      static void setBeaconName(String beacon_name);
      static String getBeaconName();
      static void setMaxClients(int max_clients);
      static int getMaxClients();
      static void setSearchTime(int search_time);
      static int getSearchTime();
      static void setMaxError(int max_error);
      static int getMaxError();
      static void setRelay1(int relay1);
      static int getRelay1();
      static void setRelay2(int relay2);
      static int getRelay2();      
      static void factoryReset();

    private:    
        struct CONFIG_STRUCT
        { 
            char BEACON_NAME[128];
            int MAX_CLIENTS;
            int SCAN_TIME;
            int SEARCH_TIME;
            int MAX_ERROR;
            int RELAY1;
            int RELAY2;
            int FLAG;
        };    
        static Config::CONFIG_STRUCT _instance;
        static void _save(void *data_source, size_t size);
        static void _load(void *data_dest, size_t size);
};

#endif