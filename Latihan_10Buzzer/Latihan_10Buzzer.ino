int test;


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

//    dengan Button latihan 1
//      if(digitalRead(4) == HIGH){  
//        digitalWrite(2, HIGH);
//        digitalWrite(3, HIGH);
//      } else {
//        digitalWrite(2, LOW);
//        digitalWrite(3, LOW);
//      }

// button latihan 2
if(digitalRead(4) == HIGH) {
//    digitalWrite(2, HIGH);
    tone(2, 800, 100); // Play tone at 800 Hz for 100 milliseconds
//    song(2);
    digitalWrite(3, HIGH);
}

if(digitalRead(5) == HIGH) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
}


//if(digitalRead(5) == HIGH) {
//  test = 1;
//  Serial.print(test);
//} else {
//  test = 0;
//  Serial.print(test);
//}

}
