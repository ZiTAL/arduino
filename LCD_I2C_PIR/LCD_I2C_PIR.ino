//DFRobot.com
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 516,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

// PIR Sensorie 2 PIN digitalien
int motion_1 = 2;

void setup()
{
  lcd.init();
  lcd.backlight();
  
  // PIR Sensorie
  pinMode (motion_1, INPUT);   
}

void loop()
{
    // LCD resetie
    lcd.clear();
    lcd.setCursor(0, 0);
 
    // PIR Sensorie leidu
    int sensor_1 = digitalRead(motion_1);
 
    if (sensor_1 == HIGH)
      lcd.print("Mobidu");     
    else    
      lcd.print("Geldik");
       
    // 100 milisegundoko deskantsue :D
    delay(100);  
}
