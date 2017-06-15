#include <ArduinoSTL.h>

using namespace std;

const int lightSensor = A0;
const int pressureSensor = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensor, count;
  cout << "Enter which sensor to read: 1 for light 2 for pressure." << endl;
  cin >> sensor;
  cout << "Enter how many readings to take." << endl;
  cin >> count;
  int readings[count];
  getSensorReadings(sensor, readings, count);

  cout << "max: " << maxReading(sensor, readings, count) << endl;
  cout << "min: " << minReading(sensor, readings, count) << endl;
  cout << "avg: " << avgReading(sensor, readings, count) << endl;
}

void getSensorReadings(int sensor, int readings[], int count) {

  if (sensor == 1) {
    for (int i; i < count; i++) {
      readings[i] = analogRead(A0);
    }
  }
  else if (sensor == 2) {
    for (int i; i < count; i++) {
      readings[i] = analogRead(A1);
    }
  }
}

int maxReading (int sensor, int readings[], int count) {
  int max;
  if (sensor == 1) {
    for (int i; i < count; i++) {
      if ( max < readings[i]) {
        max = readings[i];
      }
    }
  }
  else if (sensor == 2) {
    for (int i; i < count; i++) {
      if ( max < readings[i]) {
        max = readings[i];
      }
    }
  }
  return max;
}

int minReading (int sensor, int readings[], int count) {
  int min = readings[0];
  if (sensor == 1) {
    for (int i; i < count; i++) {
      if ( min > readings[i]) {
        min = readings[i];
      }
    }
  }
  else if (sensor == 2) {
    for (int i; i < count; i++) {
      if ( min < readings[i]) {
        min = readings[i];
      }
    }
  }
  return min;
}

int avgReading (int sensor, int readings[], int count) {
  int avg;
  for (int i; i < count; i++) {
    avg += readings[i];
  }
  avg = avg / count;
  return avg;
}



















