// 
// 
// 

#include "Encoder.h"

Encoder::Encoder(char* name, int interruptPin)
{
	this->sensorName = name;
	this->sensorFamilyVar = sensorFamily::encoderSensor;
	this->sensorTypeVar = sensorType::encoder;
	this->interruptPin = interruptPin;

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
	attachInterrupt(this->interruptPin, this->getEncoder, CHANGE);

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

void Encoder::getEncoder() {
	this->counter++;
}

