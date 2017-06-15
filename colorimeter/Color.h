#include <Arduino.h>
#include <ArduinoSTL.h>
using namespace std;
class Color {
  public:
    Color();
    Color(int r, int g, int b);
    void display();
    int getRed();
    int getGreen();
    int getBlue();
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    string getDominantColor();

  private:
    int red;
    int green;
    int blue;
    const int redLED = 11;
    const int greenLED = 10;
    const int blueLED = 9;
};

