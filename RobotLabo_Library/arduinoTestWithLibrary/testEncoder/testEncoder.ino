#include <Actioner.h>
#include <ColorSensorTCS3200.h>
#include <Encoder.h>
#include <IRSharp10To80.h>
#include <LightActionner.h>
#include <Motor.h>
#include <MotorContinu.h>
#include <resource.h>
#include <Sensor.h>
#include <Servo180.h>
#include <Sound.h>
#include <UltrasonicSensorHCSR04.h>

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"


Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *_motorFrontRight = AFMS.getMotor(1);
Adafruit_DCMotor *_motorFrontLeft = AFMS.getMotor(2);

MotorContinu motorFrontRight("motorFrontRight", _motorFrontRight);
MotorContinu motorFrontLeft("motorFrontLeft", _motorFrontLeft);

Encoder rightEncoder("myEncoder", 18, true);
Encoder leftEncoder("myEncoder", 19, true);

void setup() {
  Serial.begin(9600); 

  AFMS.begin();
  motorFrontRight.setup();
  motorFrontLeft.setup();

  rightEncoder.setup();
  leftEncoder.setup();

  motorFrontRight.move(-150);
  motorFrontLeft.move(-150);
}

void loop() {
  Serial.print("rightEncoder = ");
  Serial.println(rightEncoder.getValue());
  Serial.print("leftEncoder = ");
  Serial.println(leftEncoder.getValue());
  delay(1000);
}