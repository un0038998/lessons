#include <AccelStepper.h>

AccelStepper stepper(AccelStepper::DRIVER, 2, 3);  //StepPin D2 and DirPin D3

void setup()
{  
  stepper.setMaxSpeed(4000);
  stepper.setSpeed(4000);    //One full rotation = 800 steps = 200 steps * 4 (MS1=0, MS2=1, MS3=0)
}

void loop()
{  
  stepper.runSpeed();
}
