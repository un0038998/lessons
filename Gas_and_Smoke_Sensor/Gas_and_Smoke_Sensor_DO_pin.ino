#define BUZZER_PIN 3

void setup() 
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() 
{
  int sensorValue = digitalRead(2);
  if (sensorValue == LOW)
  { 
    analogWrite(BUZZER_PIN, 50);
  }
  else
  {
    analogWrite(BUZZER_PIN, 0);    
  }
  delay(1000);
} 
