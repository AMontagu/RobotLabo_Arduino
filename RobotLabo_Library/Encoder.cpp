// 
// 
// 

#include "Encoder.h"

Encoder* encoderRight;
Encoder* encoderLeft;

Encoder::Encoder(char* name, int interruptPin, bool isRight)
{
	this->sensorName = name;
	this->sensorFamilyVar = encoderSensor;
	this->sensorTypeVar = encoder;
	this->interruptPin = interruptPin;
	this->isRight = isRight;

	this->isSetupVar = false;

	//this->setup();
}

Encoder::Encoder(const Encoder &    ss) : Sensor(ss)
{
	this->sensorFamilyVar = ss.sensorFamilyVar;
	this->sensorName = ss.sensorName;
	this->sensorTypeVar = ss.sensorTypeVar;
	this->interruptPin = ss.interruptPin;

	this->setup();
}

Encoder &Encoder :: operator= (const Encoder &    ss)
{
	if (this != &ss) {
		this->sensorFamilyVar = ss.sensorFamilyVar;
		this->sensorName = ss.sensorName;
		this->sensorTypeVar = ss.sensorTypeVar;
		this->interruptPin = ss.interruptPin;

		this->setup();
	}

	return *this;
}


Encoder::~Encoder() {}

bool Encoder::setup(void) {

	//Initiate
	if (this->isRight)
	{
		encoderRight = this;
		attachInterrupt(this->interruptPin, getEncoderRight, CHANGE);
	}
	if (!this->isRight)
	{
		encoderLeft = this;
		attachInterrupt(this->interruptPin, getEncoderLeft, CHANGE);
	}
	

	this->isSetupVar = true;

	return this->isSetupVar;
}

bool Encoder::isSetup(void) {
	return this->isSetupVar;
}

int Encoder::getValue(void) {
	return this->counter;
}

long Encoder::getPrecisionValue(void) {
	return this->counter;
}

void Encoder::reset(void) {
	this->counter = 0;
}

char* Encoder::getSensorName(void) {
	return this->sensorName;
}

int Encoder::getSensorType(void) {
	return this->sensorTypeVar;
}

int Encoder::getSensorFamily(void) {
	return this->sensorFamilyVar;
}

void getEncoderLeft() {
	if (!encoderLeft) {
		encoderLeft->counter++;
	}
}

void getEncoderRight() {
	if (!encoderRight) {
		encoderRight->counter++;
	}
}

void attachInterruptHack(int pin, bool isRight) {
	if (isRight)
	{
		attachInterrupt(pin, getEncoderRight, CHANGE);
	}
	if (!isRight)
	{
		attachInterrupt(pin, getEncoderLeft, CHANGE);
	}
}


