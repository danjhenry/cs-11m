#include <ArduinoSTL.h>

using namespace std;

const int LEDPins[] = {2, 4, 7, 8};

void setup() {
  Serial.begin(9600);
  for (auto pin : LEDPins) {
    pinMode(pin, OUTPUT);

  }
  Serial.begin(9600);
  cout << "Enter a number 0 to 15";
}

void numberToLEDs(int num) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(LEDPins[i], bitRead(num, i));
  }
}

void loop() {
  cout << "Feed Me Integers!" << endl;
  int num;
  cin >> num;
  cout << "you fed me:"<< num << endl;
  numberToLEDs(15);
}
