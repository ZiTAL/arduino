#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 516,2);
 
#define DHTPIN 2

#define DHTTYPE DHT22
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup()
{
  lcd.init(); 
  lcd.backlight();
  dht.begin();
  Serial.begin(9600);
}
 
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  if (isnan(t) || isnan(h))
  {
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("Failed to read from DHT");
  }
  else
  {
    lcd.clear();
    lcd.setCursor (0,0);
    lcd.print("Hez:");
    lcd.print(h);
    Serial.print("Hezetasune:");
    Serial.print(h);
    Serial.println("");
    lcd.setCursor (0,1);
    lcd.print("Tenp:");
    lcd.print(t);
    Serial.print("Tenperaturie:");
    Serial.print(t);    
    Serial.println("");    
    delay(5000);
  }
}
