int lampu[] = {2,3,4,5,6};
int len = sizeof(lampu) / sizeof(lampu[0]);

void setup() {
  // put your setup code here, to run once:
  for(int y=0;y<5;y++){
    pinMode(lampu[y], OUTPUT);
  } 
//  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

// latihan 1
/* for(int i=0;i<5;i++){
//    digitalWrite(lampu[i], HIGH);
//    delay(500);
//    digitalWrite(lampu[i], LOW);
  } */

//  Serial.print(sizeof(lampu[1]));
//// latihan 2
//int b = 0;
//while(b < len){
//    digitalWrite(lampu[b], HIGH);
//    delay(500);
//    digitalWrite(lampu[b], LOW);
//    b++;
//}
//
//int c = len-1;
//while(c > 0){
//    digitalWrite(lampu[c], HIGH);
//    delay(500);
//    digitalWrite(lampu[c], LOW);
//    c--;
//}


//latihan 3
int b = 0;
do{
    digitalWrite(lampu[b], HIGH);
    delay(500);
    digitalWrite(lampu[b], LOW);
    b++;  
}while(b < len);

int c = len-1;
do{
    digitalWrite(lampu[c], HIGH);
    delay(500);
    digitalWrite(lampu[c], LOW);
    c--;  
}while(c > 0);

}
