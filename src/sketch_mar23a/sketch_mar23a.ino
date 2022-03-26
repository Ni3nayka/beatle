
const int out_device_pin = 3;
const int in_device_pin = 8;


void setup() {
    Serial.begin(9600);

    pinMode(out_device_pin, OUTPUT);
    pinMode(in_device_pin, INPUT_PULLUP);
}

void loop() {
  
  Serial.println(digitalRead(in_device_pin));
}
