// MotorContinu.cpp

#include "MotorContinu.h"


MotorContinu::MotorContinu(Adafruit_DCMotor* motorIn)
{
	motorTypeVar = courantContinu;
	this->port = port;

	this->myMotor = motorIn;

	//this->setup();*/
}


bool MotorContinu::setup(void)
{
	myMotor->setSpeed(150);
	myMotor->run(FORWARD);
	// turn on motor
	myMotor->run(RELEASE);

	Serial.println("okay2");
}

bool MotorContinu::isSetup(void)
{
	return isSetupVar;
}

char* MotorContinu::getMotorName(void) {
	return this->motorName;
}

int MotorContinu::getMotorType(void) {
	return this->motorTypeVar;
}

void MotorContinu::move(int value)
{
	this->isMoveVar = true;

	uint8_t i;

	Serial.print("tick");

	if (myMotor == NULL) {
		Serial.print("is null");
	}

	myMotor->run(FORWARD);
	for (i = 0; i<255; i++) {
		myMotor->setSpeed(i);
		delay(10);
	}
	for (i = 255; i != 0; i--) {
		myMotor->setSpeed(i);
		delay(10);
	}

	Serial.print("tock");

	myMotor->run(BACKWARD);
	for (i = 0; i<255; i++) {
		myMotor->setSpeed(i);
		delay(10);
	}
	for (i = 255; i != 0; i--) {
		myMotor->setSpeed(i);
		delay(10);
	}

	Serial.print("tech");
	myMotor->run(RELEASE);
	delay(1000);
}

bool MotorContinu::getIsMove()
{
	return isMoveVar;
}

void MotorContinu::setSpeeda(int speed) {
	this->speed = speed;
}

int MotorContinu::getSpeed() {
	return this->speed;
}
