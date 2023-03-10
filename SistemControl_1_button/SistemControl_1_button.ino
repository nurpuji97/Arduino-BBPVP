#define btn1 2
#define btn2 3
int counter;
int Perkalian;

void setup() {
  // put your setup code here, to run once:

  // deklarasi pin  
  pinMode(btn1,INPUT);
  pinMode(btn2,INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btn1) == LOW){
    counter++;
    delay(500);  
  }

  if(digitalRead(btn2) == LOW){
    counter--;
    delay(500);  
  }

  if(counter >= 10){
    counter = 10;
  } else if(counter <= 0){
    counter = 0;
  }

//  perkalian count
//  Perkalian = (counter * 10);
  
  
  Serial.print("counter : ");
  Serial.println(counter);

//  Serial.print("perkalian 10 : ");
//  Serial.println(Perkalian);
}
