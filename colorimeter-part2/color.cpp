#include "Color.h"
#include <Arduino.h>
#include <ArduinoSTL.h>

using namespace std;

void Color::setOutput() {
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}
void Color::turnOff() {
  analogWrite(redLED, 255);
  analogWrite(blueLED, 255);
  analogWrite(greenLED, 255);
}
void Color::calibrate() {
  black = analogRead(photoSensor);
  delay(2000);
  analogWrite(redLED, 0);
  red = analogRead(photoSensor) - black;
  delay(2000);
  analogWrite(redLED, 255);
  delay(2000);
  analogWrite(blueLED, 0);
  blue = analogRead(photoSensor) - black;
  delay(2000);
  analogWrite(blueLED, 255);
  delay(2000);
  analogWrite(greenLED, 0);
  green = analogRead(photoSensor) - black;
  delay(2000);
  analogWrite(greenLED, 255);
}

string Color::getDominantColor() {
  if ( red > blue and red > green) {
    return "red";
  }
  else if ( blue > red and blue > green) {
    return "blue";
  }
  else if ( green > red and green > blue) {
    return "green";
  }
  else {
    return "All colors are the same value.";
  }
}


void Color::Print() {

  cout << "The color was: " << "r: " << red << " g: " << green << " b: " << blue << endl;

}













