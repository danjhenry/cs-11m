#include <ArduinoSTL.h>


using namespace std;

void setup() {
  Serial.begin(9600);
  cout << "Enter a word and I will detect if it's a palindrome." << endl;
}

void loop() {
restart:
  string full;
  string wrd;
  cin >> wrd;
  string input = wrd;
  cout << wordLength << endl;
  if (wordLength == 1) {
    cout << "All one letter words are palindromes." << endl;
    goto restart;
  }
  bool fReturn = palindromeFunction(wrd);
  if (fReturn == true) {
    cout << "The word" << " \"" << wrd << "\" " << "is a palindrome." << endl;
  }
  else if (fReturn == false) {
    cout << "The word" << " \"" << wrd << "\" " << "is NOT a palindrome." << endl;
  }
}


bool palindromeFunction (string word) {
  string full;
  for (int i = word.length() - 1; i >= 0; i--) {
    full = full + word[i];
    if ( full.length() == word.length()) {
      if (word == full) {
        return true;
      } else {
        return false;
      }
    }
  }
}

















