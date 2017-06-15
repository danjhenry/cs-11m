#include <ArduinoSTL.h>

using namespace std;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int i;
  while (i > 9) {
    i++
    cout << i << endl;
  }
}
