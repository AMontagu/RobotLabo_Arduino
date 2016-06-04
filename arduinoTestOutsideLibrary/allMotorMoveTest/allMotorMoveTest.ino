#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motorFrontRight = AFMS.getMotor(1);
Adafruit_DCMotor *motorFrontLeft = AFMS.getMotor(2);
Adafruit_DCMotor *motorBackRight = AFMS.getMotor(3);
Adafruit_DCMotor *motorBackLeft = AFMS.getMotor(4);

int speedMotor = 150;

void setup() {
  Serial.begin(9600);
  Serial.println("Adafruit Motorshield v2 - DC Motor test!");

  AFMS.begin();  // create with the default frequency 1.6KHz
  
  motorFrontRight->setSpeed(150);
  motorFrontRight->run(FORWARD);
  motorFrontRight->run(RELEASE);

  motorFrontLeft->setSpeed(150);
  motorFrontLeft->run(FORWARD);
  motorFrontLeft->run(RELEASE);

  motorBackRight->setSpeed(150);
  motorBackRight->run(FORWARD);
  motorBackRight->run(RELEASE);

  motorBackLeft->setSpeed(150);
  motorBackLeft->run(FORWARD);
  motorBackLeft->run(RELEASE);
}

void loop() {
  
  motorFrontRight->setSpeed(speedMotor);
  motorFrontLeft->setSpeed(speedMotor);
  motorBackRight->setSpeed(speedMotor);
  motorBackLeft->setSpeed(speedMotor);
  
  motorFrontRight->run(FORWARD);
  motorFrontLeft->run(FORWARD);
  motorBackRight->run(FORWARD);
  motorBackLeft->run(FORWARD);

  delay(3000);
  
  motorFrontRight->run(RELEASE);
  motorFrontLeft->run(RELEASE);
  motorBackRight->run(RELEASE);
  motorBackLeft->run(RELEASE);
  
  delay(1000);
}

