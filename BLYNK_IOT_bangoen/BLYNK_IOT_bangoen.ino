/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6pK0aOLZW"
#define BLYNK_TEMPLATE_NAME "testLed"
#define BLYNK_AUTH_TOKEN "ELai_QB2m3dllo3F3XHlbIskbIyZjOW4"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define ledHijau D0 //led Hijau
#define ledMerah1 D1 //led Merah
#define ledMerah2 D2 //led Merah
#define relay D5 //relay

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BLYNK_WRITE(V0){
  int ledHi = param.asInt();
  digitalWrite(ledHijau, ledHi);
}

BLYNK_WRITE(V1){
  int ledmerah1 = param.asInt();
  digitalWrite(ledMerah1, ledmerah1);
}

BLYNK_WRITE(V2){
  int ledmerah2 = param.asInt();
  digitalWrite(ledMerah2, ledmerah2);
}

BLYNK_WRITE(V3){
  int Relay = param.asInt();
  digitalWrite(relay, Relay);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(ledHijau, OUTPUT);
  pinMode(ledMerah1, OUTPUT);
  pinMode(ledMerah2, OUTPUT);
  pinMode(relay, OUTPUT);
}

void loop()
{
  Blynk.run();
}

