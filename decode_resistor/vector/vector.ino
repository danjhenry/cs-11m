#include <ArduinoSTL.h>

using namespace std;

void setup() {
  Serial.begin(9600);
}

void toVector(vector<int> &vect, int numbers[], int len) {
  for (int i; i < len; i++) {
    vect.push_back(numbers[i]);
  }
}

void Print (vector<int> vect) {
  for (int i; i < vect.size(); i++) {
    cout << vect[i] << " ";
  }
  cout << endl;
}

void loop() {
  vector<int> vect;
  int numbers[] = {10, 34, 23, 43};
  toVector(vect, numbers, 4);
  Print(vect);
  delay (10000);
}
