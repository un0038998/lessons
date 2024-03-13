#include <ESP32Servo.h>

#define X_AXIS_PIN 33
#define SERVO_PIN 16

Servo myServo;

void setup() 
{
  myServo.attach(SERVO_PIN); 
}
 
void loop() 
{
  int joystickValue = analogRead(X_AXIS_PIN);
  int output = map(joystickValue, 0, 4095, 0, 180);
  myServo.write(output);
  delay(10);
}
