#include "Sound.h"

Sound::Sound(char* name, int melodyPin)
{
	this->actionerName = name;
	this->actionerTypeVar = actionerFamily::soundActioner;
	this->melodyPin = melodyPin;


	this->isSetupVar = false;
}

Sound::Sound(const Sound &    ss) : Actioner(ss)
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
	this->isSetupVar = true;
	return this->isSetupVar;
}

bool Sound::isSetup(void) {
	return this->isSetupVar;
}


void Sound::doAction(int actionNumber) {
	// iterate over the notes of the melody:
	Serial.println("here sound");
	int noteNumber = 0;
	int *melodyTab;
	int *notesDurations;
	switch (actionNumber)
	{
	case 1:
		noteNumber = this->melodyMarioNumber;
		melodyTab = new int[noteNumber];
		memcpy(melodyTab, this->melodyMario, noteNumber * sizeof(int));
		notesDurations = new int[noteNumber];
		memcpy(notesDurations, this->noteDurationsMario, noteNumber * sizeof(int));
		break;
	case 2:
		noteNumber = this->melodyNumber;
		melodyTab = new int[noteNumber];
		memcpy(melodyTab, this->melody, noteNumber * sizeof(int));
		notesDurations = new int[noteNumber];
		memcpy(notesDurations, this->noteDurationsMelody, noteNumber * sizeof(int));
		break;
	case 3:
		noteNumber = this->melodyUnderworldNumber;
		melodyTab = new int[noteNumber];
		memcpy(melodyTab, this->melodyUnderworld, noteNumber * sizeof(int));
		notesDurations = new int[noteNumber];
		memcpy(notesDurations, this->noteDurationsUnderworld, noteNumber * sizeof(int));
		break;
	case 4:
		noteNumber = this->melodyUnderworld2Number;
		melodyTab = new int[noteNumber];
		memcpy(melodyTab, this->melodyUnderworld2, noteNumber * sizeof(int));
		notesDurations = new int[noteNumber];
		memcpy(notesDurations, this->noteDurationUnderworld2, noteNumber * sizeof(int));
		break;
	default:
		break;
	}

	Serial.print("aNote number = ");
	Serial.println(noteNumber);

	Serial.print("melodyTab[40] = ");
	Serial.println(melodyTab[40]);

	Serial.print("notesDurations[40] = ");
	Serial.println(notesDurations[40]);

	for (int thisNote = 0; thisNote < noteNumber; thisNote++) {

		// to calculate the note duration, take one second
		// divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = 1000 / notesDurations[thisNote];
		tone(this->melodyPin, melodyTab[thisNote], noteDuration);

		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.75;
		delay(pauseBetweenNotes);
		// stop the tone playing:
		noTone(this->melodyPin);
		Serial.print("after loop ");
		Serial.println(thisNote);

	}
	Serial.println("out");

}

void Sound::reset(void) {}

char* Sound::getActionerName(void) {
	return this->actionerName;
}

int Sound::getActionerType(void) {
	this->actionerTypeVar = actionerFamily::soundActioner;
	return this->actionerTypeVar;
}





