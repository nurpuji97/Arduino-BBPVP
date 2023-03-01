int pin1 = 2; deklarasi pin1
int pin2 = 3; deklarasi pin1
int delayMinute = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT); //panggil function pinMode dengan parameter (port_pin, OUTPUT/INPUT)  
  pinMode(pin2, OUTPUT); //panggil function pinMode dengan parameter (port_pin, OUTPUT/INPUT) 
  Serial.begin(9600); //deklarasi console log versi arduino

  while(1){
        for(int i = 0; i <= 3; i++){ //pengulangan dari 0 ke 3
          digitalWrite(pin1, HIGH); //lampu led menyala port 2  
          digitalWrite(pin2, HIGH); //lampu led menyala port 3
          delay(100);
          digitalWrite(pin2, LOW); //lampu led mati port 2 
          digitalWrite(pin1, LOW); //lampu led mati port 3 
          delay(100);
//            Serial.print(i); // console log pada arduino
        }

          digitalWrite(pin2, LOW); //lampu led mati port 3 
          digitalWrite(pin1, LOW); //lampu led mati port 2 
          delay(600); //delay dengan waktu 6 detik

        for(int i = 3; i >= 2; i--){  //pengulangan dari 3 ke 0
          digitalWrite(pin1, HIGH); //lampu led menyala port 2 
          digitalWrite(pin2, HIGH); //lampu led menyala port 3
          delay(delayMinute); //delay dengan variable yang bernilai 1 menit
          digitalWrite(pin2, LOW); //lampu led mati port 3
          digitalWrite(pin1, LOW); //lampu led mati port 2
          delay(delayMinute); //delay dengan variable yang bernilai 1 menit
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
