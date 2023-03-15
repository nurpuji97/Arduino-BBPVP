#define led 2
#define btn1 3
#define btn2 4
#define btn3 5
bool val1;
bool val2;
bool val3;
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
  if(digitalRead(btn1) == LOW && val1 == 0){
      val2 = 1;
  }

  if(digitalRead(btn2) == LOW && val2 == 1){
      val3 = 1;
  }

  if(digitalRead(btn3) == HIGH && val3 == 1){
      ledPrev=~ledPrev;
      digitalWrite(led, ledPrev);
      val2 = 0;
      val3 = 0;
  }

}
