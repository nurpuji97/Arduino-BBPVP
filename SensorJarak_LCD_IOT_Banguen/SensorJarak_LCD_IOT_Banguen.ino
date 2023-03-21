#include <LCD_I2C.h>

#define trigPin D6
#define echoPin D5
long durasi;
int jarak;

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

void setup() {
    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // kode sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi * 0.034/2;

  
  // LCD
  lcd.setCursor(0, 0); // Or setting the cursor in the desired position.
  lcd.print("Jarak Sensor: ");
  lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
  lcd.print(jarak);
  lcd.print("CM");
  delay(1000);
  lcd.clear();

  

}
