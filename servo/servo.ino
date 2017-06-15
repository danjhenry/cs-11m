#include <ArduinoSTL.h>
#include <Servo.h>
using namespace std;

const int servoPin = 10;
Servo Servo1;

void angle() {
  int angle = Servo1.read();
  cout << angle << endl;
}
void setup() {
  Serial.begin(9600);
  Servo1.attach(servoPin);
  angle();
}

void loop() {
  int input;
  angle();
  cin >> input;
  cout << input << endl;
  Servo1.write(input);
  Servo1.read();
  angle();
}











