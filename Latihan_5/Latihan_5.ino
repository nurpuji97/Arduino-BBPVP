//int led1 = 2;
//int led2 = 3;
//int led3 = 4;
//String ledOn1;

////function led 1 menyala
// uint8_t led1Function(int a , int b, int c, int e){
//     digitalWrite(a, HIGH);
//     digitalWrite(b, LOW);
//     digitalWrite(c, LOW);
//     delay(e);
//  } 
//
////function led 2 menyala
//   uint8_t led2Function(int a, int b, int c, int e){
//     digitalWrite(a, LOW);
//     digitalWrite(b, HIGH);
//     digitalWrite(c, LOW);
//     delay(e);
//  } 
//
////function led 3 menyala
//   uint8_t led3Function(int a, int b, int c, int e){
//     digitalWrite(a, LOW);
//     digitalWrite(b, LOW);
//     digitalWrite(c, HIGH);
//     delay(e);
//  } 

void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  

//  digitalWrite(led1, HIGH);
//  digitalWrite(led2, HIGH);
//  digitalWrite(led3, HIGH);
}


void loop() {
  // put your main code here, to run repeatedly:
//  led1Function(led1, led2, led3, 1000);
//  led2Function(led1, led2, led3, 1000);
//  led3Function(led1, led2, led3, 1000);

for(int i=2; i<=4; i++){
  digitalWrite(i-1, LOW);
  digitalWrite(i, HIGH);
  delay(100);
  Serial.print(i);
  if(i==4){
    digitalWrite(i, LOW);
    }
  }
}
