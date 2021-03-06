#include "LightActionner.h"
#include <Servo.h>
#include "Servo180.h"
#include "Encoder.h"
#include "ColorSensorTCS3200.h"
#include "IRSharp10To80.h"
#include "IRSharp4To30.h"
#include "UltrasonicSensorHCSR04.h"
#include "MotorContinu.h"
#include "Sound.h"
#include "LightActionner.h"
#include "Robot.h"

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Adafruit_NeoPixel.h>

int gamma[] = {
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,
        1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,
        2,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  5,  5,  5,
        5,  6,  6,  6,  6,  7,  7,  7,  7,  8,  8,  8,  9,  9,  9, 10,
        10, 10, 11, 11, 11, 12, 12, 13, 13, 13, 14, 14, 15, 15, 16, 16,
        17, 17, 18, 18, 19, 19, 20, 20, 21, 21, 22, 22, 23, 24, 24, 25,
        25, 26, 27, 27, 28, 29, 29, 30, 31, 32, 32, 33, 34, 35, 35, 36,
        37, 38, 39, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 50,
        51, 52, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 66, 67, 68,
        69, 70, 72, 73, 74, 75, 77, 78, 79, 81, 82, 83, 85, 86, 87, 89,
        90, 92, 93, 95, 96, 98, 99,101,102,104,105,107,109,110,112,114,
        115,117,119,120,122,124,126,127,129,131,133,135,137,138,140,142,
        144,146,148,150,152,154,156,158,160,162,164,167,169,171,173,175,
        177,180,182,184,186,189,191,193,196,198,200,203,205,208,210,213,
        215,218,220,223,225,228,231,233,236,239,241,244,247,249,252,255 };

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *_motorFrontRight = AFMS.getMotor(1);
Adafruit_DCMotor *_motorFrontLeft = AFMS.getMotor(2);
Adafruit_DCMotor *_motorBackRight = AFMS.getMotor(3);
Adafruit_DCMotor *_motorBackLeft = AFMS.getMotor(4);

MotorContinu motorFrontRight("motorFrontRight", _motorFrontRight, true, true, true);
MotorContinu motorFrontLeft("motorFrontLeft", _motorFrontLeft, true, false, true);
MotorContinu motorBackRight("motorBackRight", _motorBackRight, true, true, false);
MotorContinu motorBackLeft("motorBackLeft", _motorBackLeft, true, false, false);

Servo180 servoHand("servoHand", 10, false, false, false);
Servo180 servoArm("servoArm", 9, false, false, false);

UltrasonicSensorHCSR04 ultrasonicFront("distanceFront", 53, 52);
UltrasonicSensorHCSR04 ultrasonicBack("distanceBack", 49, 48);
UltrasonicSensorHCSR04 ultrasonicLeft("distanceLeft", 45, 44);
UltrasonicSensorHCSR04 ultrasonicRight("distanceRight", 41, 40);


int s0=3,s1=4,s2=5,s3=6;
int out=2;
ColorSensorTCS3200 myColorSensor("colorRight", s0, s1, s2, s3, out);

Sound mySound("melody", 30);
LightActionner la("light", 34, 16, 50, gamma, 115200, NEO_GRBW, NEO_KHZ800);

Motor* motorTab[6] = { &motorFrontRight, &motorFrontLeft, &motorBackRight, &motorBackLeft, &servoHand, &servoArm};
Sensor* sensorTab[5] = {&ultrasonicFront, &ultrasonicBack, &ultrasonicLeft, &ultrasonicRight, &myColorSensor};
Actioner* actionerTab[2] = {&mySound, &la};

Robot* myRobot;

void setup() {

  Serial.begin(115200);

  while (!Serial)
  {
  }

  Serial.println("begin");

  myRobot = new Robot(sensorTab, motorTab, actionerTab, true);

  Serial.println("created");

  AFMS.begin();

  /*for (int i = 0; i < 4; i++)
  {
  motorTab[i]->setup();
  }*/

  myRobot->setup();
  Serial.println("setup");
}


void loop() {

  myRobot->armDown();
  delay(3000);
  myRobot->armUp();
  delay(3000);
}
