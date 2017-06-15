#include "Color.h"
#include <ArduinoSTL.h>

using namespace std;
const int leftButton = 13;
int priorButtonState = LOW;

void setup() {
  Serial.begin(9600);
  cout << "Press the LEFT button to measure" << endl;
}

void loop() {
  int buttonState = digitalRead(leftButton);
  if (buttonState != priorButtonState) {
    priorButtonState = buttonState;
    if (buttonState == LOW) {
      Color start;
      start.turnOff();
      delay(1000);
      start.calibrate();
      start.Print();
      cout << "The dominant color is: " << start.getDominantColor() << endl;
      cout << "Press the LEFT button to measure" << endl;

    }
  }
}

