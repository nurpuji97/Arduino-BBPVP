/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6AZR9aZ_x"
#define BLYNK_TEMPLATE_NAME "7Segment"
#define BLYNK_AUTH_TOKEN "QV7G-8RHesfH0BQIpLlBxQQFBjaOECqT"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BlynkTimer timer;

BLYNK_CONNECTED(){
  Blynk.syncAll();  
}

int counter;
int pinLed[7] = {D0, D1, D2, D5, D6, D7, D8};
bool digits[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0 
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2 
  {0, 0, 0, 0, 1, 1, 0}, // 3 
  {1, 0, 0, 1, 1, 0, 0}, // 4 
  {0, 1, 0, 0, 1, 0, 0}, // 5 
  {0, 1, 0, 0, 0, 0, 0}, // 6 
  {0, 0, 0, 1, 1, 1, 1}, // 7 
  {0, 0, 0, 0, 0, 0, 0}, // 8 
  {0, 0, 0, 0, 1, 0, 0} // 9   
};

void tampilAngka(int angka){
  for(int i = 0; i < 7; i++){
    digitalWrite(pinLed[i], digits[angka][i]);
  }  
}

BLYNK_WRITE(V0){
  int increment = param.asInt();
  if(increment == 1 && counter < 9){
    tampilAngka(counter++);   
  }
}

BLYNK_WRITE(V1){
  int decrement = param.asInt();
  if(decrement == 1 && counter > 0){
      tampilAngka(counter--);   
  }
}

void batas(){
  if(counter > 9){
    counter = 9;
  } else if(counter < 0){
    counter = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, batas);
  
  for(int i = 0; i < 7; i++){
    pinMode(pinLed[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run(); 
  timer.run();
}
