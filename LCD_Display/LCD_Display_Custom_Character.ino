#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// make heart custom character:
byte heart[] = {
  B00000,
  B00000,
  B01010,
  B10101,
  B10001,
  B10001,
  B01010,
  B00100
};

void setup() 
{
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);
  
  // create a new heart character
  lcd.createChar(0, heart);
  lcd.setCursor(0, 0);

  // Print a message to the lcd.
  lcd.print("I ");
  lcd.write(byte(0)); // when calling lcd.write() '0' must be cast as a byte
  lcd.print(" Arduino! ");

}

void loop() 
{
}
