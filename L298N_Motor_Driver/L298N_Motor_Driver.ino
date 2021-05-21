int enableAPin = 3;
int in1Pin = 4;
int in2Pin = 5;

void setup()
{
  pinMode(enableAPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
}

void loop()
{
  int motorPWMSpeed = 0;
  int joystickValue = analogRead(A0);   //Joystick gives values ranging from 0 to 1023. So we will consider center value as 512 and lets keep some deadband at center.

  if (joystickValue >= 530)           //This will move motor in forward direction  
  {
    motorPWMSpeed = map(joystickValue, 530, 1023, 0, 255);
    digitalWrite(in1Pin, HIGH);
    digitalWrite(in2Pin, LOW);    
    analogWrite(enableAPin, motorPWMSpeed);
  }
  else if (joystickValue <= 490)      //This will move motor in reverse direction    
  {
    motorPWMSpeed = map(joystickValue, 490, 0, 0, 255);
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);    
    analogWrite(enableAPin, motorPWMSpeed);
  }  
  else                                //Stop the motor
  {
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, LOW);    
  }
}
