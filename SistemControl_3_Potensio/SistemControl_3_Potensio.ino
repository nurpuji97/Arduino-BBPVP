#define pinA A0
#define pinB A1
#define ledA 4
#define ledB 5
#define ledC 6
#define ledD 7
#define ledE 8
#define ledF 9
#define ledG 10
int conValue;

//Fungsi Hitung Angka di 7 Secment
void HitungAngka(void){
  if(conValue == 0){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, LOW);
  } else if (conValue == 1){
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
  } else if (conValue == 2){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, LOW);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, HIGH);
  } else if (conValue == 3){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, HIGH);
  } else if (conValue == 4){
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (conValue == 5){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (conValue == 6){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (conValue == 7){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, LOW);
    digitalWrite(ledG, LOW);
  } else if (conValue == 8){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, HIGH);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  } else if (conValue == 9){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    digitalWrite(ledC, HIGH);
    digitalWrite(ledD, HIGH);
    digitalWrite(ledE, LOW);
    digitalWrite(ledF, HIGH);
    digitalWrite(ledG, HIGH);
  }
}

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  //  deklarasi led
  pinMode(2, OUTPUT);

  //  delkalasi pinMode 7Secment
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
//  test
//  Serial.print("ADC 0: ");
//  Serial.println(analogRead(pinA));
//  Serial.print("ADC 1: ");
//  Serial.println(analogRead(pinB));

//// tugas 1
//  if(analogRead(pinA) >= 500){
//    digitalWrite(2, HIGH);
//  } else {
//    digitalWrite(2, LOW); 
//  }

////tugas 2
//  if(analogRead(pinA) <= analogRead(pinB)){
//    digitalWrite(2, HIGH);
//  } else {
//    digitalWrite(2, LOW); 
//  }

//tugas 3
/*
  map

  map(value, fromLow, fromHigh, toLow, toHigh);

  Fungsi map() memiliki 5 parameter yaitu fromLow, fromHigh, toLow, toHigh.

  berikut penjelasannya.

  *value = nilai yang akan dipetakan
  *fromLow = batas bawah nilai awal
  *fromHigh = batas atas nilai awal
  *toLow = batas bawah rentang target nilai
  *toHigh = batas atas rentang target nilai
  
*/
//conValue = map(analogRead(pinA), 0, 1023, 0, 100);
//  Serial.print("Conversi ");
//  Serial.println(conValue);

  // tugas 4
  conValue = map(analogRead(pinA), 0, 1023, 0, 9);
  HitungAngka();
  
  delay(500);
}
