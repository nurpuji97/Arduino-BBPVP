/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6uCZd9kH0"
#define BLYNK_TEMPLATE_NAME "JarakAirBak"
#define BLYNK_AUTH_TOKEN "yEuSiqiUB0hJsz6itSnWOhVN9rSp8By0"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BlynkTimer timer;

#define led1 D0
#define led2 D1
#define led3 D2
#define echoPin D5
#define trigpin D6
#define relay D7

long durasi;
int jarak;
int volume;

BLYNK_CONNECTED(){
  Blynk.syncAll();
}

void TangkiAir(){

  // kode waktu sensor HY-SRF05
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);

  // durasi sensor HY-SRF05
  durasi = pulseIn(echoPin, HIGH);

  // Hitung Jarak Sensor
  jarak = durasi * 0.034/2;

  if(jarak < 20 && jarak > 10){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
    Blynk.virtualWrite(V2, 1); 
    Blynk.virtualWrite(V3, 0); 
    Blynk.virtualWrite(V4, 0); 
  } else if(jarak < 30 && jarak > 20){
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW); 
    digitalWrite(led3, LOW); 
    Blynk.virtualWrite(V3, 1);
    Blynk.virtualWrite(V2, 0); 
    Blynk.virtualWrite(V4, 0);      
  } else if(jarak > 30){
    digitalWrite(led3, HIGH);
    digitalWrite(led2, LOW); 
    digitalWrite(led1, LOW); 
    Blynk.virtualWrite(V4, 1);
    Blynk.virtualWrite(V3, 0); 
    Blynk.virtualWrite(V2, 0); 
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
    Blynk.virtualWrite(V2, 0); 
    Blynk.virtualWrite(V3, 0); 
    Blynk.virtualWrite(V4, 0); 
  }

  if(jarak >= 10 && jarak <= 40){
    volume = (40 - jarak) * 3.3333333;
    Blynk.virtualWrite(V1, volume); 
  } 

  if(volume < 20){
    digitalWrite(relay, HIGH); 
  } else if(volume >= 90) {
    digitalWrite(relay, LOW); 
  }  

  Blynk.virtualWrite(V0, jarak);  
}

void setup() {
  // put your setup code here, to run once:
  
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, TangkiAir);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(relay, OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
  timer.run();
}
