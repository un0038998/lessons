#include<Servo.h>

#define ESC_PIN 2

Servo esc;

void setup() 
{
  esc.attach(ESC_PIN,  1000, 2000);
  esc.write(0);
  delay(2000);
}

void loop() 
{
  int joystickValue = analogRead(A0);
  joystickValue = constrain(joystickValue, 550, 1023);  //Read upper half of joystick value from center.
  int mmotorSpeed = map(joystickValue, 550, 1023, 0, 180);
  esc.write(mmotorSpeed);  
}
