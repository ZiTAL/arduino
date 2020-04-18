#include "Config.h"
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
    else if(_read_line.startsWith("AT+BEACON-NAME?"))
    {
        _write_line = Config::getBeaconName();
    }
    else if(_read_line.startsWith("AT+BEACON-NAME="))
    {
        _read_line.replace("AT+BEACON-NAME=", "");
        Config::setBeaconName(_read_line);
        Config::save();
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+MAX-CLIENTS?"))
    {
        int max_clients = Config::getMaxClients();
        _write_line = String(max_clients);
    }
    else if(_read_line.startsWith("AT+MAX-CLIENTS="))
    {
        _read_line.replace("AT+MAX-CLIENTS=", "");
        Config::setMaxClients(_read_line.toInt());
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+SEARCH-TIME?"))
    {
        int max_clients = Config::getMaxClients();
        _write_line = String(max_clients);
    }    
    else if(_read_line.startsWith("AT+SEARCH-TIME="))
    {
        _read_line.replace("AT+SEARCH-TIME=", "");
        Config::setSearchTime(_read_line.toInt());
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+MAX-ERROR?"))
    {
        int max_error = Config::getMaxError();
        _write_line = String(max_error);
    }    
    else if(_read_line.startsWith("AT+MAX-ERROR="))
    {
        _read_line.replace("AT+MAX-ERROR=", "");
        Config::setMaxError(_read_line.toInt());
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+RELAY1?"))
    {
        int relay1 = Config::getRelay1();
        _write_line = String(relay1);
    }    
    else if(_read_line.startsWith("AT+RELAY1="))
    {
        _read_line.replace("AT+RELAY1=", "");
        Config::setRelay1(_read_line.toInt());
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+RELAY2?"))
    {
        int relay2 = Config::getRelay2();
        _write_line = String(relay2);
    }    
    else if(_read_line.startsWith("AT+RELAY2="))
    {
        _read_line.replace("AT+RELAY2=", "");
        Config::setRelay2(_read_line.toInt());
        _write_line = "OK";
    }

    else if(_read_line.startsWith("AT+FACTORY-RESET=1"))
    {
        Config::factoryReset();
        _write_line = "OK";
    }
    else if(_read_line.startsWith("AT+HELP"))
    {
        _write_line = _getHelp();
    }
    else
    {
        _write_line = "COMMAND NOT FOUND, USE THIS FOR HELP\nAT+HELP?";
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

String Bluetooth::_getHelp()
{
    String help = "";
    help += "SOTAPATROI AT COMMAND-LINE TOOL\n";
    help += "****************************************\n";
    help += "AT+BEACON-NAME?\n<String>get Beacon name \n";
    help += "AT+BEACON-NAME=<String>\nset Beacon name\n";
    help += "AT+MAX-CLIENTS?\n<int> get Max Client\n";
    help += "AT+MAX-CLIENTS=<int>\nset Max Clients\n";
    help += "AT+SEARCH-TIME?\n<int> get Search Time\n";
    help += "AT+SEARCH-TIME=<int>\nset Search Time\n";
    help += "AT+MAX-ERROR?\n<int> get Max Error\n";
    help += "AT+MAX-ERROR=<int>\nset Max Error\n";    
    help += "AT+RELAY1?\n<int> get Relay1 Timeout in seconds\n";
    help += "AT+RELAY1=<int>\nset Relay1 Timeout in seconds\n";
    help += "AT+RELAY2?\n<int> get Relay2 Timeout in seconds\n";
    help += "AT+RELAY2=<int>\nset Relay2 Timeout in seconds\n";    
    help += "AT+FACTORY-RESET=1\nreset values to factory defaults\n";

    return help;
}