#include <ArduinoSTL.h>

using namespace std; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  string str;
  cout << "Enter a word or phrase." << endl;
  getline(cin, str); 

  for (int i=0; i<str.length(); i++) {
    cout << str[i];
  }
  cout << endl;

  for (int i=str.length()-1; i>=0; i--) {
    cout << str[i];
  }
  cout << endl;  
}
