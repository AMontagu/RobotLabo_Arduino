#include "UltrasonicSensorHCSR04.h"

UltrasonicSensorHCSR04::UltrasonicSensorHCSR04(char* name, int triggerPin, int echoPin)
{
	this->sensorName = name;
	this->sensorFamilyVar = distanceSensor;
	this->sensorTypeVar = ultrason;
	this->triggerPin = triggerPin;
	this->echoPin = echoPin;

	this->isSetupVar = false;

	//this->setup();
}

UltrasonicSensorHCSR04::UltrasonicSensorHCSR04(const UltrasonicSensorHCSR04 &    ss): Sensor(ss)
{
	this->sensorFamilyVar = ss.sensorFamilyVar;
	this->sensorName = ss.sensorName;
	this->sensorTypeVar = ss.sensorTypeVar;
	this->triggerPin = ss.triggerPin;
	this->echoPin = ss.echoPin;

	this->setup();
}

UltrasonicSensorHCSR04 &UltrasonicSensorHCSR04 :: operator= (const UltrasonicSensorHCSR04 &    ss)
{
	if (this != &ss) {
		this->sensorFamilyVar = ss.sensorFamilyVar;
		this->sensorName = ss.sensorName;
		this->sensorTypeVar = ss.sensorTypeVar;
		this->isSetupVar = ss.isSetupVar;
		this->echoPin = ss.echoPin;
		this->triggerPin = ss.triggerPin;

		this->setup();
	}

	return *this;
}


UltrasonicSensorHCSR04::~UltrasonicSensorHCSR04() {}

bool UltrasonicSensorHCSR04::setup(void) {

	//Initiate
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);

	digitalWrite(triggerPin, LOW); // need to be Low before taking value

	this->isSetupVar = true;

	return this->isSetupVar;
}

bool UltrasonicSensorHCSR04::isSetup(void) {
	return this->isSetupVar;
}

int UltrasonicSensorHCSR04::getValue(void) {
	/* send an HIGH signal for 10�s on the trigger pin */
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);

	/* 2) Get time between sending impulsion ans echo (if exist) */
	long measure = pulseIn(echoPin, HIGH, MEASURE_TIMEOUT);

	/* Calcul distance from time elapsed */
	long distance = measure / 2 * 0.034; // in cm

	/* If debug is true print the distance */
	/*Serial.print("Distance for ");
	Serial.println(this->sensorName);
	Serial.println(distance);*/

	//delayMicroseconds(30); // if necessary in your code to calm down sensor

	return (int)distance;
}

long UltrasonicSensorHCSR04::getPrecisionValue(void) {
	/* send an HIGH signal for 10�s on the trigger pin */
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);

	/* 2) Get time between sending impulsion ans echo (if exist) */
	long measure = pulseIn(echoPin, HIGH, MEASURE_TIMEOUT);

	/* Calcul distance from time elapsed */
	long distance = measure / 2.0 * 0.034; // in cm

	/* If debug is true print the distance */
	/*Serial.print("Distance for ");
	Serial.println(this->sensorName);
	Serial.println(distance);*/

	//delayMicroseconds(30); // if necessary in your code to calm down sensor

	return distance;
}

void UltrasonicSensorHCSR04::reset(void) {}

char* UltrasonicSensorHCSR04::getSensorName(void) {
	return this->sensorName;
}

int UltrasonicSensorHCSR04::getSensorType(void) {
	return this->sensorTypeVar;
}

int UltrasonicSensorHCSR04::getSensorFamily(void) {
	return this->sensorFamilyVar;
}

