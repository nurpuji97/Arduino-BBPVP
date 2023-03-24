#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

#define pinResistor A0
#define pinPWM 9

void setup() {
  myservo.attach(pinPWM);  // attaches the servo on pin 9 to the servo object
}

void loop() {
int reading = analogRead(pinResistor);
int angle = map(reading, 0, 1023, 0, 180);
myservo.write(angle);
}
