int led1 = 2;
int led2 = 3;
int btn1  = 4;
int btn2  = 5;
int btn3  = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  //  Praktek

  //  Button 1 (Ganjil)
  if(digitalRead(btn1) == HIGH){
    digitalWrite(led1, HIGH);
  }

//  //  Button 2 (Genap)
  if(digitalRead(btn2) == HIGH){
    digitalWrite(led2, HIGH);
  }

//  //  Button 2 (OFF LED)
  if(digitalRead(btn3) == HIGH){
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
  }

}
