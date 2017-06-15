#include <ArduinoSTL.h>
#include <Servo.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <Arduino.h>
#include "motorClass.h"

using namespace std;
Motor Begin;
void setup() {
  Serial.begin(9600);
  Begin.Initialize();
}

void loop() {
  Begin.IRcaller();
  Begin.chooser();
}
