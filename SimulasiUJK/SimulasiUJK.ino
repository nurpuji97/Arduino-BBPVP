/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6aJrcCsd0"
#define BLYNK_TEMPLATE_NAME "SimulasiUJK1"
#define BLYNK_AUTH_TOKEN "x51w1nUxyvCJ-4HgYcezcYeqhvksNcKW"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

#define DHTTYPE DHT11
BlynkTimer timer;

#define DHTPIN D1     // Digital pin connected to the DHT sensor
#define Relay1 D5
#define Relay2 D6
#define Togg1 D7
#define Togg2 D8
#define Togg3 D0

DHT dht(DHTPIN, DHTTYPE);

float hum;
float temp;

BLYNK_WRITE(V0){
  int WorkRelay1 = param.asInt();
  digitalWrite(Relay1, WorkRelay1);
}

BLYNK_WRITE(V1){
  int WorkRelay2 = param.asInt();
  digitalWrite(Relay2, WorkRelay2);
}

BLYNK_WRITE(V6){
  int SetPoint = param.asInt();
  if(temp <= SetPoint){
    Blynk.virtualWrite(V8, "Hidup");
  } else {
    Blynk.virtualWrite(V8, "Mati");
  }
  
}

void ReadDHT(){
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  hum = dht.readHumidity();
  // Read temperature as Celsius (the default)
  temp = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(hum) || isnan(temp) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  
   Blynk.virtualWrite(V2, temp);
   Blynk.virtualWrite(V7, hum);

   if(digitalRead(Togg1) == 1){
     Blynk.virtualWrite(V3, 1);     
   } else {
     Blynk.virtualWrite(V3, 0);       
   }

   if(digitalRead(Togg2) == 1){
     Blynk.virtualWrite(V4, 1);     
   } else {
     Blynk.virtualWrite(V4, 0);       
   }

   if(digitalRead(Togg3) == 1){
     Blynk.virtualWrite(V5, 1);     
   } else {
     Blynk.virtualWrite(V5, 0);       
   }

}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, ReadDHT);
  dht.begin();
  pinMode(Relay1, 1);
  pinMode(Relay2, 1);

}

void loop()
{
  Blynk.run();
  timer.run();
}