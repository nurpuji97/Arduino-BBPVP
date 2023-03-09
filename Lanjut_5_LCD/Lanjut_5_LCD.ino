#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String welcome = "Selamat Datang";

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);

}

//uint8_t TextRuuning(){
//
//    for(int i = 0; i<=17; i++){
//      lcd.setCursor(i,0);
//      lcd.print("Selamat Datang");
//      //lcd.scrollDisplayRight();
//      delay(500);
//      lcd.clear();
//    }
//  
//    for(int j = 17; j>=0; j--){
//       lcd.setCursor(j,1);
//      lcd.print("Di BBPVP Bekasi");
//      //lcd.scrollDisplayLeft();
//      delay(500); 
//    }
//
//}


void loop() {
  // put your main code here, to run repeatedly:
  
//  TextRuuning();


  lcd.clear();
  
  for(int i = 0; i<14; i++){
    lcd.setCursor(i,0);
    lcd.print(welcome[i]);
    delay(1000);
  }

//
//  lcd.setCursor(1,0);
//  lcd.print("e");
//  delay(500);
//
//  lcd.setCursor(2,0);
//  lcd.print("l");
//  delay(500);
    
  
//  lcd.clear();
//  delay(1000);
//  
//  lcd.setCursor(0,0);
//  lcd.print("Selamat Belajar");
//  lcd.setCursor(0,1);
//  lcd.print("Tetap Semangat");
//  lcd.scrollDisplayRight();
//  delay(1000);
//
//  lcd.clear();
//  delay(6000);
}
