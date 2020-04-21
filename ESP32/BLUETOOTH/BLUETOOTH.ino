#include "Config.h"
#include "Bluetooth.h"

const int BAUD_RATE = 115200;
const int BLUETOOTH_PIN = 0;
const int BLUETOOTH_TIME_WAIT = 4000; // ms

void setup()
{
    // set Serial
    Serial.begin(BAUD_RATE);
    while (!Serial)
    {
    }

    // wait 1 seconds to push button
    int m = millis();
    while(m+1000>millis())
    {
    }    

    // set Config
    Config::setup();

    // wait for Bluetooth button is pressed
    m = millis();
    boolean reset = true;
    boolean config_button_pressed = false;
    while(m+BLUETOOTH_TIME_WAIT>millis())
    {
        if(Bluetooth::isButtonPressed(BLUETOOTH_PIN))
            config_button_pressed = true;
        else
            reset = false;
    }

    if(reset) // if the button is pressed for 5 seconds reset config
    {
        Serial.println("FACTORY RESET");
        Config::factoryReset();
        ESP.restart();
    }
    else if(config_button_pressed)
    {
        Serial.println("Bluetooth CONFIG");
        Bluetooth::setup();
    }
    else // normal
    {
        Serial.println("NORMAL");
    }
}

void loop()
{
    if(Bluetooth::isEnabled()) // Bluetooth bidez Sotapatroi konfiguratu
        Bluetooth::loop(); 
    else // Bestela programa aurrera
    {

    }
}