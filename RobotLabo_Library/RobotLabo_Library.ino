/*
 Name:		RobotLabo_Library.ino
 Created:	13/05/2016 20:02:48
 Author:	Adrien
 Editor:	http://www.visualmicro.com
*/

//#include "RobotLabo_LibraryLib.h"
#include <Servo.h>
#include "Servo180.h"
#include "Encoder.h"
#include "ColorSensorTCS3200.h"
#include "IRSharp10To80.h"
#include "UltrasonicSensorHCSR04.h"
#include "MotorContinu.h"

//UltrasonicSensorHCSR04 myFirstSensor("firstSensor", 8, 9);
//IRSharp10To80 myIrSensor("myIrSensor", 0);
//ColorSensorTCS3200 myColorSensor("myColorSensor", 8, 9, 10, 11, 2);
//Encoder myEncoder("myEncoder", 18, true);
//Servo180 myServo("myServo", 9);
MotorContinu myMotor(1);
int pos;

// the setup function runs once when you press reset or power the board
void setup() {
	
	Serial.begin(115200);

	while (!Serial)
	{}

	Serial.println("serial");

	//myFirstSensor.setup();
	//myIrSensor.setup();
	//myColorSensor.setup();
	//myEncoder.setup();
	myMotor.setup();
}

// the loop function runs over and over again until power down or reset
void loop() {
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

	myMotor.move(255);
	

	delay(1000);
}
