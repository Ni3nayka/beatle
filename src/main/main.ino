#include "azbuka.h"

const int spiker = 11;

const int tochka = 100;
const int tire = 500;
const int probel_in_symbol = 100;
const int probel_in_word = probel_in_symbol * 2;
const int sound = 1000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println(azbuka[0][0]);
  //Serial.println(azbuka_s[0]);
  pinMode(spiker, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(A0));
  /*if (Serial.available() > 0) {
    char bykva = Serial.read();
    //Serial.println(bykva);
    for (int i = 0; i<26; i++) {
      if (bykva==azbuka_s[i]) {
        speak(azbuka[i]);
        break;
      }
    }
  }*/
}

/*void speak(int mas[mas_size]) {
   for (int i = 0; i<mas_size; i++) {
     //Serial.println(i);
     if (mas[i]==0) S_tochka();
     else if (mas[i]==1) S_tire();
     else break;
   }
   delay(probel_2);
}*/

void S_tochka() {
  tone(spiker, sound); delay(tochka);
  noTone(spiker); delay(probel);
}

void S_tire() {
  tone(spiker, sound); delay(tire);
  noTone(spiker); delay(probel);
}
