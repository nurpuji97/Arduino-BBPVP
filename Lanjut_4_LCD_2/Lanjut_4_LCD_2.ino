#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

}

uint8_t Welcome(String terserah){
  String test = terserah;

    for(int i = 0; i<test.length(); i++){
    lcd.setCursor(i,0);
    lcd.print(test[i]);
    delay(1000);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  lcd.clear();
  Welcome("Saya");
  
}