#define SENSOR_PIN 2
#define BUZZER_PIN 3
#define RELAY_PIN 4
#define SPRINKLER_START_DELAY 5000  //5 seconds 
#define SPRINKLER_ON_TIME 3000      //3 seconds Sprinkler on time

unsigned long previousTime = millis();

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);  
}

void loop() 
{
  //If there is fire then the sensor value will be LOW else the value will be HIGH
  int sensorValue = digitalRead(SENSOR_PIN);

  //There is fire
  if (sensorValue == LOW)
  {
    analogWrite(BUZZER_PIN, 50);                          //Turn on buzzer

    if (millis() - previousTime > SPRINKLER_START_DELAY)  //We will wait for few seconds before sprinkler can be started once fire is detected.
    {
      digitalWrite(RELAY_PIN, LOW);                       //Relay is low level triggered relay so we need to write LOW to switch on the light 
      delay(SPRINKLER_ON_TIME);                           //Keep sprinkler on for sometime.
    }
  }
  else
  {
    analogWrite(BUZZER_PIN, 0);    
    digitalWrite(RELAY_PIN, HIGH); 
    previousTime = millis();  
  }
} 
