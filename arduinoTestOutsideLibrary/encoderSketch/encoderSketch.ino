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

int encoderPinA = 18;
int encoderPinB =  19;

int QEM [16] = {0,-1,1,2,1,0,2,-1,-1,2,0,1,2,1,-1,0};               // Quadrature Encoder Matrix

volatile unsigned char Old0, New0;
volatile long Position0 = 0;

void isr(){
  int readPinA = digitalRead(encoderPinA);
  int readPinB = digitalRead(encoderPinB);

  /*Serial.print("pina = ");
  Serial.print(readPinA);
  
  Serial.print(", pinb = ");
  Serial.println(readPinB);

  Serial.println("");*/

  Old0 = New0;
  New0 = readPinA * 2 + readPinB;           // Convert binary input to decimal value
  Position0 += QEM [Old0 * 4 + New0];

  Serial.print("position = ");
  Serial.println(Position0);
}

void setup(){

  Serial.begin(115200);                            //init the Serial port to print the date

  New0 = 0;
  
  pinMode(encoderPinA, INPUT);
  pinMode(encoderPinB, INPUT);
  
  
  attachInterrupt(digitalPinToInterrupt(encoderPinA), isr, CHANGE);    //init the interrupt mode for the digital pin 2
  attachInterrupt(digitalPinToInterrupt(encoderPinB), isr, CHANGE);   //init the interrupt mode for the digital pin 3
  
}

void loop(){
}


