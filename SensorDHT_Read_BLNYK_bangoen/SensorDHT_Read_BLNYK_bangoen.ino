/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6KRZ4p2-c"
#define BLYNK_TEMPLATE_NAME "BacaDHT11"
#define BLYNK_AUTH_TOKEN "L-snPEnrGzFAxsFzdVkNH20lR4rMhdzV"


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

// syntax times blnyk
BlynkTimer timer;

// syntax DHT11
DHT dht(DHTPIN, DHTTYPE);
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

float celcius;
float kelembapan;

// DHT11 function
void DHT11Data() {
  // Read temperature as Celsius (the default)
  celcius = dht.readTemperature();
  Blynk.virtualWrite(V0, celcius);

  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  kelembapan = dht.readHumidity();
  Blynk.virtualWrite(V1, kelembapan);
  
  // create strings label
  Blynk.virtualWrite(V2, "Hello Ini Proyek Saya Nur Puji");
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.backlight();
  dht.begin();
  timer.setInterval(1000L, DHT11Data);
}

void loop()
{
  Blynk.run();
  timer.run();

  lcd.setCursor(0, 0); // Or setting the cursor in the desired position.
  lcd.print("L:");
  lcd.print(celcius);
lcd.print(" ");
  lcd.print("h:");
  lcd.print(kelembapan);
  delay(1000);
  lcd.clear();
}

