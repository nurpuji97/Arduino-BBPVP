#define led 2
#define btnCounterUp 3
#define btnCounterDown 4
//#define Buzzer 5
int angka;

void setup() {
  // put your setup code here, to run once:
  pinMode(btnCounterUp, INPUT);
  pinMode(btnCounterDown, INPUT);
  pinMode(led, OUTPUT);
//  pinMode(Buzzer, OUTPUT);

  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btnCounterUp) == 0){
    angka++;
    delay(500); 
  } else if(digitalRead(btnCounterDown) == 0){
    angka--;
    delay(500);
  }

  if(angka > 10){
    angka = 10;   
  } else if(angka < 0){
    angka = 0;
  }

//   //    led menyala
////   tugas 1
//   if(angka >= 5){
//      digitalWrite(led, HIGH);
//   } else if(angka < 5){
//      digitalWrite(led, LOW);
//   }

//   tugas 2
   if(angka >= 0 && angka <= 2){
      digitalWrite(led, LOW);
   } else if(angka >= 3 && angka <= 5){
      digitalWrite(led, HIGH);
//      digitalWrite(Buzzer, HIGH);
//      delay(50);
//      digitalWrite(Buzzer, LOW);
//      delay(100);
   } else if(angka >= 6 && angka <= 8){
      digitalWrite(led, LOW);
   } else if(angka >= 9 && angka <= 10){
      digitalWrite(led, HIGH);
   }

   Serial.print(angka);   
   
}
