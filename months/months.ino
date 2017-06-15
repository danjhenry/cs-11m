#include <ArduinoSTL.h>

using namespace std;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int monthNumber;
  cout << "Enter the month number";
  cin >> monthNumber;
  cout << " " << monthNumber << endl;
  char* months[] = { "January", "February", "March", "April", "May", "June"
                     , "July", "August", "September", "October", "November", "December"
                   };

  cout << "month" << " " << monthNumber << " " << "is" << " " << months[monthNumber - 1] << endl;

}
