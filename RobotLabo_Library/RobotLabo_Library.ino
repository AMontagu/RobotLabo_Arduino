#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

/*
 Name:		RobotLabo_Library.ino
 Created:	13/05/2016 20:02:48
 Author:	Adrien
 Editor:	http://www.visualmicro.com
*/

#include <Servo.h>
#include "Servo180.h"
#include "Encoder.h"
#include "ColorSensorTCS3200.h"
#include "IRSharp10To80.h"
#include "UltrasonicSensorHCSR04.h"
#include "MotorContinu.h"
#include "Sound.h"



// Create the motor shield object with the default I2C address
//Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

//UltrasonicSensorHCSR04 myFirstSensor("firstSensor", 8, 9);
//IRSharp10To80 myIrSensor("myIrSensor", 0);
//ColorSensorTCS3200 myColorSensor("myColorSensor", 8, 9, 10, 11, 2);
//Encoder myEncoder("myEncoder", 18, true);
//Servo180 myServo("myServo", 9);
MotorContinu myMotorContinu(myMotor);
  //Sound mySound("melody", 30);
//int pos;

// the setup function runs once when you press reset or power the board
void setup() {
	//mySound.setup();
	Serial.begin(115200);

	while (!Serial)
	{}

	Serial.println("serial");


	AFMS.begin();

	//myFirstSensor.setup();
	//myIrSensor.setup();
	//myColorSensor.setup();
	//myEncoder.setup();
	myMotorContinu.setup();
    
}

// the loop function runs over and over again until power down or reset
void loop() {
  //mySound.doAction();
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

	//myMotor.move(-255);


	//delay(1000);
}

