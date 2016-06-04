// MotorContinu.cpp

#include "MotorContinu.h"


MotorContinu::MotorContinu(char* name,  Adafruit_DCMotor* motorIn, bool isMovingMotor, bool isRight, bool isFront)
{
	motorTypeVar = motorType::courantContinu;
	this->port = port;
	this->motorName = name;

	this->myMotor = motorIn;

	this->isMovingMotor = isMovingMotor;
	this->isRightVar = isRight;
	this->isFront = isFront;

	//this->setup();*/
}


bool MotorContinu::setup(void)
{
	/*if (AFMS == NULL) {
		Serial.println("AFMS is null");
	}*/
	//AFMS.begin();

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
	

	if (value >= 0) {
		myMotor->setSpeed(value);
		myMotor->run(FORWARD);
	}
	else
	{
		myMotor->setSpeed(-value);
		myMotor->run(BACKWARD);
	}
}

void MotorContinu::stop() 
{
	this->myMotor->run(RELEASE);
}

bool MotorContinu::getIsMove()
{
	return isMoveVar;
}

void MotorContinu::setSpeed(int speed) {
	this->speed = speed;
}

int MotorContinu::getSpeed() {
	return this->speed;
}
