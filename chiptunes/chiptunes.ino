#include <ArduinoSTL.h>

using namespace std;

const int speakerPin = 3;
void setup() {
  Serial.begin(9600);
  cout << "Enter Note" << endl;
  string scale = "cdefgabagfedc";
  for (int i=0; i<scale.length(); i++) {
    tone(speakerPin, getNote(scale[i]));
    delay(200);
  }
  noTone(speakerPin);
}

void loop() {
  char input;
  cin >> input;
  cout << getNote(input) << endl;
  tone(speakerPin, getNote(input));
  delay(190);

}

/* getNote()
    char note: The letter that represents the note
     returns: The note's frequency
*/
int getNote(char note) {
  if (note ==  'c') {
    return 261;
  }
  else if (note == 'C') {
    return 277;
  }
  else if (note == 'd') {
    return 294;
  }
  else if (note == 'D') {
    return 311;
  }
  else if (note == 'e') {
    return 330;
  }
  else if (note == 'f') {
    return 349;
  }
  else if (note == 'F') {
    return 370;
  }
  else if (note == 'g') {
    return 392;
  }
  else if (note == 'G') {
    return 415;
  }
  else if (note == 'a') {
    return 440;
  }
  else if (note == 'A') {
    return 466;
  }
  else if (note == 'b') {
    return 494;
  }
  else if (note == '-') {
    //empty
  }
  else if (note == ' ') {
    delay(200);
  }

}























