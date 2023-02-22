#define pin1 2
#define pin2 3
      #define delayMinute 1000
      
      int number = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  Serial.begin(9600);


  while(1){
        for(int i = 0; i <= 3; i++){
          digitalWrite(pin1, HIGH);
          digitalWrite(pin2, HIGH);
          delay(100);
          digitalWrite(pin2, LOW);
          digitalWrite(pin1, LOW);
          delay(100);
//            Serial.print(i);
        }

          digitalWrite(pin2, LOW);
          digitalWrite(pin1, LOW);
          delay(600);

        for(int i = 3; i >= 2; i--){
          digitalWrite(pin1, HIGH);
          digitalWrite(pin2, HIGH);
          delay(delayMinute);
          digitalWrite(pin2, LOW);
          digitalWrite(pin1, LOW);
          delay(delayMinute);
        }        
    }

}

void loop() {
  // put your main code here, to run repeatedly:
//    digitalWrite(pin1, HIGH);
//    digitalWrite(pin2, HIGH);
//    delay(delayMinute);
//    
//    digitalWrite(pin2, LOW);
//    digitalWrite(pin1, LOW);
//    delay(delayMinute);

//for(int i = 0; i <= 3; i++){
//          digitalWrite(pin1, HIGH);
//          digitalWrite(pin2, HIGH);
//          delay(100);
//          digitalWrite(pin2, LOW);
//          digitalWrite(pin1, LOW);
//          delay(100);
////            Serial.print(i);
//        }
//
//          digitalWrite(pin2, LOW);
//          digitalWrite(pin1, LOW);
//          delay(600);
//
//        for(int i = 3; i >= 0; i--){
//          digitalWrite(pin1, HIGH);
//          digitalWrite(pin2, HIGH);
//          delay(delayMinute);
//          digitalWrite(pin2, LOW);
//          digitalWrite(pin1, LOW);
//          delay(delayMinute);
//        }        


}
