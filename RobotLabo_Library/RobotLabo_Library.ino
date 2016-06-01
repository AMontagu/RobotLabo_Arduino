<<<<<<< HEAD
=======
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

>>>>>>> master
/*
 Name:		RobotLabo_Library.ino
 Created:	13/05/2016 20:02:48
 Author:	Adrien
 Editor:	http://www.visualmicro.com
*/

<<<<<<< HEAD
//#include "RobotLabo_LibraryLib.h"
#include "LightActionner.h"
=======
>>>>>>> master
#include <Servo.h>
#include "Servo180.h"
#include "Encoder.h"
#include "ColorSensorTCS3200.h"
#include "IRSharp10To80.h"
#include "UltrasonicSensorHCSR04.h"
#include "MotorContinu.h"
#include "Sound.h"
#include "LightActionner.h"

<<<<<<< HEAD
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Adafruit_NeoPixel.h>
=======

>>>>>>> master

// Create the motor shield object with the default I2C address
//Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
//Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

//UltrasonicSensorHCSR04 myFirstSensor("firstSensor", 8, 9);
//IRSharp10To80 myIrSensor("myIrSensor", 0);
//ColorSensorTCS3200 myColorSensor("myColorSensor", 8, 9, 10, 11, 2);
//Encoder myEncoder("myEncoder", 18, true);
//Servo180 myServo("myServo", 9);
//MotorContinu myMotorContinu(myMotor);
  Sound mySound("melody", 30);
//int pos;

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

LightActionner la = LightActionner("first", 0, 6, 60, 50, gamma, 115200, NEO_GRBW, NEO_KHZ800);

// the setup function runs once when you press reset or power the board
void setup() {
	mySound.setup();
	Serial.begin(115200);

	while (!Serial)
	{}

	Serial.println("serial");

<<<<<<< HEAD
	//la.setup();

	AFMS.begin();
=======

	//AFMS.begin();
>>>>>>> master

	//myFirstSensor.setup();
	//myIrSensor.setup();
	//myColorSensor.setup();
	//myEncoder.setup();
	//myMotorContinu.setup();
    
}

// the loop function runs over and over again until power down or reset
void loop() {
  mySound.doAction();
	Serial.println("in loop");
	/*if (myFirstSensor.isSetup()) {
	Serial.println(myFirstSensor.getValue());
	}*/

	/*if (myIrSensor.isSetup()) {
		Serial.println(myIrSensor.getValue());
		delayMicroseconds(100);
		//myIrSensor.getPrecisionValue();
		Serial.println(myIrSensor.getPrecisionValue());
	}*/
	/*Serial.println("blibli");
	Serial.println(myColorSensor.isSetup());
	if (myColorSensor.isSetup()) {
		Serial.println("before get value");
		myColorSensor.getValue();
	}

	Serial.println("blabla");*/

	/*for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
										  // in steps of 1 degree
		myServo.move(pos);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
	}
	for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
		myServo.move(pos);              // tell servo to go to position in variable 'pos'
		delay(15);                       // waits 15ms for the servo to reach the position
	}*/

	//myMotorContinu.move(255);
 
	
	

	//delay(1000);

	//myMotorContinu.move(-255);

	//la.loop();


	//delay(1000);
}

