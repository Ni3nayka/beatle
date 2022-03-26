#include "azbuka.h"
#include "data.h"

const int out_device_pin = 3;
const int in_device_pin = 8;

unsigned long int time_1 = 0;
unsigned long int time_2 = 0;
String line_buffer = "";
int word_buffer = 0;

void play_symbol(char a) {
  //Serial.println(a);
  int t = azbuka_size*2+1;
  for (int i = 0; i < t; i++) {
    if (a==azbuka[i]) {
      int test = azbuka_morze[(i-1)/2];
      int count = test&7;
      int symbol = (test>>3)&(0b1111111111111111>>(16-count));
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

void play_line(String a, int d=1) {
  for (int i = d-1; a[i]!=0; i+=d) { 
    //Serial.println(a[i]);
    play_symbol(a[i]);
    if (!digitalRead(in_device_pin)) {
      while (!digitalRead(in_device_pin)) delay(10);
      break;
    }
  }
}

void setup() {
    Serial.begin(9600);

    pinMode(out_device_pin, OUTPUT);
    pinMode(in_device_pin, INPUT_PULLUP);

    //play_symbol('П');
    //delay(2000);
    //play_line("ПРИВЕТ");
    //play_line(String(azbuka[22]));
}

void loop() {
  time_1 = millis();
  while (!digitalRead(in_device_pin)) delay(10);
  if (millis()-time_1>5) {
    time_2 = millis();
    int count = (word_buffer&7)+1;
    int symbol = (millis()-time_1>delay_input_tochka_tire_trigger)?(1<<(2+count)):0;
    word_buffer = (word_buffer|symbol)&0b1111111111111000|count;
  }
  if (millis()-time_2>delay_input_in_between_word_trigger && word_buffer!=0) {
    for (int i = 0; i < azbuka_size; i++) {
      if (azbuka_morze[i]==word_buffer) {
        line_buffer += String(azbuka[i*2+1]);
        break;
      }
    }
    word_buffer = 0;
  }
  if (millis()-time_2>delay_input_enter_trigger && line_buffer!="") {
    //find_answer(line_buffer);
    //play_line(line_buffer);
    play_line(find_answer(line_buffer),2);
    line_buffer = "";
  }
  Serial.println(digitalRead(in_device_pin));
}
