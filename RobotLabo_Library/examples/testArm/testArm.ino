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



Servo180 servoHand("servoHand", 10, false, false, false);
Servo180 servoArm("servoArm", 9, false, false, false);

int pos = 90;    // variable to store the servo position

void setup() {

	Serial.begin(115200);

	while (!Serial)
	{}

	Serial.println("begin");


    servoHand.setup();
    servoArm.setup();
}


void loop() {
    for (pos = 90; pos <= 135; pos += 1) { // goes from 0 degrees to 180 degrees
        // in steps of 1 degree
        servoHand.move(pos);              // tell servo to go to position in variable 'pos'
        servoArm.move(pos);              // tell servo to go to position in variable 'pos'

        delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 135; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
        servoHand.move(pos);              // tell servo to go to position in variable 'pos'

        servoArm.move(pos);              // tell servo to go to position in variable 'pos'

        delay(15);                       // waits 15ms for the servo to reach the position
    }
}

