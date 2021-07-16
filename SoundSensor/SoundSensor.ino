#define SENSOR_PIN 2
#define RELAY_PIN 3

int previousValue = HIGH;
int clapCount = 0;
unsigned long previousTime = millis();
bool relayOutPut = HIGH;

void setup() 
{
  pinMode(SENSOR_PIN , INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  //Turn off relay . Relay is LOW level triggered relay
  digitalWrite(RELAY_PIN, HIGH);
}


void loop() 
{
  int currentValue = digitalRead(SENSOR_PIN);
  if (previousValue == HIGH && currentValue == LOW)
  {
    if (clapCount == 1 &&  millis() - previousTime >= 500)
    {
      clapCount = 0;
    }
    
    if (clapCount == 0)
    {
      previousTime = millis();
    }
    clapCount++;

    if (clapCount == 2)
    {
      relayOutPut = !relayOutPut;
      digitalWrite(RELAY_PIN, relayOutPut);
      clapCount = 0;          
    }
    delay(200);    
  }
  previousValue = currentValue;
}
