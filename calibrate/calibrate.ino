#include <ArduinoSTL.h>

using namespace std;

const int lightSensor = A0;

void setup() {
  Serial.begin(9600);
}


void getSamples(vector<int> &samples, int sampleCount) {
  for (int i; i < sampleCount; i++) {
    samples.push_back(analogRead(lightSensor));
  }
}

void sortSamples(vector<int> &samples) {
  
  bool swap = true;
  while (swap) {
    swap = false;
    for (size_t i = 0; i < samples.size() - 1; i++) {
      if (samples[i] > samples[i + 1] ) {
        samples[i] += samples[i + 1];
        samples[i + 1] = samples[i] - samples[i + 1];
        samples[i] -= samples[i + 1];
        swap = true;
      }
    }
  }
}

void Print(vector<int> samples) {
  for (size_t i = 0;  i < samples.size();  i++) {
    cout << samples[i] << " ";

  }
  cout << endl;
}

void loop() {
  cout << "Enter how many samples to take for calibration." << endl;
  int sampleCount;
  cin >> sampleCount;

  // Get samples from the light sensor...
  vector<int> samples;
  getSamples(samples, sampleCount);
  
  // Sort the samples that were retrieved...
  sortSamples(samples);
  // Print the information about the samples...
  Print(samples);
  cout << "There are " << samples.size() << " samples." << endl;
  cout << "The minimum sample is: " << samples[0] << endl;
  cout << "The maximum sample is: " << samples[samples.size() - 1] << endl;
  cout << "The median sample is: " << samples[samples.size() / 2] << endl;
}


















