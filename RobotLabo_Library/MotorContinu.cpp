// MotorContinu.cpp

#include "MotorContinu.h"


MotorContinu::MotorContinu(int port)
{
	motorTypeVar = motorType::courantContinu;
	this->port = port;
	afms = Adafruit_MotorShield();

	this->motor = afms.getMotor(port);

	this->setup();
}


bool MotorContinu::setup(void)
{
	afms.begin();

	motor->setSpeed(150);
	motor->run(FORWARD);
	delay(1000);
	// turn on motor
	motor->run(RELEASE);

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
	motor->run(FORWARD);
	for (int i = 0; i < value; ++i)
	{
		motor->setSpeed(i);
	}

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