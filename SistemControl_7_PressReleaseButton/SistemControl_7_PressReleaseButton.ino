#define btnUp 2
#define btnDown 3
bool partBtnUp;
bool partBtnDown;
int counter;

void setup() {
  // put your setup code here, to run once:

//  deklarasi pinMode
  pinMode(btnUp, INPUT);
  pinMode(btnDown, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

//  Button Up
  if(partBtnUp == 0 && digitalRead(btnUp) == LOW ){
    partBtnUp = 1;
  }

  if(partBtnUp == 1 && digitalRead(btnUp) == HIGH ){
    counter++;
    delay(10);
    partBtnUp = 0;
  }

//  Button Down
  if(partBtnDown == 0 && digitalRead(btnDown) == LOW ){
    partBtnDown = 1;
  }

  if(partBtnDown == 1 && digitalRead(btnDown) == HIGH ){
    counter--;
    delay(10);
    partBtnDown = 0;
  }

  Serial.println(counter);

}
