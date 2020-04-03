#include "BluetoothSerial.h"

class Bluetooth
{
    public:
      static void init();

      static void setCallback(String callback);
      static void onConnect();
      static void onReceivedStart();
      static void onReceivedEnd();
      static void onWriteStart();
      static void onWriteEnd();
      static String getCallback();

    private:
      static BluetoothSerial _serial;
      static String _read_line;
      static String _write_line;
      static String _beacon_name;
      static String _callback;
      Bluetooth();
};