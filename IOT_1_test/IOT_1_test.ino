//#define led1 D0
//#define led2 D1

#define btn0 D5
#define btn1 D6
#define btn2 D7
#define btn3 D8

bool btnActive0;
bool btnActive1;
bool btnActive2;
bool btnActive3;

void setup() {
  // put your setup code here, to run once:
//  pinMode(led1, OUTPUT);
//  pinMode(led2, OUTPUT);

  pinMode(btn0, INPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(led1, HIGH);
//  digitalWrite(led2, HIGH);
//  delay(500);
//  digitalWrite(led1, LOW);
//  digitalWrite(led2, LOW);
//  delay(500);

  btnActive0 = digitalRead(btn0);
  btnActive1 = digitalRead(btn1);
  btnActive2 = digitalRead(btn2);
  btnActive3 = digitalRead(btn3);

  Serial.print(btnActive0);
  Serial.print(btnActive1);
  Serial.print(btnActive2);
  Serial.print(btnActive3);
  delay(6000);
}
