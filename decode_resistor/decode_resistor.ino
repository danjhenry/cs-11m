#include <ArduinoSTL.h>

using namespace std;

void setup() {
  Serial.begin(9600);
}

void loop() {
  string color;
  cout << "Enter a resistor color code." << endl;
  cin >> color;

  int colorNumber = getNumberFromCode(color);
  cout << "That code corresponds to the number " << colorNumber << endl;
}

int getNumberFromCode(string code) {
  int number = 0;

  if (code == "B") {
    number = 0;
  }
  else if (code == "Br" or code == "BR") {
    number = 1;
  }
  else if (code == "R") {
    number = 2;
  }
  else if (code == "O") {
    number = 3;
  }
  else if (code == "Y") {
    number = 4;
  }
  else if (code == "G") {
    number = 5;
  }
  else if (code == "Bu" or code == "BU") {
    number = 6;
  }
  else if (code == "V") {
    number = 7;
  }
  else if (code == "Gy" or code == "GY") {
    number = 8;
  }
  else if (code == "W") {
    number = 9;
  }

  return number;
}
