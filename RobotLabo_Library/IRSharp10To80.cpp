#include "IRSharp10To80.h"

IRSharp10To80::IRSharp10To80(char* name, int analogPin, bool isFront, bool isRight)
{
	this->sensorName = name;
	this->sensorFamilyVar = sensorFamily::distanceSensor;
	this->sensorTypeVar = sensorType::infrared;
	this->analogPin = analogPin;

	this->isFront = isFront;
	this->isRight = isRight;

	this->isSetupVar = false;

	//this->setup();
}

IRSharp10To80::IRSharp10To80(const IRSharp10To80 &    ss) : Sensor(ss)
{
	this->sensorFamilyVar = ss.sensorFamilyVar;
	this->sensorName = ss.sensorName;
	this->sensorTypeVar = ss.sensorTypeVar;
	this->analogPin = ss.analogPin;

	this->isFront = ss.isFront;
	this->isRight = ss.isRight;

	this->setup();
}

IRSharp10To80 &IRSharp10To80 :: operator= (const IRSharp10To80 &    ss)
{
	if (this != &ss) {
		this->sensorFamilyVar = ss.sensorFamilyVar;
		this->sensorName = ss.sensorName;
		this->sensorTypeVar = ss.sensorTypeVar;
		this->isSetupVar = ss.isSetupVar;
		this->analogPin = ss.analogPin;

		this->isFront = ss.isFront;
		this->isRight = ss.isRight;

		this->setup();
	}

	return *this;
}


IRSharp10To80::~IRSharp10To80() {}

bool IRSharp10To80::setup(void) {

	//Initiate
	pinMode(analogPin, INPUT);

	this->isSetupVar = true;

	return this->isSetupVar;
}

bool IRSharp10To80::isSetup(void) {
	return this->isSetupVar;
}

int IRSharp10To80::getValue(void) {
	int compteur = 0, valeurPlusProcheCentimetre = 100, valeurPlusProcheZero = 1025;
	int valeurCompare[arraySize] = {};
	int analogValue = analogRead(analogPin);
	for (compteur = 0; compteur < arraySize; compteur++)
	{
		valeurCompare[compteur] = abs(analogValue - tableauValeur[compteur]);
		if (valeurCompare[compteur] < valeurPlusProcheZero)
		{
			valeurPlusProcheZero = valeurCompare[compteur];
			if (compteur < 4) {
				valeurPlusProcheCentimetre = compteur * 5 + 5;
			}
			else {
				valeurPlusProcheCentimetre = (compteur - 2) * 10 + 10;
			}
		}
	}
	//Serial.println(valeurPlusProcheCentimetre);

	return valeurPlusProcheCentimetre;
}

long IRSharp10To80::getPrecisionValue(void) {
	float distance = 0, volt = 0;
	int analogValue = analogRead(analogPin);
	volt = analogValue*0.0048828125;
	//distance = 1 / (volt / 24 - 0.1);
	distance = 1 / (volt / this->ratio);
	/*Serial.println(F("valeur recu par le capteur = "));
	Serial.println(analogValue);
	Serial.println(F("valeur en volt = "));
	Serial.println(volt);
	Serial.println(F("distance = "));
	Serial.println(distance);*/

	return distance;
}

void IRSharp10To80::reset(void) {}

char* IRSharp10To80::getSensorName(void) {
	return this->sensorName;
}

int IRSharp10To80::getSensorType(void) {
	return this->sensorTypeVar;
}

int IRSharp10To80::getSensorFamily(void) {
	return this->sensorFamilyVar;
}


