/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL67xHBzmhX"
#define BLYNK_TEMPLATE_NAME "ProjectIOT1"
#define BLYNK_AUTH_TOKEN "KsLTed_Cl0H9n7RsqY7D5fzU0Dmr4QeZ"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LCD_I2C.h>
#include <Servo.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BlynkTimer timer;
Servo myservo;
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

#define Kt D0
#define Gg D3
#define Kcm D4
#define Door D7
#define Window D8
#define pinBuzzer D6
#define pinServo D5

BLYNK_WRITE(V0){
  int KTidur = param.asInt();
  digitalWrite(Kt, KTidur);   
}

BLYNK_WRITE(V1){
  int GarasiG = param.asInt();
  digitalWrite(Gg, GarasiG);   
}

BLYNK_WRITE(V2){
  int DapurMandi = param.asInt();
  digitalWrite(Kcm, DapurMandi);   
}

BLYNK_WRITE(V4){
  int StateServo = param.asInt();
  myservo.write(StateServo);
  if(StateServo > 90){
      digitalWrite(pinBuzzer, 1);
      Blynk.virtualWrite(V5, 1);
      delay(15);
  } else {
      digitalWrite(pinBuzzer, 0);
      Blynk.virtualWrite(V5, 0);  
      delay(15);  
  }

}

void WorkHouse(){
    lcd.clear();
    lcd.setCursor(3, 0); // Or setting the cursor in the desired position.
    lcd.print("Smart Home");
    lcd.setCursor(1, 1); // Or setting the cursor in the desired position.
    lcd.print("D:");
    if(digitalRead(Door) == 1){
      lcd.print("ON ");      
    } else {
      lcd.print("OFF");     
    }
    lcd.setCursor(10, 1); // Or setting the cursor in the desired position.
    lcd.print("W:");
    if(digitalRead(Window) == 1){
      lcd.print("ON ");      
    } else {
      lcd.print("OFF");     
    }

}

void setup()
{
  // Debug console
  Serial.begin(9600);

    lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
    lcd.backlight();
    lcd.setCursor(0, 0); // Or setting the cursor in the desired position.
    lcd.print("Selamat Datang");
    lcd.setCursor(5, 1); // Or setting the cursor in the desired position.
    lcd.print("Pujie!");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(1000L, WorkHouse);
  myservo.attach(pinServo);
  pinMode(Kt, OUTPUT);
  pinMode(Gg, OUTPUT);
  pinMode(Kcm, OUTPUT);
}

void loop()
{
  Blynk.run();
  timer.run();
}

