#include <IRremote.h>
#include <IRremoteInt.h>
#include <Arduino.h>
#include <Servo.h>
class Motor {
  public:
    void Initialize();
    void IRcaller();
    void adjustMove(int angle, Servo servo);
    void moveUp(int degree, Servo servo, int start, bool Switch, int servoPin);
    void moveDown(int degree, Servo servo, int start, bool Switch, int servoPin);
    void clawOpen();
    void clawClosed();
    void powerButton();
    void chooser();

  private:
    //set servo pins to servo variables.
    const int servoPin5 = 5;
    const int servoPin3 = 3;
    const int servoPin9 = 9;
    const int servoPin10 = 10;
    //initialize servos.
    Servo servoArm;
    Servo servoArmMain;
    Servo servoBase;
    Servo servoClaw;
    //initialize time variable.
    int Time;
    //initialize home positions in degrees

    int baseStart = 90;
    const int baseHome = 90;
    int armMainStart = 65;
    const int armMainhome = 65;
    int armStart = 180;
    const int armHome = 180;
    //initialize part bool's for loop continuance.
    bool base = true;
    bool mainArm = true;
    bool Arm = true;

};




