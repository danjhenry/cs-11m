
#include <ArduinoSTL.h>

using namespace std;

const int redLED = 11;
const int greenLED = 10;
const int blueLED = 9;

class Color {

  public:

    Color() {
      cout << "Constructing a color." << endl;
    }

    Color(int r, int g, int b) {
      cout << "Constructing the color r:" << r << " g:" << g << " b:" << b << endl;
      red = r;
      green = g;
      blue = b;
    }
    int red;
    int green;
    int blue;

    void saturate() {
      int Min;
      if (red < blue and red < green) {
        Min = red;
      }
      else if (blue < red and blue < green) {
        Min = blue;
      }
      else if (green < blue and green < red) {
        Min = green;
      }
      red = red - Min;
      blue = blue - Min;
      green = green - Min;
      cout << "min: " << Min << endl;

    }
    void display() {
      analogWrite(redLED, 255 - red);
      analogWrite(greenLED, 255 - green);
      analogWrite(blueLED, 255 - blue);
    }

};

void setup() {
  Serial.begin(9600);
}

void setColor(Color c) {
  analogWrite(redLED, 255 - c.red);
  analogWrite(greenLED, 255 - c.green);
  analogWrite(blueLED, 255 - c.blue);
}

void loop() {

  Color(64, 128, 256);
  Color(32, 125, 200);

  c.saturate();
  b.saturate();

  setColor(c);
  delay(3000);
  setColor(b);
  delay(3000);

}
