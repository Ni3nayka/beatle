// https://robotclass.ru/tutorials/arduin-read-write-micro-sd-card/

#include "azbuka.h"

#include <SD.h>

const int chipSelect = 10;

const int out_device_pin = 13;

/*void play_symbol(char a) {
  for (int i = 0; i < azbuka_size; i++) {
    if (a==azbuka[i][0]) {
      for (int u; azbuka[i][u]!=0; u++) {
        digitalWrite(out_device_pin, 1);
        if (azbuka[i][u]=='.') delay(delay_play_tochka);
        else delay(delay_play_tire);
        digitalWrite(out_device_pin, 0);
        delay(delay_play_in_word);
      }
      delay(delay_play_between_word);
      return;
    }
  }
}*/

void play_symbol(char a) {
  Serial.println(a);
  int t = azbuka_size*2+1;
  for (int i = 0; i < t; i++) {
    if (a==azbuka[i]) {
      int test = azbuka_morze[(i-1)/2];
      int count = test&7;
      int symbol = (test>>3)&count;
      //Serial.println(i);
      //Serial.println(count);
      //Serial.println(symbol);
      for (int u = 0; u < count; u++) {
        digitalWrite(out_device_pin, 1);
        if (symbol&1) delay(delay_play_tire);
        else delay(delay_play_tochka);
        symbol >>= 1; 
        digitalWrite(out_device_pin, 0);
        delay(delay_play_in_word);
      }
      delay(delay_play_between_word);
      return;
    }
  }
}

void setup() {
    Serial.begin(9600);

    pinMode(out_device_pin, OUTPUT);

    play_symbol('А');
    //play_symbol('Л');
  Serial.println("!!!");

   if( !SD.begin( chipSelect )){
       Serial.println("initialization failed!");
       return;
    }
    // открываем файл для чтения
    File myFile = SD.open("text.txt");
    char F = 0;
    if (myFile) {
        // считываем все байты из файла и выводим их в COM-порт
        while (myFile.available()) {
            if (String(myFile.read())==String('Е')) Serial.print("!");
            //F = f;
            //play_symbol(f);
            //Serial.print(f);
        }
        // закрываем файл
        myFile.close();
    } else {
        // выводим ошибку если не удалось открыть файл
        Serial.println("error opening test.txt");
    }
}
void loop() {
}
