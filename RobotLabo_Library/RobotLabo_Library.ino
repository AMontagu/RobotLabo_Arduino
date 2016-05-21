/*
 Name:		RobotLabo_Library.ino
 Created:	13/05/2016 20:02:48
 Author:	Adrien
 Editor:	http://www.visualmicro.com
*/

//#include "RobotLabo_LibraryLib.h"
#include "ColorSensorTCS3200.h"
#include "IRSharp10To80.h"
#include "UltrasonicSensorHCSR04.h"

//UltrasonicSensorHCSR04 myFirstSensor("firstSensor", 8, 9);
//IRSharp10To80 myIrSensor("myIrSensor", 0);
ColorSensorTCS3200 myColorSensor("myColorSensor", 8, 9, 10, 11, 2);

// the setup function runs once when you press reset or power the board
void setup() {
	//myFirstSensor.setup();
	//myIrSensor.setup();
	myColorSensor.setup();
	Serial.begin(115200);

	while (!Serial)
	{
		Serial.print(".");
	}
}

// the loop function runs over and over again until power down or reset
void loop() {
	/*if (myFirstSensor.isSetup()) {
		Serial.println(myFirstSensor.getValue());
	}*/

	/*if (myIrSensor.isSetup()) {
		Serial.println(myIrSensor.getValue());
		delayMicroseconds(100);
		//myIrSensor.getPrecisionValue();
		Serial.println(myIrSensor.getPrecisionValue());
	}*/
	Serial.println("blibli");
	Serial.println(myColorSensor.isSetup());
	if (myColorSensor.isSetup()) {
		Serial.println("before get value");
		myColorSensor.getValue();
	}

	Serial.println("blabla");
	delay(1000);
}
