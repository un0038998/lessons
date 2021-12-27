#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::DRIVER, 2, 3);  //StepPin D2 and DirPin D3

void setup()
{  
  stepper.setMaxSpeed(4000);
}

void loop()
{  
  int potValue = analogRead(A0);
  if (potValue < 100 ) potValue = 0;
  int stepperMotorSpeed = map(potValue, 0, 1023, 0, 4000);
  
  stepper.setSpeed(stepperMotorSpeed);  
  stepper.runSpeed();
 
}
