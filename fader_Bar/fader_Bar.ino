#include <ArduinoSTL.h>

using namespace std;

const int greenLED = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Fade out
  for (int i = 0; i < 255; i++) {
    for (int j = 0; j < i; j += 8) {
      cout << "*";
    }
    cout << endl;
    analogWrite(greenLED, i);

    delay(10);
  }


  for (int i = 255; i >= 0; i--) {

    analogWrite(greenLED, i);

    delay(10);



  }
}
