#include "Bluetooth.h"

void BluetoothCallback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param)
{
    Bluetooth::callback(event, param);
}

boolean Bluetooth::_enabled;
BluetoothSerial Bluetooth::_serial;
String Bluetooth::_callback;
String Bluetooth::_read_line;
String Bluetooth::_write_line;

void Bluetooth::setup()
{
    _serial.register_callback(BluetoothCallback);
    _serial.begin("SOTAPATROI");

    _callback = ""; 
}

void Bluetooth::loop()
{
    if(_callback=="onConnect")
        Bluetooth::onConnect();
    else if(_callback=="onWriteStart")
        Bluetooth::onWriteStart();
    else if(_callback=="onReceivedStart")
        Bluetooth::onReceivedStart();
}

void Bluetooth::callback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param)
{
    if(_callback=="")
    {
        if(event == ESP_SPP_DATA_IND_EVT)          // DATA RECEIVED
            _callback = "onReceivedStart";
    }
    else
        Bluetooth::clearBuffer();

    if(event == ESP_SPP_SRV_OPEN_EVT)               // CONNECTION STABLISHED
        _callback = "onConnect";

    else if(event == ESP_SPP_CLOSE_EVT)             // CONNECTION CLOSED
    {
        _enabled = false;
        ESP.restart();
    }
}

boolean Bluetooth::isButtonPressed(int pin)
{
    if(digitalRead(pin)==LOW)
        _enabled = true;
    else
        _enabled = false;    

    return _enabled;
}

boolean Bluetooth::isEnabled()
{
    return _enabled;
}

void Bluetooth::onConnect()
{
    _callback = "";
/*    
    _write_line = "SOTAPATROI CONFIG TOOL\n*****************************";
    _callback = "onWriteStart";
*/
}

void Bluetooth::onReceivedStart()
{
    if(_serial.available())
    {
        byte b = byte(_serial.read());
        if(b!=10 && b!=13) // \r \n
            _read_line = _read_line + char(b);
    }
    else
        Bluetooth::onReceivedEnd();
}

void Bluetooth::onReceivedEnd()
{
    Bluetooth::clearBuffer();
    if(_read_line=="AT")
    {
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+BEACON_NAME?"))
    {
        _write_line = Config::getBeaconBame(); // HAU EZ DABIL
    }
    else if(_read_line.startsWith("AT+BEACON_NAME="))
    {
        _read_line.replace("AT+BEACON_NAME=", "");
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+RESET"))
    {
    }
    else if(_read_line.startsWith("AT+HELP"))
    {
        _write_line = "HELP...";
    }
    else if(_read_line.startsWith("AT+RESTART"))
    {
        _enabled = false;
    }
    else
    {
        _write_line = "AT+HELP? for HELP";
    }
    _callback = "onWriteStart";
}

void Bluetooth::onWriteStart()
{
    if(_write_line!="")
    {
        _serial.print(_write_line[0]);
        _write_line.remove(0, 1);
    }
    else
    {
        _serial.println();
        Bluetooth::onWriteEnd();
    }
}

void Bluetooth::onWriteEnd()
{
    _read_line = "";
    _write_line = "";
    _callback = "";
}

void Bluetooth::clearBuffer()
{
    while(_serial.available())
        _serial.read();
}