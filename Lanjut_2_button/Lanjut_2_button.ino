int btn1 = 2;
int led1 = 8;
int led2 = 9;
int hitung;

void setup() {
  // put your setup code here, to run once:
  pinMode(btn1, INPUT);
  
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

bool nilaiButton = digitalRead(btn1);

if( nilaiButton == 1){
 hitung++;
 delay(500);
}

// Latihan 1
//if(hitung == 1) {
//  digitalWrite(led1, HIGH);
//}
//
//if(hitung == 4) {
//  digitalWrite(led1, LOW);
//  hitung = 0;
//}

//Latihan 3
switch(hitung) {
  case 1:
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  break;
  case 2:
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  break;
  case 3:
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  break;
  case 4:
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    hitung = 0;
  break;
}
  
}
