#include <ArduinoSTL.h>

using namespace std;

void setup() {
Serial.begin(9600);

}

void loop() {
int homo = analogRead(A5);
cout << homo <<endl;
delay(200);

}
