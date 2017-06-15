#include <ArduinoSTL.h>

using namespace std;

const int NUM_SCORES = 10;
int scores[NUM_SCORES] = {90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
const int tempSpace = 3;
float temp [tempSpace] = {25.7, 30.3, 40.9};
const int cStringspace = 6;
char cString [cStringspace] = {'a', 'e', 'i', 'o', 'u', '\0'};

void print(const int values[], int size) {
  for (int i = 0; i < size; i++) {
    cout << values[i] << " ";
  }
  cout << endl;
}

void print2(const float values[], int size) {
  for (int i = 0; i < size; i++) {
    cout << values[i] << " ";
  }
  cout << endl;
}

void print3(const char values[], int size) {
  for (int i = 0; i < size; i++) {
    cout << values[i];
  }
  cout << endl;
}

void setup() {
  Serial.begin(9600);

  cout << "Integer scores:" << endl;
  print(scores, NUM_SCORES);

  cout << "Double temperatures:" << endl;
  print2(temp, tempSpace);

  cout << "C-string vowels:" << endl;
  print3(cString, cStringspace);

}

void loop() {


}
