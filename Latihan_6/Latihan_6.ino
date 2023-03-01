void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  for(int i = 1; i<=4; i++){
      pinMode(i, OUTPUT);
//      Serial.print(i);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // led menyala
//  for(int y = 2; y<=5; y++){
//    digitalWrite(y, LOW);
//
//  if(y%2==0){
//    digitalWrite(y, HIGH);
//    digitalWrite(y+2, HIGH);
//    delay(1000);
//    digitalWrite(y, LOW);
//    digitalWrite(y+2, LOW);
//    delay(1000);
//    }
//
//   if(y%2==1){
//    digitalWrite(y, HIGH);
//    digitalWrite(y+2, HIGH);
//    delay(1000);
//    digitalWrite(y, LOW);
//    digitalWrite(y+2, LOW);
//    delay(1000);
//    }
//    
//   }    

digitalWrite(2, HIGH);
digitalWrite(4, HIGH);
delay(1000);
digitalWrite(2, LOW);
digitalWrite(4, LOW);
digitalWrite(3, HIGH);
digitalWrite(5, HIGH);
delay(1000);
digitalWrite(3, LOW);
digitalWrite(5, LOW);

}
