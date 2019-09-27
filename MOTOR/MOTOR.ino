#include<AFMotor.h>
AF_DCMotor motor1(1);

void setup()
{
  motor1.setSpeed(255);
}

void loop()
{
  motor1.run(FORWARD);
  delay(5000);
  motor1.run(RELEASE);
  delay(1000);
  motor1.run(BACKWARD);
  delay(5000);
}
