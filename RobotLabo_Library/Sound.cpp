#include "Sound.h"

Sound::Sound(char* name, int melodyPin)
{
	this->actionerName = name;
	this->actionerTypeVar = actionerFamily::soundActioner;
	this->melodyPin = melodyPin;
	

	this->isSetupVar = false;
}

Sound::Sound(const Sound &    ss): Sound(ss)
{
	this->actionerName = ss.actionerName;
	this->actionerTypeVar = ss.actionerTypeVar;
	this->melodyPin = ss.melodyPin;

	this->setup();
}

Sound &Sound:: operator= (const Sound &    ss)
{
	if (this != &ss) {
		this->actionerName = ss.actionerName;
		this->actionerTypeVar = ss.actionerTypeVar;
		this->isSetupVar = ss.isSetupVar;
		this->melodyPin = ss.melodyPin;

		this->setup();
	}

	return *this;
}

Sound::~Sound() {}

bool Sound::setup(void) {
}

bool Sound::isSetup(void) {
}


int Sound::doAction(void) {

}

void Sound::reset(void) {}

char* Sound::getActionerName(void){}

int Sound::getActionerType(void){}





