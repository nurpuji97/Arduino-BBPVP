#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8

#define dig1 9
#define dig2 10
#define dig3 11
#define dig4 13

// fungsi menampilkan angka
void TampilAngka(int angka){
  if(angka == 0){
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
  } else if (angka == 1){
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  } else if (angka == 2){
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
  } else if (angka == 3){
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
  } else if (angka == 4){
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  } else if (angka == 5){
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  } else if (angka == 6){
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  } else if (angka == 7){
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  } else if (angka == 8){
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  } else if (angka == 9){
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
  } 
}

// fungsi digit active
void digitActive(char digital){
  if(digital == dig1){
    digitalWrite(dig1, HIGH);
    digitalWrite(dig2, LOW);
    digitalWrite(dig3, LOW);
    digitalWrite(dig4, LOW); 
  } else if(digital == dig2){
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, HIGH);
    digitalWrite(dig3, LOW);
    digitalWrite(dig4, LOW); 
  } else if(digital == dig3){
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    digitalWrite(dig3, HIGH);
    digitalWrite(dig4, LOW); 
  } else if(digital == dig4){
    digitalWrite(dig1, LOW);
    digitalWrite(dig2, LOW);
    digitalWrite(dig3, LOW);
    digitalWrite(dig4, HIGH); 
  }
}

// fungsi matikan semua digit
void Matikan(void){
  digitalWrite(dig1, LOW);
  digitalWrite(dig2, LOW);
  digitalWrite(dig3, LOW);
  digitalWrite(dig4, LOW);  
}

// fungsi tampilkan kalkulasi 7 segment  buah
void TampilkanSegment(int nilai){
  
  // convert Ribuan
  int ribuan = (nilai % 10000) / 1000;

  // convert ratusan
  int ratusan = (nilai % 1000) / 100;

  // convert puluhan
  int puluhan = (nilai % 100) / 10;

  // convert satuan
  int satuan = nilai % 10;

  // tampilkan angka ribuan
  TampilAngka(ribuan);
  digitActive(dig1);
  Matikan();
  delay(5);

  // tampilkan angka ratusan
  TampilAngka(ratusan);
  digitActive(dig2);
  Matikan();
  delay(5);

  // tampilkan angka puluhan
  TampilAngka(puluhan);
  digitActive(dig3);
  Matikan();
  delay(5);

  // tampilkan angka satuan
  TampilAngka(satuan);
  digitActive(dig4);
  Matikan();
  delay(5);
}


void setup() {
  // put your setup code here, to run once:

  // pinMode 
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

  // pinMode Digits
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  TampilkanSegment(2345);

}
