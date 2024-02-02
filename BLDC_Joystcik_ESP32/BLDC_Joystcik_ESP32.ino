#include <ESP32Servo.h>

#define X_AXIS_PIN 33
#define ESC_PIN 16

Servo esc;

void setup() 
{
  esc.attach(ESC_PIN,  1000, 2000);
  esc.write(0);
  delay(2000);  
  Serial.begin(9600);

}
 
void loop() 
{
  int joystickValue = analogRead(X_AXIS_PIN);
  joystickValue = constrain(joystickValue, 2200, 4095);  //Read upper half of joystick value from center.
  int mmotorSpeed = map(joystickValue, 2200, 4095, 0, 180);
  esc.write(mmotorSpeed); 
  Serial.println(mmotorSpeed); 
}
