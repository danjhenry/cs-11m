#include <ArduinoSTL.h>

using namespace std;
int volt = 5;
float vout = 0;
float buffer = 0;
float Ressistor = 10000;
float Ressistor_2 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(A1);
  if (reading)
  {
    buffer = reading * volt;
    vout = (buffer) / 1024.0;
    buffer = (volt / vout) - 1;
    Ressistor_2 = Ressistor * buffer;

    cout << "Ressistance is:" << Ressistor_2 << endl;
    delay(100);
  }
}
