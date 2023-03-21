/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPLqt_eYDXN"
#define BLYNK_TEMPLATE_NAME "LedTest"
#define BLYNK_AUTH_TOKEN "tCuGEwCLNZVj4PNDRP2GQzO74gk0o5U3"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define led D0

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BLYNK_WRITE(V0){
  int pinValue = param.asInt();
  digitalWrite(led, pinValue);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(led, OUTPUT);
}

void loop()
{
  Blynk.run();
}

