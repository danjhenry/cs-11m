#include <ArduinoSTL.h>
#include "Color.h"
#include <Arduino.h>

using namespace std;

Color::Color(int r, int g, int b) {
  red = r;
  green = g;
  blue = b;
}

void Color::display() {
  analogWrite(redLED, 255 - red);
  analogWrite(greenLED, 255 - green);
  analogWrite(blueLED, 255 - blue);
}
int Color::getRed() {
  return red;
}

int Color::getGreen() {
  return green;
}

int Color::getBlue() {
  return blue;
}

void Color::setRed(int r) {
  red = r;
}

void Color::setGreen(int g) {
  green = g;
}

void Color::setBlue(int b) {
  blue = b;
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














