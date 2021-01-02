#include<Servo.h>

#define SERVO_PIN 2
Servo myServo;

void setup() 
{
  myServo.attach(SERVO_PIN); 
}

void loop()
{
  int joystickValue = analogRead(A0);
  int output = map(joystickValue, 0, 1023, 0, 180);
  myServo.write(output);
  delay(10);
}
