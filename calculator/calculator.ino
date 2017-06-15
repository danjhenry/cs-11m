
#include <ArduinoSTL.h>

using namespace std;

void setup() {
  Serial.begin(9600);
  cout << "Enter two numbers separated by a space" << endl;
}

void loop() {
  float a;
  float b;
  if (Serial.available()) {
    cin >> a >> b;
    cin.ignore(1);
    cout << "You entered: " << a << " and " << b << endl;

    float numAdd = a + b;
    cout << " a + b = " << numAdd << endl;

    float numSub = a - b;
    cout << " a - b = " << numSub << endl;

    float numMult = a * b;
    cout << " a * b = " << numMult << endl;

    float numDiv = a / b;
    cout << " a / b = " << numDiv << endl;

  }
}

