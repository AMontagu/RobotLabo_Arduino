// 
// 
// 

#include "Servo180.h"

Servo180::Servo180(char* name, int servoPin, bool isMovingMotor, bool isRight, bool isFront)
{
	this->motorName = name;
	this->motorTypeVar = motorType::servoMotor;
	this->pin = servoPin;

	this->isSetupVar = false;

	this->isMovingMotor = isMovingMotor;
	this->isRight = isRight;
	this->isFront = isFront;

	//this->setup();
}

Servo180::Servo180(const Servo180 &    ss) : Motor(ss)
{
	this->motorName = ss.motorName;
	this->motorTypeVar = ss.motorTypeVar;
	this->pin = ss.pin;

	this->setup();
}

Servo180 &Servo180 :: operator= (const Servo180 &    ss)
{
	if (this != &ss) {
		this->motorName = ss.motorName;
		this->motorTypeVar = ss.motorTypeVar;
		this->isSetupVar = ss.isSetupVar;
		this->pin = ss.pin;

		this->setup();
	}

	return *this;
}


Servo180::~Servo180() {}

bool Servo180::setup(void) {

	myservo.attach(this->pin);

	this->isSetupVar = true;

	return this->isSetupVar;
}

bool Servo180::isSetup(void) {
	return this->isSetupVar;
}

char* Servo180::getMotorName(void) {
	return this->motorName;
}

int Servo180::getMotorType(void) {
	return this->motorTypeVar;
}

void Servo180::move(int value) {
	this->myservo.write(value);
}

void Servo180::stop()
{
	this->myservo.detach();
}

void Servo180::setSpeed(int speed) {
	this->speed = speed;
}

int Servo180::getSpeed() {
	return this->speed;
}

bool Servo180::getIsMove()
{
	return isMoveVar;
}