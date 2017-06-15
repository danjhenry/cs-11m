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
  // initiate all the variables
  string sentence;
  string wrd;
  string output;
  string wordBackwards;
  string sentenceBackwards;
  int previousLength;
  int Length;
  bool keep_going = true;
  while (keep_going) {
    //checks for butten presses
    int buttonState = digitalRead(leftButton);
    delay(1); // debounce
    if (buttonState != priorButtonState) {
      priorButtonState = buttonState;
      if (buttonState == LOW) {
        cout << "Abort!" << endl;
        keep_going = false;

      }
    }
    if (Serial.available()) {
      //checks for inputs
      cin >> wrd;
      Length += wrd.length();
      sentence += wrd;
      output = output + " " + wrd;
      for (int i = Length - 1; i >= 0; i--) {
        sentenceBackwards += sentence[i];

        if ( sentenceBackwards.length() == Length) {

          // checks if the sentence backwards equals the sentence forwards.
          if (sentence == sentenceBackwards and Length != 1 ) {
            output = output.substr(1).append(output.substr(0, 1));
            cout << output << endl;
            cout << "Palindrome detected!" << endl;
            keep_going = false;
          } else {
            //else if a palindrome isnt detected try again with the next word.
            sentenceBackwards = "";
            keep_going = true;



          }
        }
      }
    }
  }
  cout << "Enter a word and I will detect if it's a palindrome." << endl;
  keep_going = true;

}





