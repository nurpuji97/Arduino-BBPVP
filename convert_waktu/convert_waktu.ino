int nilai;
int detik;
int menit;
int jam;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  nilai = 1000;
  detik = nilai % 60;
  menit = (nilai % 3600) / 60;
  jam = menit / 3600;


  Serial.print("Nilai : ");
  Serial.println(nilai);
  
  Serial.print("Detik : ");
  Serial.println(detik);

  Serial.print("Menit : ");
  Serial.println(menit);

  Serial.print("Jam : ");
  Serial.println(jam);

  delay(5000);

}
