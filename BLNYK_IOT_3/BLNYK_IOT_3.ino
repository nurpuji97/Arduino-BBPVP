/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6AE6wp-Yf"
#define BLYNK_TEMPLATE_NAME "ServoCounter"
#define BLYNK_AUTH_TOKEN "kKQveFHK_0y-bhHUHGwHJQBUPMWdEjc4"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
BlynkTimer timer;

#define pinServo D1
int nilai10 = 10;
int nilai20 = 20;
int counter;
bool swicth;

BLYNK_CONNECTED(){
  Blynk.syncAll();  
}

BLYNK_WRITE(V0){
  int increment = param.asInt();
  if(increment == 1){
    if(counter <= 180){
      if(swicth == 0){
        myservo.write(counter+=nilai10); 
      } else {
        myservo.write(counter+=nilai20);         
      }
    }      
  }
  if(counter >= 180) {
    counter = 180;
  }   
}

BLYNK_WRITE(V1){
  int decrement = param.asInt();
  if(decrement == 1){
    if(counter >= 0){
      if(swicth == 0){
        myservo.write(counter-=nilai10); 
      } else {
        myservo.write(counter-=nilai20); 
      }
    }      
  }
  if(counter <= 0) {
    counter = 0;
  }  
}

BLYNK_WRITE(V4){
  int kelipatan = param.asInt();
  swicth = kelipatan;
}

// This function sends Arduino's up time every second to Virtual Pin (5)
void ServoDesc()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V2, "Motor Servo Control");
  Blynk.virtualWrite(V3, counter);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  myservo.attach(pinServo);
    // Setup a function to be called every second
  timer.setInterval(1000L, ServoDesc);
}

void loop()
{
  Blynk.run();
  timer.run();
}
