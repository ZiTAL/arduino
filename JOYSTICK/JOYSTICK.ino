// https://www.brainy-bits.com/arduino-joystick-tutorial/

const int X = 0; // arduino analog 0 // joystick X, VRx
const int Y = 1; // arduino analog 1 // joystick Y, VRy
const int B = 2; // arduino digital 2 // joystick KEY, SW

int BV;

void setup()
{
    Serial.begin(9600);
    pinMode(B, INPUT_PULLUP);
}

void loop()
{
    BV = digitalRead(B);
    if(BV==0)
        BV = 1;
    else
        BV = 0;

    Serial.print("Botoia:  ");
    Serial.println(BV);
    Serial.print("X: ");
    Serial.println(analogRead(X));
    Serial.print("Y: ");
    Serial.println(analogRead(Y));
    Serial.println();
    delay(500);
}
