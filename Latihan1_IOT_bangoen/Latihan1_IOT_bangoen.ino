/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6updzk2p0"
#define BLYNK_TEMPLATE_NAME "Latihan1IOT"
#define BLYNK_AUTH_TOKEN "JkQOvwsmsds8nbJTkBswMjnwtGVm9xFx"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define relay1 D0 //relay1
#define relay2 D1 //relay2
#define PinPU D5 //toggle0
#define PinPB D6 //toggle0
#define PinJS D7 //toggle0

// syntax times blnyk
BlynkTimer timer;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BLYNK_WRITE(V0){
  int RelayOn1 = param.asInt();
  digitalWrite(relay1, RelayOn1);
}

BLYNK_WRITE(V1){
  int RelayOn2 = param.asInt();
  digitalWrite(relay2, RelayOn2);
}

// Toggle function
void Toggle() {
  if(digitalRead(PinPU) == 1){
      Blynk.virtualWrite(V2, 1);
      Blynk.virtualWrite(V5, "Pintu Utama Terbuka");
  } else {
     Blynk.virtualWrite(V2, 0);        
     Blynk.virtualWrite(V5, "Pintu Utama Tertutup");  
  }

  if(digitalRead(PinPB) == 1){
      Blynk.virtualWrite(V3, 1);
      Blynk.virtualWrite(V6, "Pintu Belakang Terbuka");
  } else {
     Blynk.virtualWrite(V3, 0);        
     Blynk.virtualWrite(V6, "Pintu Belakang Tertutup");  
  }

  if(digitalRead(PinJS) == 1){
      Blynk.virtualWrite(V4, 1);
      Blynk.virtualWrite(V7, "Jendela Samping Terbuka");
  } else {
     Blynk.virtualWrite(V4, 0);        
     Blynk.virtualWrite(V7, "Jendela Samping Tertutup");  
  }
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(PinPU, INPUT);
  pinMode(PinPB, INPUT);
  pinMode(PinJS, INPUT);
  timer.setInterval(1000L, Toggle);
}

void loop()
{
  Blynk.run();
  timer.run();
}

