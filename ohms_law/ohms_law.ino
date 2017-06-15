#include <ArduinoSTL.h>

using namespace std;

void setup() {
  Serial.begin(9600);

}

void loop() {
  /* intitalize all used local variables. Variable E ,I and R are initialized as
    float variables in order to produce a more accurate output.
  */
  float E;
  float I;
  float R;
  int choice = 0;
  // print out user instructions and take input from user.
  cout << "1. Calculate voltage (E)" << "\n"
       << "2. Calculate amperes (I)" << "\n"
       << "3. Calculate resistance (R)" << endl;

  cout << endl;

  cout << "Enter the number of your choice";
  cin >> choice;
  cout << " " << choice << endl;
  /* Inputs can be 1 ,2 and 3 which direct the use to the correct
    function the user wishes to calculate.
  */
  if (choice == 1) {
    cout << endl;

    cout << "Calculating voltage using Ohm's law (E = IR)" << "\n"
         << "Enter current in Amperes (I)";
    cin >> I;
    cout << " " << I << endl;
    cout << "Enter resistance in Ohms (R)";
    cin >> R;
    cout << " " << R << endl;
    // calculates voltage using the ohm's law with user inputs for amps and resistance.
    E = R * I;
    cout << "For " << I << " Amps and " << R << " Ohms the voltage is " <<
         E << " Volts." << endl;
  }

  else if (choice == 2) {
    cout << endl;

    cout << "Calculating amperes using Ohm's law (I = E / R)" << "\n"
         << "Enter the voltage (E)";
    cin >> E;
    cout << " " << E << endl;
    cout << "Enter resistance in Ohms (R)";
    cin >> R;
    cout << " " << R << endl;
    // calculates amperage using the ohm's law with user inputs for voltage and resistance.
    I = E / R;
    cout << "For " << E << " Volts and " << R << " Ohms the current is " <<
         I << " Amps." << endl;
  }

  else if (choice == 3) {
    cout << endl;

    cout << "Calculating resistance using Ohm's law (R = E / I)" << "\n"
         << "Enter the voltage (E)";
    cin >> E;
    cout << " " << E << endl;
    cout << "Enter current in Amperes (I)";
    cin >> I;
    cout << " " << I << endl;
    // calculates resistance using Ohm's law with user inputs for voltage and amps.
    R = E / I;
    cout << "For " << E << " Volts and " << I << " Amps the resistance is " <<
         R << " Ohms." << endl;
  }

  else  {
    // tells the user they entered an incorrect input.
    cout << "Inccorect input" << endl;
  }

  cout << endl;
}
