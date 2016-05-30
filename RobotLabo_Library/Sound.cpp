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
	melodyPin = 8 

	this->isSetupVar = true;
	return this->isSetupVar;
}

bool Sound::isSetup(void) {
	return this->isSetupVar;
}


int Sound::doAction(void) {

	for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
	}

void Sound::reset(void) {}

char* Sound::getActionerName(void){}

int Sound::getActionerType(void){}





