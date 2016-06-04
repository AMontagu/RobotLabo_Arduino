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

void setup() {
	
	Serial.begin(115200);

	while (!Serial)
	{}

	Serial.println("begin");

	AFMS.begin();
	motorFrontRight.setup();
  motorFrontLeft.setup();
  motorBackRight.setup();
  motorBackLeft.setup();
}


void loop() {
	motorFrontRight.move(150);
  motorFrontLeft.move(150);
  motorBackRight.move(150);
  motorBackLeft.move(150);

  delay(3000);

  motorFrontRight.stop();
  motorFrontLeft.stop();
  motorBackRight.stop();
  motorBackLeft.stop();

  delay(2000);
}

