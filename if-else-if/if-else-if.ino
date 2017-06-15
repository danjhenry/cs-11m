#include <ArduinoSTL.h>

using namespace std;

const int LEDPins[] = {2, 4, 7, 8};

int blinkDelay;

void setup() {
  pinMode(LEDPins[0], OUTPUT);
  Serial.begin(9600);
  cout << "Enter a 1 or a 2 to set the LED blink rate." << endl;

}

void loop() {
  int choice;
  if (Serial.available()) {
    cin >> choice;
    cin.ignore(1);

    if (choice == 1) {
      blinkDelay = 100;
      cout << "Fast Blink" << endl;
    }
    else if (choice == 2)  {
      blinkDelay = 500;
      cout << "Slow Blink" << endl;

    }
  }
  digitalWrite(LEDPins[0], HIGH);
  delay(blinkDelay);
  digitalWrite(LEDPins[0], LOW);
  delay(blinkDelay);
}













