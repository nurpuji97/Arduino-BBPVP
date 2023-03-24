/*************************************************************
  Blynk is a platform with iOS and Android apps to control
  ESP32, Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build mobile and web interfaces for any
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  NOTE: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6uoE6m5-M"
#define BLYNK_TEMPLATE_NAME "BacaSensor"
#define BLYNK_AUTH_TOKEN "Ga77KfSPPrpY8116Xp-0th0J2ls9o_j9"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

// syntax times blnyk
BlynkTimer timer;

// potensio function
void potensioData() {
  int port = analogRead(A0); // this is an example of reading sensor data
  Blynk.virtualWrite(V0, port);

  int angle = map(port, 0, 1023, 0, 100); 
  Blynk.virtualWrite(V1, angle);   
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(1000l, potensioData);
}

void loop()
{
  Blynk.run();
  timer.run();
}

