#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() 
{
  lcd.begin(16, 2);  
  lcd.clear();  

  lcd.setCursor(0, 0);    //first column, First row 
  lcd.print("Hello All !!");  
  lcd.setCursor(0, 1);   //First column, Second row 
  lcd.print("I am Ujwal");  
}


void loop() 
{
  // Turn off the display:
  lcd.noDisplay();
  delay(1000);
  // Turn on the display:
  lcd.display();
  delay(1000);  
}
