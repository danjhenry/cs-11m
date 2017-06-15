#include <ArduinoSTL.h>

using namespace std;

int buttonCount = 0;
int priorButtonState = LOW;

const int rightButton = 12;
const int leftButton = 13;
const int LEDPins[] = {2, 4, 7, 8};

int blinkDelay = 960;

void setup() {
  pinMode(leftButton, INPUT_PULLUP);
  pinMode(rightButton, INPUT_PULLUP);
  pinMode(LEDPins[0], OUTPUT);
  Serial.begin(9600);

}

void loop() {

  int buttonState = digitalRead(rightButton);
  delay(1); // debounce
  if (buttonState != priorButtonState) {
    priorButtonState = buttonState;

    if (blinkDelay >= 1000) {
      cout << "Upper Limit of 1000 miliseconds has been cannot be exceeded" << endl;
      blinkDelay = 1000;
    }

    else if (buttonState == LOW) {
      blinkDelay = blinkDelay + 20;
      cout << "blinkDelay + 20" << " = " << blinkDelay << endl;
    }
  }
  int buttonState_2 = digitalRead(leftButton);
  delay(1); // debounce
  if (buttonState_2 != priorButtonState) {
    priorButtonState = buttonState_2;

    if (blinkDelay <= 100) {
      cout << "Lower Limit of 100 miliseconds has been cannot be exceeded" << endl;
      blinkDelay = 100;
    }

    else if (buttonState_2 == LOW) {
      blinkDelay = blinkDelay - 20;
      cout << "blinkDelay - 20" << " = " << blinkDelay << endl;
    }
  }
  digitalWrite(LEDPins[0], HIGH);
  delay(blinkDelay);
  digitalWrite(LEDPins[0], LOW);
  delay(blinkDelay);

}











