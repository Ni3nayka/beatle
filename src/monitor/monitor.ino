/*
 * https://www.arduino.cc/reference/en/language/variables/utilities/progmem/
 * https://alexgyver.ru/lessons/progmem/
 * https://kit.alexgyver.ru/tutorials/oled/
 */

#include <GyverOLED.h>
GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;

#include "text.h"

const int button_pin[3] = {4,3,2};

bool sleep = 0; // 0 - work, 1 - sleep
int list = 1; // отображаемая страница
unsigned long int time = 0; // для автоотключения экрана
#define time_sleep 30000 // время для ухода в сон

void setup() {
  Serial.begin(9600);
  // button
  for (int i = 0; i<3; i++)
    pinMode(button_pin[i],INPUT_PULLUP);
  // display
  oled.init();        // инициализация
  
  /*oled.clear();       // очистка
  oled.setScale(3);   // масштаб текста (1..4)
  oled.home();        // курсор в 0,0
  oled.print("П");
  delay(100);
  oled.print("p");
  delay(100);
  oled.print("и");
  delay(100);
  oled.print("в");
  delay(100);
  oled.print("е");
  delay(100);
  oled.print("т");
  delay(100);
  oled.print("!");
  delay(500);*/
  
  print_display(1);
  
  /*oled.clear();
  oled.setScale(1);
  // курсор на начало 3 строки
  oled.setCursor(0, 3);
  oled.print("ТЕСТ прив.");
  // курсор на (20, 50)
  oled.setCursorXY(20, 50);
  float pi = 3.14;
  oled.print("PI = ");
  oled.print(pi);*/
}

void loop() {
  //test_button();
  controller();
}

void controller() {
  bool b1 = button(1), b2 = button(2), b3 = button(3);
  if (b1+b2+b3>1 || b2) {  // отключение экрана
    oled.clear();
    sleep = 1;
    delay(1000);
  }
  else if (b1+b2+b3==1) {
    time = millis();
    if (sleep) { // проснуться
      sleep = 0;
      print_display(list);
    }
    else {
      Serial.print(list);
      if (b3) {
        list++;
        Serial.print(list);
        if (list>=size_text) {
          list = 1;
        }
      }
      else if (b1) {
        list--;
        Serial.print(list);
        if (list<=0) {
          list = size_text-1;
        }
      }
      Serial.println(list);
      Serial.println(size_text); // ПОЧЕМУ ТО РАБОАЕТ ТОЛЬКО С ЭТОЙ И СЛЕДУЮЩЕЙ СТРОКОЙ, ИНАЧЕ ПЕРЕПОЛНЕНИЕ
      Serial.println(size_text-1);
      print_display(list);
    }
    delay(100);
  }
  if (time+time_sleep<millis() && !sleep) { // отключение экрана по задержке
    oled.clear();
    sleep = 1;
  }
}

void test_button() {
  Serial.print(button(1));
  Serial.print(" ");
  Serial.print(button(2));
  Serial.print(" ");
  Serial.print(button(3));
  Serial.println();
}

bool button(int n) {
  return !digitalRead(button_pin[n-1]);
}

String srez(int n, int n_line) {
  char buf[size_text_message*size_text_line];
  strcpy_P(buf, (char *)pgm_read_word(&(TEXT[n])));
  String answer = "";
  for (int i = n_line*size_text_line; i<(n_line+1)*size_text_line; i++) {
    answer += buf[i];
  }
  /*for (int i = n_line*size_text_line; i<(n_line+1)*size_text_line; i++) {
    answer += TEXT[n][i];
  }*/
  return answer;
}

void print_display(int n) {
  if (n>size_text) return;
  //if (n!=0) print_display(0);
  oled.clear();
  oled.setScale(1);
  oled.home();
  for (int i = 0; i<size_text_message; i++) {
    oled.setCursor(0, i); 
    oled.print(srez(n,i));
  }
}
