#include <NewPing.h>
#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>

#define BUZZER_PIN 5
#define CUT_OFF_TEMPERATURE 25  //This is temperature in degreeC
#define DISTANCE_TO_CHECK 10    //This is in cm

NewPing ultrasonicSensor(2,3,400);  //Ultrasonic sensor pins
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  lcd.begin(16, 2);  
  lcd.clear();  
  
  analogWrite(BUZZER_PIN, 0);
  mlx.begin();
}

void tempHighTone() 
{ 
  for (int i = 0; i < 10; i++)
  {
    analogWrite(BUZZER_PIN,100);
    delay(100);
    analogWrite(BUZZER_PIN,0);
    delay(100);  
  }      
}

void tempOkTone() 
{ 
  analogWrite(BUZZER_PIN, 100);
  delay(2000);
  analogWrite(BUZZER_PIN, 0);
}

void loop() 
{
  String displayString;
  lcd.setCursor(0, 0);
  lcd.print("Check Temp"); 
  
  int distance = ultrasonicSensor.ping_cm();
  if (distance > 0 && distance < DISTANCE_TO_CHECK)
  {
    delay(2000);
    float temperature = mlx.readObjectTempC();
    distance = ultrasonicSensor.ping_cm();
    if (distance > 0 && distance < DISTANCE_TO_CHECK && temperature <= CUT_OFF_TEMPERATURE)
    {
      displayString = displayString + "Temp OK : " + int(temperature);
      lcd.clear();  
      lcd.setCursor(0, 0); 
      lcd.print(displayString);   lcd.print((char)223);  lcd.print("C");         
      tempOkTone();
      delay(2000);
      lcd.clear();  
    }
    else if ( !(distance > 0 && distance < DISTANCE_TO_CHECK))
    {
    }
    else
    {
      displayString = displayString + "Temp HIGH : " + int(temperature);  
      lcd.clear();  
      lcd.setCursor(0, 0); 
      lcd.print(displayString); lcd.print((char)223); lcd.print("C");         
      tempHighTone();
      delay(2000);
      lcd.clear();  
    }
  }
}
