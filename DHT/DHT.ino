#include <DHT.h>
 
#define DHTPIN 2
#define DHTTYPE DHT22
 
DHT dht(DHTPIN, DHTTYPE);
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
 
  if (isnan(t) || isnan(h))
  {
    Serial.print("Failed to read from DHT");
  }
  else
  {
    Serial.print("Hezetasune:");
    Serial.print(h);
    Serial.println("");
    Serial.print("Tenperaturie:");
    Serial.print(t);    
    Serial.println("");    
    delay(5000);
  }
}
