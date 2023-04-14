#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6g209tSUs"
#define BLYNK_TEMPLATE_NAME "SmartHome"
#define BLYNK_AUTH_TOKEN "0adxztBOc-xTYaTEC47ZlQhpdR_rGHoA"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char ssid [] = "ayen";
char pass [] = "ayen1234";

#include <DHT.h>

BlynkTimer timer;

#define DHTPIN D5 // DHT Digital Input Pin
#define DHTTYPE DHT11 // DHT11 or DHT22, depends on your sensor
#define Buzzer D0 // Buzzer

DHT dht(DHTPIN, DHTTYPE);

float temperature, humidity; // Temp and Humid floats, will be measured by the DHT


void ActiveDHT() {
  // DHT11
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }  

  Serial.println(temperature);
  Blynk.virtualWrite(V0, temperature);  

  if(temperature > 28) {
    digitalWrite(Buzzer, LOW);
    Blynk.virtualWrite(V1, 1);     
  } else {
    digitalWrite(Buzzer, HIGH);
    Blynk.virtualWrite(V1, 0);         
  }

}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin (BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L,ActiveDHT);

  dht.begin();
  pinMode(Buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  Blynk.run();
  timer.run();
}
