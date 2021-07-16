#define SENSOR_PIN 2

unsigned long previousTime = millis();

void setup() 
{
  pinMode(SENSOR_PIN , INPUT);
  Serial.begin(9600);
}

int samples = 0;
void loop() 
{
  int currentValue = digitalRead(SENSOR_PIN);
  if (currentValue == LOW)
  {
    samples++;
  }

  if (millis() - previousTime >= 25)
  {
    Serial.println(samples);
    previousTime = millis();
    samples = 0;
  }
}
