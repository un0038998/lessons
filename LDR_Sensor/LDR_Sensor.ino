#define SENSOR_PIN 2
#define RELAY_PIN 3

void setup() 
{
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(SENSOR_PIN, INPUT);  
  //Serial.begin(9600);
}

void loop() 
{
  //If there is no light then the sensor value will be 1 else the value will be 0
  int sensorValue = digitalRead(SENSOR_PIN);
  //Serial.println(sensorValue);
  //Its dark
  if (sensorValue == HIGH)
  {
    digitalWrite(RELAY_PIN, LOW);  //Relay is low level triggered relay so we need to write LOW to switch on the light
  }
  else
  {
    digitalWrite(RELAY_PIN, HIGH);    
  }
  //You can add delay for getting good light settled reading depending upon need
  delay(1000);
} 
