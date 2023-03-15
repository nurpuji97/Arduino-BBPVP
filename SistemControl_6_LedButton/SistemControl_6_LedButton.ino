#define led 2
#define btn1 3
#define btn2 4
#define btn3 5

int kondisi;
bool ledPrev;

void setup() {
  // put your setup code here, to run once:
  
  // pinmode led
  pinMode(led, OUTPUT);

  // pinmode button
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:  
  if(digitalRead(btn1) == LOW && kondisi == 0){
      kondisi = 1;
  }

  if(digitalRead(btn2) == LOW && kondisi == 1){
      kondisi = 2;
  }

  if(digitalRead(btn3) == HIGH && kondisi == 2){
      ledPrev=!ledPrev;
      digitalWrite(led, ledPrev);
      kondisi = 0;
  }

}
