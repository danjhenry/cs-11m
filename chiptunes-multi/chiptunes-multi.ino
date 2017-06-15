#include <ArduinoSTL.h>

using namespace std;

const int speakerPin = 3;
void setup() {
  Serial.begin(9600);
}

void loop() {
  string melody;
  getline(cin, melody);
  cout << melody << endl;

  for (int i = 0; i < melody.length(); i++) {
    if (melody[i] == ' ') {
      noTone(speakerPin);
      delay(180);
      cout << "space" << endl;
    }
    else if (melody[i] == '-') {
      delay(190);
      cout << "keepgoing" << endl;
    }
    else {
      noTone(speakerPin);
      delay(10);
      tone(speakerPin, getNote(melody[i]));
      delay(190);

    }
  }
  noTone(speakerPin);

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



