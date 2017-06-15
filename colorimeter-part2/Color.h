#include <Arduino.h>
#include <ArduinoSTL.h>
using namespace std;
class Color {
  public:
    void setOutput();
    void turnOff();
    void calibrate();
    void Print();
    string getDominantColor();

  private:
    const int redLED = 11;
    const int greenLED = 10;
    const int blueLED = 9;
    const int photoSensor = A0;
    int black;
    int red;
    int blue;
    int green;

};

