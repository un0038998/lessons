#define SENSOR_PIN 2
#define BUZZER_PIN 3

void setup() 
{
  pinMode(SENSOR_PIN, INPUT);  
  //Serial.begin(9600);
}

void loop() 
{
  //If there is no vibration then the sensor value will be 0 else the value will be 1
  int sensorValue = digitalRead(SENSOR_PIN);
  //Serial.println(sensorValue);
  //There is fire
  if (sensorValue == LOW)
  {
    analogWrite(BUZZER_PIN, 0);
  }
  else
  {
    //If vibration then turn on the buzzer
    analogWrite(BUZZER_PIN, 50);    
  }
  //You can add delay between reading
  delay(100);
} 
