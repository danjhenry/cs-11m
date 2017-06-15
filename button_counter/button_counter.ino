#include <ArduinoSTL.h>

using namespace std;

int buttonCount = 0;
int priorButtonState = LOW;

const int rightButton = 12;
const int leftButton = 13;

void setup() {
  Serial.begin(9600);
  pinMode(rightButton, INPUT_PULLUP);
}

void loop() {
  int buttonState = digitalRead(rightButton);
  delay(1); // debounce
  if (buttonState != priorButtonState) {
    priorButtonState = buttonState;
    if (buttonState == LOW) {
      buttonCount = buttonCount + 1;
      cout << "Count of button presses: " << buttonCount << endl;
    }
  }
}
