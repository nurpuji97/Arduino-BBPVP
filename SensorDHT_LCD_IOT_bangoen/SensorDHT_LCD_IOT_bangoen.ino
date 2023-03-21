#include "DHT.h"
#include <LCD_I2C.h>

// Define DHT 11
#define DHTPIN D5     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.backlight();

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  // float f = dht.readTemperature(true);

  // LCD
  lcd.setCursor(0, 0); // Or setting the cursor in the desired position.
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.setCursor(0, 1); // Or setting the cursor in the desired position.
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("C");
  delay(1000);
  lcd.clear();
  }
