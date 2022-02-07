#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() 
{
  Serial.begin(9600);
  mlx.begin();
}

void loop() 
{
  float temperature = mlx.readObjectTempC();
  Serial.println(temperature);
  delay(500);
}
