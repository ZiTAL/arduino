#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

// LCD
#define I2C_ADDR    0x27  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7
LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

// PIR Sensorie 2 PIN digitalien
int motion_1 = 2;

// Hasikerako konfiguraziñue
void setup()
{
  // LCD
  lcd.begin(20, 4, LCD_5x8DOTS); 
  lcd.setBacklightPin(BACKLIGHT_PIN, POSITIVE); // init the backlight
  lcd.setBacklight(HIGH);

  // PIR Sensorie
  pinMode (motion_1, INPUT);  
}

// Buelta bakotzan eingo dana
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
