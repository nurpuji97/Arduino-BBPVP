int ledA = 2;
int ledB = 3;
int ledC = 4;
int ledD = 5;
int ledE = 6;
int ledF = 7;
int ledG = 8;
//int led[] = {2,3,4,5,6,7,8};
//int len = sizeof(led) / sizeof(led[0]);
int delayMinute = 2000;

void setup() {
  // put your setup code here, to run once:
//  for(int i = 0; i<=len; i++){
//    pinMode(led[i], OUTPUT);
//  }
  
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);

}
//
byte digits[10][7] = {
  {0,0,0,0,0,0,1},  //0
  {1,0,0,1,1,1,1},  //1 
  {0,0,1,0,0,1,0},  //2 
  {0,0,0,0,1,1,0},  //3 
  {1,0,0,1,1,0,0},  //4 
  {0,1,0,0,1,0,0},  //5 
  {0,1,0,0,0,0,0},  //6 
  {0,0,0,1,1,1,1},  //7 
  {0,0,0,0,0,0,0},  //8 
  {0,0,0,0,1,0,0}  //9  
};

void loop() {
  // put your main code here, to run repeatedly:
  for(int y = 0; y<10; y++){
    digitalWrite(ledA, digits[y][0]);
    digitalWrite(ledB, digits[y][1]);
    digitalWrite(ledC, digits[y][2]);
    digitalWrite(ledD, digits[y][3]);
    digitalWrite(ledE, digits[y][4]);
    digitalWrite(ledF, digits[y][5]);
    digitalWrite(ledG, digits[y][6]);
    delay(delayMinute);
  }
 
}
