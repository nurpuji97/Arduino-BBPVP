/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6O3o-XOlv"
#define BLYNK_TEMPLATE_NAME "LatihanUjk1"
#define BLYNK_AUTH_TOKEN "GNoTau-mBo_ShtGvenRgWvXhI6MhNIHe"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BlynkTimer timer;

#define Relay1 D0
#define Relay2 D1 
#define PbWork1 D2
#define PbWork2 D5
#define tglWork1 D6
#define tglWork2 D7
#define tglWork3 D8
int RelayWork1;
int RelayWork2;

bool state1;
bool state2; 

BLYNK_CONNECTED(){
  Blynk.syncAll();
}

BLYNK_WRITE(V0){
  RelayWork1 = param.asInt();
  digitalWrite(Relay1, RelayWork1);
}

BLYNK_WRITE(V1){
  RelayWork2 = param.asInt();
  digitalWrite(Relay2, RelayWork2);
}

void RelayActive(){
  bool btn1 = digitalRead(PbWork1);      
    if(btn1 == 1){
      if(state1 != 0){
        RelayWork1 = !RelayWork1;
        digitalWrite(Relay1, RelayWork1);
        Blynk.virtualWrite(V0, RelayWork1);
      }
      state1 = 0;
    } else{
      state1 = 1;
    }

  bool btn2 = digitalRead(PbWork2);      
    if(btn2 == 1){
      if(state2 != 0){
        RelayWork2 = !RelayWork2;
        digitalWrite(Relay2, RelayWork2);
        Blynk.virtualWrite(V0, RelayWork2);
      }
      state2 = 0;
    } else{
      state2 = 1;
    }

  // delay(400);

  if(digitalRead(tglWork1) == 1){
    Blynk.virtualWrite(V2, 1);
    Blynk.virtualWrite(V6, "Pintu Utama Terbuka");
    Blynk.logEvent("pintuutamaterbuka", String("Pintu Utama Terbuka ......"));
  }  else {
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V6, "Pintu Utama Tertutup");    
  }

  if(digitalRead(tglWork2) == 1){
    Blynk.virtualWrite(V3, 1);
    Blynk.virtualWrite(V5, "Pintu Belakang Terbuka");
    Blynk.logEvent("PintuBelakangTerbuka", String("Pintu Belakang Terbuka ......"));
  }  else {
    Blynk.virtualWrite(V3, 0);
    Blynk.virtualWrite(V5, "Pintu Belakang Tertutup");    
  }

  if(digitalRead(tglWork3) == 1){
    Blynk.virtualWrite(V4, 1);
    Blynk.virtualWrite(V7, "jendela Samping Terbuka");
    Blynk.logEvent("jendelasampingterbuka", String("Jendela Samping Terbuka ......"));
  }  else {
    Blynk.virtualWrite(V4, 0);
    Blynk.virtualWrite(V7, "jendela Samping Tertutup");    
  }
}

void setup() {
// Debug console
  Serial.begin(9600);

  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(PbWork1, INPUT);
  pinMode(PbWork2, INPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(10L, RelayActive);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run(); 
}
