/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6RkC3PbJd"
#define BLYNK_TEMPLATE_NAME "LedTest"
#define BLYNK_AUTH_TOKEN "h_1dXc-t2QVzJF4Uqj5gwFQ6pHjSpJ1b"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LCD_I2C.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "ayen";
char pass[] = "ayen1234";

BlynkTimer timer;
LCD_I2C lcd(0x27, 16, 2); // Default address of most PCF8574 modules, change according

const int led = D0;
const int button = D5;
bool nilaibutton;
bool kondisiLed;
bool state;

BLYNK_CONNECTED(){
  Blynk.syncAll();  
}

BLYNK_WRITE(V0){
  kondisiLed = param.asInt();
  digitalWrite(led, kondisiLed);
  Blynk.setProperty(V0, "color", "#D3435C");
}

void ledbutton(){
  nilaibutton = digitalRead(button);   
  if(nilaibutton == 0){
    if(state != 0){
      kondisiLed=!kondisiLed;
      digitalWrite(led,kondisiLed);
      Blynk.virtualWrite(V0,kondisiLed);      
    }
    state = 0;        
  } else {
    state = 1; 
  }
  
  if(kondisiLed == 1){
    lcd.setCursor(0, 0);
    lcd.print("Led: ON ");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Led: OFF");   
  }


  delay(400);
  
}
 
void setup(){
  // Debug console
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(10L,ledbutton);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT);

  lcd.begin(); // If you are using more I2C devices using the Wire library use lcd.begin(false)
                 // this stop the library(LCD_I2C) from calling Wire.begin()
  lcd.backlight();
}

void loop()
{
  Blynk.run();
  timer.run();
}