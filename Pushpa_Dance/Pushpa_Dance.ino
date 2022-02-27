#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte head[] = {
  B00000,
  B00000,  
  B01110,
  B11111,
  B11111,
  B01110,
  B00100,
  B00100
};

byte straightLeg[] = {
  B00100,
  B11111,
  B10101,
  B00100,
  B00100,
  B01010,
  B01010,
  B01010
};

byte rightLeg[] = {
  B00111,
  B11101,
  B10100,
  B00100,
  B00111,
  B00101,
  B01001,
  B10001
};

byte leftLeg[] = {
  B11100,
  B10111,
  B00101,
  B00100,
  B11100,
  B10100,
  B10010,
  B10001
};

byte chappalPosition[] = {
  B00100,
  B11111,
  B10101,
  B00100,
  B00100,
  B01110,
  B01010,
  B11011
};

int positionMan = 0;

void setup() 
{
  // initialize LCD and set up the number of columns and rows:
  lcd.begin(16, 2);
  
  // create a new heart character
  lcd.createChar(0, head);
  lcd.createChar(1, straightLeg);
  lcd.createChar(2, rightLeg);
  lcd.createChar(3, leftLeg);
  lcd.createChar(4, chappalPosition);  
  

  lcd.print("Hi");
  lcd.setCursor(0, 0);
  lcd.write(byte(0)); 
  lcd.setCursor(0, 1);
  lcd.write(byte(1)); 
  
  lcd.setCursor(1, 0);
  lcd.write(byte(0)); 
  lcd.setCursor(1, 1);
  lcd.write(byte(2));   
    
}

void loop() 
{

  for (int i = 0; i < 9; i++)
  {
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.write(byte(0)); 
    lcd.setCursor(i, 1);
    lcd.write(byte(1)); 
    delay(500);
  
    i++;
    
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.write(byte(0)); 
    lcd.setCursor(i, 1);
    lcd.write(byte(2)); 
    delay(700);  
 
  }    

  for (int  i = 0; i <= 4; i++)
  {
    lcd.setCursor(9, 1);
    lcd.write(byte(4));
    delay(500)  ;
    lcd.setCursor(9, 1);
    lcd.write(byte(1));
    delay(500)  ;    
  } 

  for (int i = 9; i >= 0; i--)
  {
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.write(byte(0)); 
    lcd.setCursor(i, 1);
    lcd.write(byte(1)); 
    delay(500);
  
    i--;
    
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.write(byte(0)); 
    lcd.setCursor(i, 1);
    lcd.write(byte(3)); 
    delay(700);  
  } 
       
}
