#include <ArduinoSTL.h>

using namespace std; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  string band1;
  string band2; 
  string band3; 
  cout << "Enter a resistor color code." << endl;
  cin >> band1 >> band2 >> band3; 

  int band1value = getNumberFromCode(band1);
  int band2value = getNumberFromCode(band2);
  int band3value = getNumberFromCode(band3);

  // Calculate the resistor value.
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
