//fungsi lampu menyala bergantian
uint8_t lampuBergantianFunction(){
  for(int ulang = 1; ulang<=4; ulang++){
    for(int pinLampu = 2; pinLampu <=5; pinLampu++){
      digitalWrite(pinLampu-1, LOW);
      digitalWrite(pinLampu, HIGH);
      delay(500);
      if(pinLampu==5){
        digitalWrite(pinLampu, LOW);
        }
    }
    delay(1000);  
  }
  delay(2000);
}

// fungsi lampu bersamaan
uint8_t lampuBersamaanFunction(){
  for(int ulang = 1; ulang<=4; ulang++){
     for(int pinLampu = 2; pinLampu <=2; pinLampu++){
      digitalWrite(pinLampu, HIGH);
      digitalWrite(pinLampu+1, HIGH);
      digitalWrite(pinLampu+2, HIGH);
      digitalWrite(pinLampu+3, HIGH);
      delay(1000);
      }
  
    for(int pinLampu = 2; pinLampu <=2; pinLampu++){
      digitalWrite(pinLampu, LOW);
      digitalWrite(pinLampu+1, LOW);
      digitalWrite(pinLampu+2, LOW);
      digitalWrite(pinLampu+3, LOW);
      delay(1000);
      }   
   }
    delay(2000);
 }


// fungsi lampun selang seling 1 dan 3 , 2 dan 4
uint8_t lampuGanti1Function(){
     for(int ulang = 1; ulang<=4; ulang++){
      for(int pinLampu = 2; pinLampu <=2; pinLampu++){
        digitalWrite(pinLampu, HIGH);
        digitalWrite(pinLampu+1, LOW);
        digitalWrite(pinLampu+2, HIGH);
        digitalWrite(pinLampu+3, LOW);
        delay(1000);
      }

      for(int pinLampu = 2; pinLampu <=2; pinLampu++){
        digitalWrite(pinLampu, LOW);
        digitalWrite(pinLampu+1, HIGH);
        digitalWrite(pinLampu+2, LOW);
        digitalWrite(pinLampu+3, HIGH);
        delay(1000);  
      }
    }
    
    for(int pinLampu = 2; pinLampu <=2; pinLampu++){
        digitalWrite(pinLampu, LOW);
        digitalWrite(pinLampu+1, LOW);
        digitalWrite(pinLampu+2, LOW);
        digitalWrite(pinLampu+3, LOW);
        delay(2000);
    }
    
}


// fungsi lampun selang seling 1 dan 2 , 3 dan 4
uint8_t lampuGanti2Function(){
  for(int ulang = 1; ulang<=4; ulang++){
    for(int pinLampu = 2; pinLampu <=2; pinLampu++){
        digitalWrite(pinLampu, HIGH);
        digitalWrite(pinLampu+1, HIGH);
        digitalWrite(pinLampu+2, LOW);
        digitalWrite(pinLampu+3, LOW);
        delay(1000);
     }

     for(int pinLampu = 2; pinLampu <=2; pinLampu++){
        digitalWrite(pinLampu, LOW);
        digitalWrite(pinLampu+1, LOW);
        digitalWrite(pinLampu+2, HIGH);
        digitalWrite(pinLampu+3, HIGH);
        delay(1000);  
     }
  }

  for(int pinLampu = 2; pinLampu <=2; pinLampu++){
    digitalWrite(pinLampu, LOW);
    digitalWrite(pinLampu+1, LOW);
    digitalWrite(pinLampu+2, LOW);
    digitalWrite(pinLampu+3, LOW);
    delay(2000);
   }
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 2; i<=5; i++){
    pinMode(i, OUTPUT);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  lampuBergantianFunction();
  lampuBersamaanFunction();
  lampuGanti1Function();
  lampuGanti2Function();
}
