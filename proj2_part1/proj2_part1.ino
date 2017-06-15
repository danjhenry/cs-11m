#include <ArduinoSTL.h>

using namespace std;

const int LEDPins[] = {2, 4, 7, 8};

int blinkDelay;

void setup() {
  pinMode(LEDPins[0], OUTPUT);
  Serial.begin(9600);
  cout << "Enter a rate in miliseconds to set the LED blink rate." << endl;

}

void loop() {

  if (Serial.available()) {
    cin >> blinkDelay;
    cin.ignore(1);

    if (blinkDelay > 100 and blinkDelay < 1000) {
      cout << blinkDelay << endl;

    } else if (blinkDelay <= 100 and blinkDelay > 0) {
      blinkDelay = 100;
      cout << "100" << endl;

    } else if (blinkDelay >= 1000)  {
      blinkDelay = 1000;
      cout << "1000" << endl;

    } else {
      cout << "invalid input" << endl;

    }
  }
  digitalWrite(LEDPins[0], HIGH);
  delay(blinkDelay);
  digitalWrite(LEDPins[0], LOW);
  delay(blinkDelay);

}











