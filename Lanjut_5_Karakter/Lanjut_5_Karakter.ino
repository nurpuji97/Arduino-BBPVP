
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte tas[] = {
  B10101,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010,
  B10101,
  B01010
};

byte piala[] = {
  B11111,
  B11111,
  B11111,
  B01110,
  B00100,
  B00100,
  B01110,
  B11111
};

void setup() {
  lcd.createChar(0, smiley);
  lcd.createChar(1, tas);
  lcd.createChar(2, piala);
  lcd.begin(16, 2);  
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));

  lcd.setCursor(0, 1);
  lcd.print("test");
}

void loop() {}