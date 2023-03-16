// include the library code:
#include <LiquidCrystal.h>

const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:

// tampilkan led 0
  lcd.setCursor(0, 0);
  lcd.print("ADC 0 : ");
  lcd.setCursor(8, 0);
  lcd.print(analogRead(A0));
  lcd.print(" ");

  // tampilkan led 1
  lcd.setCursor(0, 1);
  lcd.print("ADC 1 : ");
  lcd.setCursor(8, 1);
  lcd.print(analogRead(A1));
  lcd.print(" ");
  
}
