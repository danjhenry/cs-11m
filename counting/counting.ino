#include <ArduinoSTL.h>

using namespace std;

void setup() {
  Serial.begin(9600);
  cout << "This sketch writes lists of numbers." << endl;
  cout << "Enter the maximum number:" << endl;
}

void loop() {
  int max;
  cin >> max;
  cout << "for loop:" << endl;
  for (int i = 0; i <= max; i++) {
    cout << i << endl;
  }
}
