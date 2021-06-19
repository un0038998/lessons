#define BUZZER_PIN 3

void setup() 
{
  pinMode(BUZZER_PIN, OUTPUT);
  //Serial.begin(9600);
}

void loop() 
{
  int sensorValue = analogRead(A0);
  //Serial.println(sensorValue);
  if (sensorValue > 200)
  {
    analogWrite(BUZZER_PIN, 50);
  }
  else
  {
    analogWrite(BUZZER_PIN, 0);    
  }
  delay(1000);
} 
