#include "Bluetooth.h"

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
    }
    Bluetooth::init();
}

void loop()
{
    String callback = Bluetooth::getCallback();
    if(callback=="onConnect")
    {
        Bluetooth::onConnect();
    }
    else if(callback=="onWriteStart")
    {
        Bluetooth::onWriteStart();
    }    
    else if(callback=="onReceivedStart")
    {
        Bluetooth::onReceivedStart();
    }
}