/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL65NUrueJ-"
#define BLYNK_TEMPLATE_NAME "Latihan2IOT"
#define BLYNK_AUTH_TOKEN "hJLzbD5xTo-r-E1n2aX89T5aXb8qBiiE"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#include <LCD_I2C.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";


// Define DHT 11
#define DHTPIN D5     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
#define Buzzer D0 // Pin Buzzer

// syntax times blnyk
BlynkTimer timer;

// syntax DHT11
DHT dht(DHTPIN, DHTTYPE);
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

float celcius;
float kelembapan;
bool setActive, setBuzzer;
int setPoint;
int maxCelcius, minCelcius;

BLYNK_WRITE(V4){
  int active = param.asInt();
  if(active == 1){
    setActive = 1;
    setBuzzer = 1;

  } else {
    setActive = 0;
    setBuzzer = 0;
  }
}

BLYNK_WRITE(V3){
  minCelcius = celcius - 08.00;
  maxCelcius = celcius + 08.00;   

  if(setActive == 1){
    setPoint = param.asInt();
    // Buzzer Bunyi
    if(setPoint >= minCelcius && setPoint <= maxCelcius){
      digitalWrite(Buzzer, HIGH);    
    } else {
      digitalWrite(Buzzer, LOW); 
    }
  } else {
    setPoint = 2;
    digitalWrite(Buzzer, LOW);
  }

}

void SensorDHT11(){
  // create strings label
  Blynk.virtualWrite(V0, "Hello Ini Proyek Nur Puji");

  // Read temperature as Celsius (the default)
  celcius = dht.readTemperature();
  Blynk.virtualWrite(V1, celcius);

  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  kelembapan = dht.readHumidity();
  Blynk.virtualWrite(V2, kelembapan);

 }


void setup() {
  // put your setup code here, to run once:
  
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(Buzzer, OUTPUT);

  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.backlight();
  dht.begin();
  timer.setInterval(1000L, SensorDHT11);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();

  lcd.setCursor(0, 0); // Or setting the cursor in the desired position.
  lcd.print("t:");
  lcd.print(celcius);
  lcd.print("  ");
  lcd.print("h:");
  lcd.print(kelembapan);
  lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
  lcd.print("s:");
  lcd.print(setPoint);
  lcd.print(" ");
  lcd.print("e:");
  if(setActive == 1 && setBuzzer == 1){
      lcd.print("ON");
  } else {
      lcd.print("OFF");    
  }  
  lcd.print(" ");
  lcd.print("b:");
    if(setActive == 1 && setBuzzer == 1){
      lcd.print("ON");
  } else {
      lcd.print("OFF");    
  }  
  lcd.print(" ");
  delay(1000);
  lcd.clear();
}
