#include <ArduinoSTL.h>

using namespace std;

const int MAX_SCORES = 5;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int scores[MAX_SCORES];

  cout << "Enter " << MAX_SCORES << " scores." << endl;
  for (int i = 0; i < MAX_SCORES; i++) {
    cin >> scores[i];
  }

  cout << "You entered: " << endl;
  for (int i = MAX_SCORES - 1; i >= 0; i--) {
    cout << scores[i] << endl;
  }
}
