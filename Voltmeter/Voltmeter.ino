#include <ArduinoSTL.h>

using namespace std;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A1);
  float voltage = reading * (5.0 / 1023.0);
  cout << reading << " " << "voltage:" << voltage << endl;
  delay(100);
}
