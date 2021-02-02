#include <NewPing.h>

#define BUZZER_PIN 3
NewPing mySensor(11,12,400);

void setup() 
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() 
{
  int distance = mySensor.ping_cm();
  if (distance > 0 && distance < 50)
  {
    analogWrite(BUZZER_PIN, 50);
  }
  else
  {
    analogWrite(BUZZER_PIN, 0);
  }
  delay(50);
}
