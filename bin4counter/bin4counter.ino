#include <ArduinoSTL.h>

using namespace std; 

const int LEDPins[] = {2, 4, 7, 8};

void setup() {
  Serial.begin(9600);
  for (auto pin : LEDPins) {
    pinMode(pin, OUTPUT);
  }
}

void numberToLEDs(int num) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(LEDPins[i], bitRead(num, i));
  }
}

void loop() {
  numberToLEDs(5);
}
