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
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 80; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations2[thisNote];
    tone(8, melodyMario[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.75;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }

  return 1;

}

void Sound::reset(void) {}

char* Sound::getActionerName(void){
	 return this->actionerName;

}
	


int Sound::getActionerType(void){
	return this->actionerTypeVar;

}





