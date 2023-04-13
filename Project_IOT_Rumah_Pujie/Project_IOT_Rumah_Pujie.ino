#include <LCD_I2C.h>
#include <MQ135.h>


LCD_I2C lcd(0x27, 20, 4); 

#define PIN_MQ135 A2 // MQ135 Analog Input Pin


// #define LDR1 A3

int RELAY1 = 3;
int RELAY2 = 4;
// int RELAY2 = 5;

int nilaiLDR1;


MQ135 mq135_sensor(PIN_MQ135);


void setup() {

 pinMode (RELAY1, OUTPUT);
 pinMode  (RELAY2, OUTPUT);
  // put your setup code here, to run once:
  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.backlight();

  Serial.begin(9600);

  // nama Setup Awal
  lcd.print("Selamat Datang"); // You can make spaces using well... spaces
  lcd.setCursor(0, 0); // Or setting the cursor in the desired position. 
  lcd.print("Kelompok 1 'SmartHome' "); // You can make spaces using well... spaces
  lcd.setCursor(0, 1); // Or setting the cursor in the desired position.     

}

void loop() {  

  // LDR 1
  nilaiLDR1 = analogRead(A3);
  Serial.print("Nilai LDR: ");
  Serial.println(nilaiLDR1); 
  delay(200);

  // if(nilaiLDR1 < 100){
  //   lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
  //   lcd.print("Kondisi: "); // You can make spaces using well... spaces
  //   lcd.print("Gelap"); // You can make spaces using well... spaces

  //   digitalWrite(RELAY1, LOW);
  //   digitalWrite(RELAY2, LOW);

  //   lcd.setCursor(0, 2); // Or setting the cursor in the desired position.
  //   lcd.print("L1: "); // You can make spaces using well... spaces
  //   lcd.print("OFF"); // You can make spaces using well... spaces
    
  //   lcd.setCursor(0, 3); // Or setting the cursor in the desired position.
  //   lcd.print("L2: "); // You can make spaces using well... spaces
  //   lcd.print("OFF"); // You can make spaces using well... spaces
    
  //   lcd.setCursor(0, 4); // Or setting the cursor in the desired position.
  //   lcd.print("L3: "); // You can make spaces using well... spaces
  //   lcd.print("OFF"); // You can make spaces using well... spaces            
  // } else {
  //   lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
  //   lcd.print("Kondisi: "); // You can make spaces using well... spaces
  //   lcd.print("Terang"); // You can make spaces using well... spaces
    
  //   digitalWrite(RELAY1, HIGH);
  //   digitalWrite(RELAY2, HIGH);
      
  //   lcd.setCursor(0, 2); // Or setting the cursor in the desired position.
  //   lcd.print("L1: "); // You can make spaces using well... spaces
  //   lcd.print("ON"); // You can make spaces using well... spaces
    
  //   lcd.setCursor(0, 3); // Or setting the cursor in the desired position.
  //   lcd.print("L2: "); // You can make spaces using well... spaces
  //   lcd.print("ON"); // You can make spaces using well... spaces
    
  //   lcd.setCursor(0, 4); // Or setting the cursor in the desired position.
  //   lcd.print("L3: "); // You can make spaces using well... spaces
  //   lcd.print("ON"); // You can make spaces using well... spaces  
  // } 


  // digitalWrite(RELAY1, LOW);
  // digitalWrite(RELAY2, LOW);  


//   float rzero = mq135_sensor.getRZero();
//   float correctedRZero = mq135_sensor.getCorrectedRZero(temperature, humidity);
//   float resistance = mq135_sensor.getResistance();
//   float ppm = mq135_sensor.getPPM();
//   float correctedPPM = mq135_sensor.getCorrectedPPM(temperature, humidity);

//   Serial.print("MQ135 RZero: ");
//   Serial.print(rzero);
//   Serial.print("\t Corrected RZero: ");
//   Serial.print(correctedRZero);
//   Serial.print("\t Resistance[]: ");
//   Serial.print(resistance);
//   Serial.print("\t PPM: ");
//   Serial.print(ppm);
//   Serial.print("ppm");
//   Serial.print("\t Corrected PPM: ");
//   Serial.print(correctedPPM);
//   Serial.println("ppm"); 
 
  // put your main code here, to run repeatedly:
 
  // lcd.print("L1: "); // You can make spaces using well... spaces
  // lcd.print("ini Statusnya "); // You can make spaces using well... spaces
  // lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
  // lcd.print("L2: "); // You can make spaces using well... spaces
  // lcd.print("ini Statusnya "); // You can make spaces using well... spaces
  // lcd.setCursor(0, 2); // Or setting the cursor in the desired position.
  // lcd.print("L3: "); // You can make spaces using well... spaces
  // lcd.print("ini Statusnya "); // You can make spaces using well... spaces
  // lcd.setCursor(0, 3); // Or setting the cursor in the desired position
  // delay(300);

  // lcd.backlight();  
//  lcd.clear();
//   delay(500);

}
