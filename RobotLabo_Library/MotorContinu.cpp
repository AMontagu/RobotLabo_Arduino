// MotorContinu.cpp

#include "MotorContinu.h"


MotorContinu::MotorContinu(char* name,  Adafruit_DCMotor* motorIn, bool isMovingMotor, bool isRight, bool isFront)
{
<<<<<<< HEAD
	motorTypeVar = courantContinu;
=======
	this->motorTypeVar = motorType::courantContinu;
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
	this->port = port;
	this->motorName = name;

	this->myMotor = motorIn;

	this->isMovingMotor = isMovingMotor;
	this->isRight = isRight;
	this->isFront = isFront;

	//this->setup();*/
}

MotorContinu::MotorContinu(const MotorContinu &    ss) : Motor(ss)
{
	this->port = ss.port;
	this->motorName = ss.motorName;
	this->myMotor = ss.myMotor;
	this->isMovingMotor = ss.isMovingMotor;
	this->isRight = ss.isRight;
	this->isFront = ss.isFront;

	this->setup();
}

MotorContinu &MotorContinu :: operator= (const MotorContinu &    ss)
{
	if (this != &ss) {
		this->port = ss.port;
		this->motorName = ss.motorName;
		this->myMotor = ss.myMotor;
		this->isMovingMotor = ss.isMovingMotor;
		this->isRight = ss.isRight;
		this->isFront = ss.isFront;

		this->setup();
	}

	return *this;
}


MotorContinu::~MotorContinu() {}


bool MotorContinu::setup(void)
{
	myMotor->setSpeed(150);
	myMotor->run(FORWARD);
	// turn on motor
	myMotor->run(RELEASE);

	//Serial.println("okay2");
}

bool MotorContinu::isSetup(void)
{
	return isSetupVar;
}

char* MotorContinu::getMotorName(void) {
	return this->motorName;
}

int MotorContinu::getMotorType(void) {
	this->motorTypeVar = motorType::courantContinu;
	return this->motorTypeVar;
}

void MotorContinu::move(int value)
{
	Serial.println("move");
	this->isMoveVar = true;
<<<<<<< HEAD

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
=======
	

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
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523

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

