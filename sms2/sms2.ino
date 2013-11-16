void setup()
{
  Serial.begin(19200);  //Baud rate of the GSM/GPRS Module
  Serial.print("\r");
  delay(1000);
  Serial.print("AT+CMGF=1\r");
  delay(1000);
  Serial.print("AT+CMGS=\"+34123456789\"\r");    //Number to which you want to send the sms
  delay(1000);
  Serial.print("Arduino SMS2 Test! \r");   //The text of the message to be sent
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
}
void loop()
{
}
