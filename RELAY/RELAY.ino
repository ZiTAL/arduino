 #define IN1 8
 
 void setup()
 {
   pinMode(IN1, OUTPUT);
   digitalWrite(IN1, LOW);
 }
 
 void loop(){
   digitalWrite(IN1, HIGH);  //Green LED on, Yellow LED off
   delay(500);
   digitalWrite(IN1, LOW);   //Yellow LED on, Green LED off
   delay(500);
 }
