/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6TEtdpHE8"
#define BLYNK_TEMPLATE_NAME "Pagar7Segment"
#define BLYNK_AUTH_TOKEN "ga2P7srcaxrc8pjygJeeUQnCaDN_qHSR"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BLYNK_CONNECTED(){
  Blynk.syncAll();
}

BlynkTimer timer;

char led[7] = {D0, D1, D2, D5, D6, D7};

void OnOffLed(bool contOn){
    if(contOn == 1){
      for(int i = 0; i < 6; i++ ){
      digitalWrite(led[i], HIGH);
      delay(1000);
      }
        // kirim notofikasi
        Blynk.logEvent("pagarterbuka", String("Pager Terbuka"));      
    } else {
      for(int i = 6; i > -1; i-- ){
      digitalWrite(led[i], LOW);
      delay(1000);
      }
      // kirim notofikasi
      Blynk.logEvent("pagartertutup", String("Pager Tertutup")); 
    }  
  }  


BLYNK_WRITE(V0){
  int pagar = param.asInt();
  OnOffLed(pagar);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  for(int i = 0; i < 7; i++ ){
    pinMode(led[i], OUTPUT);
  }  
  
}

void loop()
{
  Blynk.run();
}

