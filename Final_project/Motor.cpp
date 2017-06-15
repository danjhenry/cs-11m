#include <ArduinoSTL.h>
#include <Servo.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <Arduino.h>
#include "motorClass.h"
using namespace std;

//Initialize IR components.
int TKD2 = 6;
int receiver = TKD2;
IRrecv irrecv(receiver);
decode_results results;

//IR signal decoder and timeout clock.
void Motor::IRcaller() {
  if (irrecv.decode(&results)) {
    cout << "IR signal debug information: ";
    Serial.println(results.value, HEX);
    cout << endl;
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

//Smooths out Initial servo movements.
void Motor::adjustMove(int angle, Servo servo) {
  for (int i = 0; i < angle + 1; i++) {
    servo.write(i);
    delay(20);
  }
}

//Drives servo motors for positive degree inputs.
void Motor::moveUp(int degree, Servo servo, int start, bool Switch, int servoPin) {
  delay(50);
  IRcaller();
  if (results.value == 0xFFFFFFFF) {
    cout << "button hold" << endl;
    Switch = true;
    while (Switch) {
      if (servoPin == servoPin5) {
        baseStart = start;
        cout << "base Degree: " << baseStart << endl;
      }
      else if (servoPin == servoPin9) {
        armMainStart = start;
        cout << "mainArm Degree: " << armMainStart << endl;
      }
      else if (servoPin == servoPin10) {
        armStart = start;
        cout << "secondaryArm Degree: " << armStart << endl;
      }
      servo.write(start);
      start++;
      if (start >= degree) {
        start = degree - 1;
        Switch = false;
      }
      IRcaller();
      if (results.value != 0xFFFFFFFF) {
        Switch = false;
        cout << "Button break" << endl;
      }
    }
  }
}

//Drives servo motors for positive negative inputs.
void Motor::moveDown(int degree, Servo servo, int start, bool Switch, int servoPin) {
  delay(50);
  IRcaller();
  if (results.value == 0xFFFFFFFF) {
    cout << "button hold" << endl;
    Switch = true;
    while (Switch) {
      if (servoPin == servoPin5) {
        baseStart = start;
        cout << "base Degree: " << baseStart << endl;
      }
      else if (servoPin == servoPin9) {
        armMainStart = start;
        cout << "mainArm Degree: " << armMainStart << endl;
      }
      else if (servoPin == servoPin10) {
        armStart = start;
        cout << "secondaryArm Degree: " << armStart << endl;
      }
      servo.write(start);
      start--;
      if (start <= degree) {
        start = degree + 1;
        Switch = false;
      }
      IRcaller();
      if (results.value != 0xFFFFFFFF) {
        Switch = false;
        cout << "Button break" << endl;
      }
    }
  }
}

//set's claw servo to 135 degrees then turns it off to prevent damage.
void Motor::clawOpen() {
  cout << "Button down pressed" << endl;
  servoClaw.write(135);
  delay(100);
  servoClaw.detach();
  IRcaller();
}

//Turn's on servo and opens claw (servo to 180 degrees).
void Motor::clawClosed() {
  servoClaw.attach(servoPin3);
  cout << "Button up pressed" << endl;
  servoClaw.write(180);
  IRcaller();
}

//Turns on servo's when pressed and held, Turns off servos when just pressed once.
void Motor::powerButton() {
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

//Checks IR inputs and sends them to their correct function.
void Motor::chooser() {
  if (results.value == 0x20FE4DBB) {
    cout << "Button > pressed" << endl;
    moveUp(180, servoBase, baseStart, base, servoPin5);
  }
  else if (results.value == 0x52A3D41F) {
    cout << "Button < pressed" << endl;
    moveDown(0, servoBase, baseStart, base, servoPin5);
  }
  else if (results.value == 0x8C22657B) {
    cout << "Button 4 pressed" << endl;
    moveUp(180, servoArmMain, armMainStart, mainArm, servoPin9);
  }
  else if (results.value == 0x449E79F) {
    cout << "Button 6 pressed" << endl;
    moveDown(65, servoArmMain, armMainStart, mainArm, servoPin9);
  }
  else if (results.value == 0x3D9AE3F7) {
    cout << "Button 2 pressed" << endl;
    moveUp(180, servoArm, armStart, Arm, servoPin10);
  }
  else if (results.value == 0x1BC0157B) {
    cout << "Button 8 pressed" << endl;
    moveDown(70, servoArm, armStart, Arm, servoPin10);
  }
  else if (results.value == 0xE318261B) {
    cout << "power button press" << endl;
    powerButton();
  }
  else if (results.value == 0xF076C13B) {
    clawOpen();
  }
  else if (results.value == 0xE5CFBD7F) {
    clawClosed();
  }
}

//Turns on servos and sets Intial "home" movements of servos.
void Motor::Initialize() {
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
