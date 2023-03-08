// definisi pin
#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8

// definisi nilai digit
byte digits[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
};

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    digitalWrite(a, digits[i][0]);
    digitalWrite(b, digits[i][1]);
    digitalWrite(c, digits[i][2]);
    digitalWrite(d, digits[i][3]);
    digitalWrite(e, digits[i][4]);
    digitalWrite(f, digits[i][5]);
    digitalWrite(g, digits[i][6]);
    delay(1000);
  }
}