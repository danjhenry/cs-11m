#include <ArduinoSTL.h>
#include <Servo.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <Arduino.h>

using namespace std;
//set servo pins to servo variables.
const int servoPin5 = 5;
const int servoPin3 = 3;
const int servoPin9 = 9;
const int servoPin10 = 10;
//initialize servos.
Servo servoArm;
Servo servoArmMain;
Servo servoBase;
Servo servoClaw;

int Time;
//initialize home positions in degrees
int baseStart = 90;
const int baseHome = 90;
int armMainStart = 65;
const int armMainhome = 65;
int armStart = 180;
const int armHome = 180;

bool base = true;
bool mainArm = true;
bool Arm = true;

int receiver = 6;
IRrecv irrecv(receiver);
decode_results results;

void adjustMove(int angle, Servo servo) {
  for (int i = 0; i < angle + 1; i++) {
    servo.write(i);
    delay(20);
  }
}

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  servoArmMain.attach(servoPin9);
  adjustMove(armMainhome, servoArmMain);
  delay(100);
  servoBase.attach(servoPin5);
  adjustMove(baseHome, servoBase);
  delay(100);
  servoArm.attach(servoPin10);
  adjustMove(armHome, servoArm);
  delay(100);
  servoClaw.attach(servoPin3);
  adjustMove(180, servoClaw);
}

void IRcaller() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    Time = 0;
  }
  else {
    Time++;
    if (Time == 8) {
      Time = 0;
      results.value = 0;
    }
  }
}

void loop() {
  IRcaller();
  if (results.value == 0x20FE4DBB) {
    cout << "Button > pressed" << endl;
    delay(50);
    IRcaller();
    if (results.value == 0xFFFFFFFF) {
      base = true;
      while (base) {
        cout << "Button > pressed hold" << endl;
        servoBase.write(baseStart);
        baseStart++;
        if (baseStart >= 180) {
          baseStart = 179;
          base = false;
        }
        IRcaller();
        if (results.value != 0xFFFFFFFF) {
          base = false;
          cout << "Button > break" << endl;
        }
      }
    }
  }

  else if (results.value == 0x52A3D41F) {
    cout << "Button < pressed" << endl;
    delay(50);
    IRcaller();
    if (results.value == 0xFFFFFFFF) {
      base = true;
      while (base) {
        cout << "Button < pressed hold" << endl;
        servoBase.write(baseStart);
        baseStart--;
        if (baseStart <= 0) {
          baseStart = 1;
          base = false;
        }
        IRcaller();
        if (results.value != 0xFFFFFFFF) {
          base = false;
          cout << "Button < break" << endl;
        }
      }
    }
  }

  else if (results.value == 0xF076C13B) {

    cout << "Button down pressed" << endl;
    servoClaw.write(135);
    delay(100);
    servoClaw.detach();
    IRcaller();
  }

  else if (results.value == 0xE5CFBD7F) {
    servoClaw.attach(servoPin3);
    cout << "Button up pressed" << endl;
    servoClaw.write(180);
    IRcaller();
  }


  if (results.value == 0x8C22657B) {
    cout << "Button 4 pressed" << endl;
    delay(50);
    IRcaller();
    if (results.value == 0xFFFFFFFF) {
      mainArm = true;
      while (mainArm) {
        cout << "Button 4 pressed hold" << endl;
        servoArmMain.write(armMainStart);
        armMainStart++;
        if (armMainStart >= 180) {
          armMainStart = 179;
          mainArm = false;
        }
        IRcaller();
        if (results.value != 0xFFFFFFFF) {
          mainArm = false;
          cout << "Button 4 break" << endl;
        }
      }
    }
  }

  else if (results.value == 0x449E79F) {
    cout << "Button 6 pressed" << endl;
    delay(50);
    IRcaller();
    if (results.value == 0xFFFFFFFF) {
      mainArm = true;
      while (mainArm) {
        cout << "Button 6 pressed hold" << endl;
        servoArmMain.write(armMainStart);
        armMainStart--;
        if (armMainStart <= 65) {
          armMainStart = 66;
          mainArm = false;
        }
        IRcaller();
        if (results.value != 0xFFFFFFFF) {
          mainArm = false;
          cout << "Button 6 break" << endl;
        }
      }
    }
  }

  if (results.value == 0x3D9AE3F7) {
    cout << "Button 2 pressed" << endl;
    delay(50);
    IRcaller();
    if (results.value == 0xFFFFFFFF) {
      Arm = true;
      while (Arm) {
        cout << "Button 2 pressed hold" << endl;
        servoArm.write(armStart);
        armStart++;
        if (armStart >= 180) {
          armStart = 179;
          Arm = false;
        }
        IRcaller();
        if (results.value != 0xFFFFFFFF) {
          Arm = false;
          cout << "Button 2 break" << endl;
        }
      }
    }
  }

  else if (results.value == 0x1BC0157B) {
    cout << "Button 8 pressed" << endl;
    delay(50);
    IRcaller();
    if (results.value == 0xFFFFFFFF) {
      Arm = true;
      while (Arm) {
        cout << "Button 8 pressed hold" << endl;
        servoArm.write(armStart);
        armStart--;
        if (armStart <= 70) {
          armStart = 71;
          Arm = false;
        }
        IRcaller();
        if (results.value != 0xFFFFFFFF) {
          Arm = false;
          cout << "Button 8 break" << endl;
        }
      }
    }
  }

  else if (results.value == 0xE318261B) {
    servoArmMain.detach();
    servoBase.detach();
    servoClaw.detach();
    servoArm.detach();
    cout << "power button press" << endl;
    delay(50);
    IRcaller();
    if ( results.value == 0xFFFFFFFF) {
      servoArmMain.attach(servoPin9);
      servoBase.attach(servoPin5);
      servoArm.attach(servoPin10);
      servoClaw.attach(servoPin3);
      cout << "power button hold" << endl;

    }
  }
}




















