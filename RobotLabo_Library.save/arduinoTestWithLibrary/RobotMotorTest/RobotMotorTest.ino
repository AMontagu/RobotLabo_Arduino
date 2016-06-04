#include "LightActionner.h"
#include <Servo.h>
#include "Servo180.h"
#include "Encoder.h"
#include "ColorSensorTCS3200.h"
#include "IRSharp10To80.h"
#include "UltrasonicSensorHCSR04.h"
#include "MotorContinu.h"
#include "Sound.h"
#include "LightActionner.h"
#include "Robot.h"

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Adafruit_NeoPixel.h>


Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *_motorFrontRight = AFMS.getMotor(1);
Adafruit_DCMotor *_motorFrontLeft = AFMS.getMotor(2);
Adafruit_DCMotor *_motorBackRight = AFMS.getMotor(3);
Adafruit_DCMotor *_motorBackLeft = AFMS.getMotor(4);

MotorContinu motorFrontRight("motorFrontRight", _motorFrontRight, true, true, true);
MotorContinu motorFrontLeft("motorFrontLeft", _motorFrontLeft, true, false, true);
MotorContinu motorBackRight("motorBackRight", _motorBackRight, true, true, false);
MotorContinu motorBackLeft("motorBackLeft", _motorBackLeft, true, false, false);

Motor* motorTab[4] = { &motorFrontRight, &motorFrontLeft, &motorBackRight, &motorBackLeft};
Sensor* sensorTab[] = {};
Actioner* actionerTab[] = {};

Robot myRobot(sensorTab, motorTab, actionerTab, true);

void setup() {
  
  Serial.begin(115200);

  while (!Serial)
  {}

  Serial.println("begin");

  AFMS.begin();
  myRobot.setup();
}


void loop() {

  Serial.println("forward");
  
  myRobot.forward(150);

  delay(3000);

  Serial.println("backward");

  myRobot.backward(150);

  delay(3000);

  Serial.println("stop");

  myRobot.stop();

  delay(3000);
}

