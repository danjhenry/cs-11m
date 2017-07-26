#include <ArduinoSTL.h>

using namespace std;

void setup() {
Serial.begin(9600);

}

void loop() {
int test = analogRead(A5);
cout << test <<endl;
delay(200);

}
