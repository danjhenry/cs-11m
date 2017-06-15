
#include <ArduinoSTL.h>

using namespace std;

const int redLED = 11;
const int greenLED = 10;
const int blueLED = 9;

class Color {

  public:
    int red;
    int green;
    int blue;

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
  
  Color go; 
  go.red = 255;
  go.green = 0; 
  go.blue = 0; 

  Color stop; 
  stop.red = 255; 
  stop.green = 0; 
  stop.blue = 0; 
  
  Color slow; 
  slow.red = 0; 
  slow.green = 0; 
  slow.blue = 255; 
  setColor(stop);
  delay(3000);
  setColor(go);
  delay(3000);
  setColor(slow);
  delay(2000);
}
