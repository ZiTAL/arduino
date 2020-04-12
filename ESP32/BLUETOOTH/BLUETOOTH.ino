#include "Bluetooth2.h"

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
    }
    Bluetooth::setup();
}

void loop()
{
    Bluetooth::loop();
}