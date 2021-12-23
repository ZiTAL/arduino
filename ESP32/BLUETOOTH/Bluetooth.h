#include "Config.h"
#include "BluetoothSerial.h"

class Bluetooth
{
    public:
      static void setup();
      static void loop();
      static void callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param);
      static boolean isButtonPressed(int pin);
      static boolean isEnabled();

    private:
      static BluetoothSerial _serial;

      static boolean _enabled;
      static String _callback;
      static String _read_line;
      static String _write_line;

      static void onConnect();

      static void onReceivedStart();
      static void onReceivedEnd();

      static void onWriteStart();
      static void onWriteEnd();

      static void clearBuffer();

      static String _getHelp();
};