#include "Bluetooth.h"

void BluetoothCallback(esp_spp_cb_event_t event, esp_spp_cb_param_t *param)
{
    if(event == ESP_SPP_SRV_OPEN_EVT)               // CONNECTION STABLISHED
    {
        Bluetooth::setCallback("onConnect");
    }
    else if(event == ESP_SPP_CLOSE_EVT)             // CONNECTION CLOSED
    {
        // ESP.restart();
        // setup();
    }
    else if(event == ESP_SPP_DATA_IND_EVT)          // DATA RECEIVED
    {
        Bluetooth::setCallback("onReceivedStart");
    }
}

Bluetooth::Bluetooth()
{
}

BluetoothSerial Bluetooth::_serial;
String Bluetooth::_callback;
String Bluetooth::_read_line;
String Bluetooth::_write_line;
String Bluetooth::_beacon_name;

void Bluetooth::init()
{
    _callback = "";
    _read_line = "";
    _write_line = "";
    _beacon_name = "SOTAPATROI";

    _serial.register_callback(BluetoothCallback);
    _serial.begin("SOTAPATROI");    
}

void Bluetooth::setCallback(String callback)
{
    _callback = callback;
}

String Bluetooth::getCallback()
{
    return _callback;
}

void Bluetooth::onConnect()
{
    _write_line = "SOTAPATROI CONFIG TOOL";
    Bluetooth::setCallback("onWriteStart");
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
    {
        Bluetooth::onReceivedEnd();
    }
}

void Bluetooth::onReceivedEnd()
{
    if(_read_line == "AT")
    {
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+BEACON_NAME?"))
    {
        _write_line = _beacon_name;
    }
    else if(_read_line.startsWith("AT+BEACON_NAME="))
    {
        _read_line.replace("AT+BEACON_NAME=", "");
        _beacon_name = _read_line;
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+RESET"))
    {
    }
    else if(_read_line.startsWith("AT+HELP?"))
    {
        _write_line = "HELP...";
    }
    else
    {
        _write_line = "AT+HELP? for HELP";
    }

    Bluetooth::setCallback("onWriteStart");
}

void Bluetooth::onWriteStart()
{
    if(_write_line!="")
    {
        _serial.print(_write_line[0]);
        _write_line.remove(0, 1);
        if(_write_line=="")
            _serial.println();
    }
    else
        Bluetooth::onWriteEnd();
}

void Bluetooth::onWriteEnd()
{
    _read_line = "";
    _write_line = "";
    Bluetooth::setCallback("");
}