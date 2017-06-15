#include <ArduinoSTL.h>
#include "Color.h"
using namespace std;
void setup() {
  Serial.begin(9600);
  cout << "Enter a value from 0 to 255 which determines color intenisty for red , blue and green" << endl;
}

void loop() {
  int red;
  int blue;
  int green;
  cout << "Red: ";
  cin >> red;
  cout << red << endl;

  cout << "blue: ";
  cin >> blue;
  cout << blue << endl;

  cout << "green: ";
  cin >> green;
  cout << green << endl;

  Color pwmValues(red, green, blue);
  pwmValues.display();
  cout << "The most intense Color is: ";
  cout << pwmValues.getDominantColor() << endl;



}
