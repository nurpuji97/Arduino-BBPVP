#define led0 D0
#define led1 D1
#define led2 D2
#define trigPin D6
#define echoPin D5
long durasi;
int jarak;

void setup() {
  // put your setup code here, to run once:
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  // kode sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  durasi = pulseIn(echoPin, HIGH);
  jarak = durasi * 0.034/2;

  Serial.print("Jarak = ");
  Serial.println(jarak);
  
  // 
  if(jarak > 60 && jarak < 99){
    digitalWrite(led0, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  } else if (jarak > 30 && jarak < 60) {
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else if (jarak > 12 && jarak < 30) {
    digitalWrite(led0, HIGH);
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  } else if (jarak < 12) {
      digitalWrite(led0, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      delay(600);

      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      delay(600);
  } else {
      digitalWrite(led0, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);    
  }

}
