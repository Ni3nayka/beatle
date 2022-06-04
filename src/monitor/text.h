#define size_text 6
#define size_text_message 4
#define size_text_line 21

/*const char TEXT2[size_text][size_text_message*size_text_line] PROGMEM = {
  "                                                                                    ",
  "qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!",
  "werwerw",
  "werwerw",
  "werwerw",
  "qwertqwertqwertqwert!sdfgsdfgsdt!qwertqwertqwertqwert!qwertqwertqwertqwert!         ",
  "sdfgsdfgsdfgdfsg",
  "qwertqsdfgsdfgsdfgdf!",
  "qwertqwertqwertqwert!qwdbfxdb!qwertqwertqwertqwert!",
  "qwertqwertqwertqwert!qwertqwertqwertqwert!",
  "qwert fbfdzb tqwertqwert!qwertqwertqwertqwert!",
  "qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!qwertqwertqwertqwert!",
  "qwertqwertqwertqwert!qwertqwertqwertqwertqwertqwertqwert!",
  "qweertqwert!",
  "qwertqwertqwertqwert!qweqwert!",
};*/

#include <avr/pgmspace.h>
const char string_0[] PROGMEM = "String 0                                                                            "; // "String 0" etc are strings to store - change to suit.
const char string_1[] PROGMEM = "String 1                                                                            ";
const char string_2[] PROGMEM = "String 2                                                                            ";
const char string_3[] PROGMEM = "String 3                                                                            ";
const char string_4[] PROGMEM = "String 4                                                                            ";
const char string_5[] PROGMEM = "String 5                                                                            ";

const char *const TEXT[] PROGMEM = {string_0, string_1, string_2, string_3, string_4, string_5};
