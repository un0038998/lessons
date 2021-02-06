#define RELAY_PIN 3
void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
}

//Switch on/off relay after every 5 seconds. This is low level triggered relay.
//So sending LOW signal will turn on relay and HIGH signal will turn off relay.
void loop() 
{
  digitalWrite(RELAY_PIN, LOW);
  delay(5000);
  digitalWrite(RELAY_PIN, HIGH);
  delay(5000);  
}
