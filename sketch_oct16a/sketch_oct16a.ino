#include <ArduinoSTL.h>

using namespace std;

int priorButtonState = LOW;
const int leftButton = 13;

void setup() {
  Serial.begin(9600);
  pinMode(leftButton, INPUT_PULLUP);
  cout << "Enter a word and I will detect if it's a palindrome." << endl;

}

void loop() {
  string sentence;
  string wrd;
  int previousLength;
  int Length;
  bool keep_going = true;
  while (keep_going) {
    

    if (Serial.available()) {
      cin >> wrd;
      sentence += wrd;
      Length += wrd.length();
      if (Length > previousLength) {
        cout << Length << " " << sentence << " " << previousLength << endl;
        keep_going = true;
        previousLength = sentence.length();
      } else if (Length == previousLength) {

        cout << Length << " " << sentence << " " << previousLength << endl;
      }


    }

  }
}

























