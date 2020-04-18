#include <EEPROM.h>

class Config
{
    public:
      static void setup();
      static String getBeaconName();

    private:    
        struct CONFIG_STRUCT
        { 
            char BEACON_NAME[128];
            int MAX_CLIENTS;
            int SCAN_TIME;
            int SEARCH_TIME;
            int MAX_ERROR;
            int RELAY1_TIMEOUT;
            int RELAY2_TIMEOUT;
            int FLAG;
        };    
        static Config::CONFIG_STRUCT _info;
        static void setDefault();
        static void getInfo();
        static void save(void *data_source, size_t size);
        static void load(void *data_dest, size_t size);
        static void print();
        static void edit();
};