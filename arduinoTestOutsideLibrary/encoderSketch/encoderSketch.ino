#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

#define LEFT 19
#define RIGHT 18

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

volatile int coderLeft = 0;
volatile int coderRight = 0;

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *motorLeft = AFMS.getMotor(1);
Adafruit_DCMotor *motorRight = AFMS.getMotor(2);

void setup(){

  Serial.begin(9600);                            //init the Serial port to print the data
  attachInterrupt(digitalPinToInterrupt(LEFT), LwheelSpeed, RISING);    //init the interrupt mode for the digital pin 2
  attachInterrupt(digitalPinToInterrupt(RIGHT), RwheelSpeed, RISING);   //init the interrupt mode for the digital pin 3

  AFMS.begin();
  
  motorLeft->setSpeed(50);
  motorLeft->run(FORWARD);
  motorLeft->run(RELEASE);

  motorRight->setSpeed(50);
  motorRight->run(FORWARD);
  motorRight->run(RELEASE);

  motorLeft->run(FORWARD);
  motorRight->run(FORWARD);
}

void loop(){

  static unsigned long timer = 0;                //print manager timer

  if(millis() - timer > 1000){                   
    Serial.print("Coder value: ");
    Serial.print(coderLeft);
    Serial.print("[Left Wheel] ");
    Serial.print(coderRight);
    Serial.println("[Right Wheel]");
    
    timer = millis();
  }

}


void LwheelSpeed()
{
  coderLeft ++;  //count the left wheel encoder interrupts
}


void RwheelSpeed()
{
  coderRight ++; //count the right wheel encoder interrupts
}


