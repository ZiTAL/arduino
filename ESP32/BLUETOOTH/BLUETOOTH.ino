#include "Config.h"
#include "Bluetooth.h"

const int BAUD_RATE = 115200;
const int BLUETOOTH_PIN = 0;
const int BLUETOOTH_TIME_WAIT = 2000; // ms

void setup()
{
    // set Serial
    Serial.begin(BAUD_RATE);
    while (!Serial)
    {
    }

    // set Config
    Config::setup();

    // wait for Bluetooth button is pressed
    int m = millis();
    boolean config_button_pressed = false;
    while(m+BLUETOOTH_TIME_WAIT>millis())
    {
        if(Bluetooth::isButtonPressed(BLUETOOTH_PIN))
            config_button_pressed = true;
    }

    if(config_button_pressed)
        Bluetooth::setup();
}

void loop()
{
    if(Bluetooth::isEnabled()) // Bluetooth bidez Sotapatroi konfiguratu
        Bluetooth::loop(); 
    else // Bestela programa aurrera
    {

    }
}