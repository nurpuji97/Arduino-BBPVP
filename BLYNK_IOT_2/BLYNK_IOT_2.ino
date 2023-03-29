/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6HqQbFuP6"
#define BLYNK_TEMPLATE_NAME "Counter"
#define BLYNK_AUTH_TOKEN "U6SRDM519PFUbC9Skq_ndg9ZHs5KV8kF"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

// BlynkTimer timer;

int counter;

BLYNK_CONNECTED(){
  Blynk.syncAll();  
}

BLYNK_WRITE(V0){
  int increment = param.asInt();
  if(increment == 1){
    counter++;
  }
  Blynk.setProperty(V0, "color", "#D3435C");
  Blynk.virtualWrite(V2, counter);
}

BLYNK_WRITE(V1){
  int Decrement = param.asInt();
  if(Decrement == 1){
    counter--;
  }
  Blynk.setProperty(V1, "color", "#D3435C");
  Blynk.virtualWrite(V2, counter);
}

void TextCount(){
  Blynk.virtualWrite(V2, counter);
} 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
