#define btnUp 2
#define btnDown 3
#define ledA 4
#define ledB 5
#define ledC 6
#define ledD 7
#define ledE 8
#define ledF 9
#define ledG 10
#define led A0

// deklarasi variable count
int count;

//Fungsi Hitung Angka di 7 Secment
void HitungAngka(void){
  if(count == 0){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
  } else if (count == 1){
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
  } else if (count == 2){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, HIGH);
  } else if (count == 3){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, HIGH);
  } else if (count == 4){
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (count == 5){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (count == 6){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (count == 7){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
  } else if (count == 8){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (count == 9){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (count == 10){
    count = 0;
  }else {
    count = 9; 
  }

  // menyalakan led
  if(count >= 0 && count <= 5){
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
 
}


void setup() {
  // put your setup code here, to run once:
//  deklarasi pinMode Button
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);

//  delkalasi pinMode 7Secment
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);

  pinMode(led, OUTPUT);

//  Serial begin 9600
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Count ++ dan Count --
  if(digitalRead(btnUp) == 0){
    count++;
    delay(500); 
  } else if(digitalRead(btnDown) == 0){
    count--;
    delay(500);
  }

 HitungAngka(); 

//// serial print
//Serial.print("Serial Print : "):
//Serial.println(count);

}
