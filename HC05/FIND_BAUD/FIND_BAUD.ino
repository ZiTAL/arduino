#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); // Bluetooth TX -> Arduino RX, Bluetooth RX -> Arduino TX
int LED = 13;
int DATA;
int KEY = 8;

void setup()
{
  pinMode(KEY, OUTPUT); // AT komanduek sartzieko  
  pinMode(LED, OUTPUT);  
  Serial.begin(115200);
  findBaud();
}

void loop()
{
}

void findBaud()
{
    digitalWrite(KEY, HIGH); // AT komanduek sartzieko biztu
    delay(100);

    int recvd = 0;
    int _bufsize;
    char _buffer[32];

    _bufsize = sizeof(_buffer)/sizeof(char);
    
    for(long i = 0; i < 2147483648; i++)
    {
        BT.begin(i);
        BT.setTimeout(100);
        Serial.print("Saiatzen ");
        Serial.print(i);
        Serial.print("...");
        BT.write("AT\r\n");
        recvd = BT.readBytes(_buffer, _bufsize);
        if (recvd > 0)
        {
            Serial.println("Topatuta.");
            digitalWrite(LED, HIGH);            
            digitalWrite(KEY, LOW);
            break;
        }
        else
        {
            Serial.println("x");
        }
    }
    digitalWrite(KEY, LOW);    
}
