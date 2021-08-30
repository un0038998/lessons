#include <LiquidCrystal.h>

#define SENSOR_PIN 2
#define LED_PIN 3

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  lcd.begin(16, 2);  
  lcd.clear();  

  lcd.setCursor(0, 0);    //first column, First row 
  lcd.print("Test");      //Dummy  print.
}


void loop() 
{
  lcd.setCursor(0, 0);    //first column, First row 
  lcd.clear(); 
  if (digitalRead(SENSOR_PIN) == LOW)
  {
    lcd.print("Tilt Detected");  
    digitalWrite(LED_PIN, HIGH);
  }
  else
  {
    lcd.print("Not tilted");      
    digitalWrite(LED_PIN, LOW);    
  }
  delay(500);
}
