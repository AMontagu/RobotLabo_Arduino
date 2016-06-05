#include "IRSharp4To30.h"

IRSharp4To30::IRSharp4To30(char* name, int analogPin, bool isFront, bool isRight)
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

IRSharp4To30::IRSharp4To30(const IRSharp4To30 &    ss) : Sensor(ss)
{
	this->sensorFamilyVar = ss.sensorFamilyVar;
	this->sensorName = ss.sensorName;
	this->sensorTypeVar = ss.sensorTypeVar;
	this->analogPin = ss.analogPin;

	this->isFront = ss.isFront;
	this->isRight = ss.isRight;

	this->setup();
}

IRSharp4To30 &IRSharp4To30 :: operator= (const IRSharp4To30 &    ss)
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


IRSharp4To30::~IRSharp4To30() {}

bool IRSharp4To30::setup(void) {

	//Initiate
	pinMode(analogPin, INPUT);

	this->isSetupVar = true;

	return this->isSetupVar;
}

bool IRSharp4To30::isSetup(void) {
	return this->isSetupVar;
}

int IRSharp4To30::getValue(void) {
	int compteur = 0, valeurPlusProcheCentimetre = 100, valeurPlusProcheZero = 1025;
	int valeurCompare[8] = {};
	int analogValue = analogRead(analogPin);
	for (compteur = 0; compteur < 8; compteur++)
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

long IRSharp4To30::getPrecisionValue(void) {
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

void IRSharp4To30::reset(void) {}

char* IRSharp4To30::getSensorName(void) {
	return this->sensorName;
}

int IRSharp4To30::getSensorType(void) {
	return this->sensorTypeVar;
}

int IRSharp4To30::getSensorFamily(void) {
	return this->sensorFamilyVar;
}


