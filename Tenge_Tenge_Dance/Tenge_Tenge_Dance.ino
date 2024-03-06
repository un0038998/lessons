#include <Wire.h>
#include <LiquidCrystal_I2C.h>

byte FirstPositionHead[] = {
  0b00000,
  0b00000,
  0b00100,
  0b01110,
  0b11111,
  0b11111,
  0b01110,
  0b00100
};

byte FirstPositionLeg1[] = {
  0b00100,
  0b11111,
  0b10101,
  0b00100,
  0b00100,
  0b01110,
  0b01010,
  0b11011
};

byte FirstPositionLeg2[] = {
  0b11111,
  0b10101,
  0b00100,
  0b00100,
  0b00100,
  0b01110,
  0b10001,
  0b10001
};


byte SecondPositionHead1[] = {
  0b00000,
  0b00000,
  0b00110,
  0b01111,
  0b01111,
  0b01111,
  0b00110,
  0b00010
};

byte SecondPositionHead2[] = {
  0b00000,
  0b00000,
  0b01100,
  0b11110,
  0b11110,
  0b11110,
  0b01110,
  0b00010
};

byte SecondPositionLeg1[] = {
  0b11110,
  0b10110,
  0b11010,
  0b01010,
  0b00010,
  0b11110,
  0b10100,
  0b10100
};

byte SecondPositionLeg2[] = {
  0b00010,
  0b11110,
  0b11110,
  0b01010,
  0b00010,
  0b01110,
  0b01010,
  0b01010
};

int positionMan = 0;

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  // create a new character
  lcd.createChar(0, FirstPositionHead);
  lcd.createChar(1, FirstPositionLeg1);
  lcd.createChar(2, FirstPositionLeg2);

  // create a new character
  lcd.createChar(3, SecondPositionHead1);
  lcd.createChar(4, SecondPositionLeg1);
  lcd.createChar(5, SecondPositionHead2);  
  lcd.createChar(6, SecondPositionLeg2);

  
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

long long timeStamp = 0;
bool flipDance = true;

void loop() 
{
  if (millis() - timeStamp > 10000)
  {
    flipDance = !flipDance;
    timeStamp = millis();
  }
  if (flipDance)
  {

    lcd.clear();
    lcd.setCursor(8, 0);
    lcd.write(byte(0)); 
    lcd.setCursor(8, 1);
    lcd.write(byte(1)); 
    delay(200);
  
    lcd.clear();
    lcd.setCursor(8, 0);
    lcd.write(byte(0)); 
    lcd.setCursor(8, 1);
    lcd.write(byte(2)); 
    delay(200);
  }
  else
  {
    lcd.clear();
    lcd.setCursor(8, 0);
    lcd.write(byte(3)); 
    lcd.setCursor(8, 1);
    lcd.write(byte(4)); 
    delay(200);
  
    lcd.clear();
    lcd.setCursor(8, 0);
    lcd.write(byte(5)); 
    lcd.setCursor(8, 1);
    lcd.write(byte(6)); 
    delay(200);
  }
}
