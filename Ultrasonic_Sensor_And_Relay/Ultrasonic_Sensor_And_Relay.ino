#include <NewPing.h>

#define RELAY_PIN 3
NewPing mySensor(11,12,400);

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() 
{
  int distance = mySensor.ping_cm();
  if (distance > 0 && distance < 50)
  {
    digitalWrite(RELAY_PIN, LOW);
    delay(5000);
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);
  }
  delay(50);
}
