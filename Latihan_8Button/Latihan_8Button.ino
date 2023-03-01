int led = 2;
int button1 = 5;
int button2 = 9;
int value;

void setup() {
  // put your setup code here, to run once:
   pinMode(button1, INPUT);
   pinMode(button2, INPUT);
   pinMode(led, OUTPUT);
 

//  digitalWrite(led, HIGH);

  Serial.begin(9600);


  
}

void loop() {
  // put your main code here, to run repeatedly:
//   value = digitalRead(button1);
//   if(value == 1){
//    digitalWrite(led, HIGH);
//   }
//    digitalWrite(led, LOW);
//       Serial.print(value);
//      
//      delay(100);


int test1 = digitalRead(button1);
int test2 = digitalRead(button2);


//delay(1000);

if(test1==1){
//  value=1;
digitalWrite(led,1);
} else if(test2==1){
// value=0;
digitalWrite(led,0);
}

//if(value == 1){
//  digitalWrite(led, HIGH);
//} else {
//  digitalWrite(led, LOW);
// }

}
