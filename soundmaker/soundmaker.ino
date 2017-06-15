#include <ArduinoSTL.h>

using namespace std;
const int sound = 3;
void setup() {
  Serial.begin(9600);
  pinMode(sound, OUTPUT);
}

void loop() {
  int reading = analogRead(A2);
  cout << reading << endl;
  tone(3, reading);


}

