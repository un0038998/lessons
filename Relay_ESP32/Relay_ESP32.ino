#define RELAY_PIN 16

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
}

//Switch on/off relay after every 1 seconds. This is low level triggered relay.
//So sending LOW signal will turn on relay and HIGH signal will turn off relay.
void loop() 
{
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);  
}
