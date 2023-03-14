#define pinA A0
#define pinB A1
int conValue;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(2, OUTPUT);
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
conValue = map(analogRead(pinA), 0, 1023, 0, 100);
  Serial.print("Conversi ");
  Serial.println(conValue);

  delay(500);
}
