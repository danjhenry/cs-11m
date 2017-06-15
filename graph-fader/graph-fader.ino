#include <ArduinoSTL.h>

using namespace std;

const int greenLED = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int num;
  // Fade out
  for (int i = 0; i < 255; i++) {
    num = i;
    for (int j = 0; j < num; j += 8) {
      cout << "*";
    }
    analogWrite(greenLED, i);
    delay(10);
    cout << endl;

  }
  for (int i = 255; i >= 0; i--) {

    analogWrite(greenLED, i);
    delay(10);




  }
}
