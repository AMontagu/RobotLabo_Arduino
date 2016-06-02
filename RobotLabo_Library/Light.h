// Light.h

#ifndef _LIGHT_h
#define _LIGHT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Actioner.h"
#include <Adafruit_NeoPixel.h>

class LightClass : public Actioner
{
private:
	/**
	*  Name of the actioner
	*/
	char* actionerName;

	/**
	*  Name of the actioner
	*/
	int actionerTypeVar;

	/**
	*  number for the trigger pin on the arduino
	*/
	int lightPin;


	/**
	*  return true is the actioner is setup.
	*/
	bool isSetupVar;
protected:

public:
	LightClass(char* name, int lightPin);


	LightClass(const LightClass &    ss);

	/**
	*  Destructor.
	*/
	virtual ~LightClass(void);
	void init();
	/**
	*  Setup the actioner.
	*
	*  @return true if setup was successfull, false otherwise.
	*/
	virtual bool setup(void);

	/**
	*  Check if the actioner is setup.
	*
	*  @return true if the actioner is setup, false otherwise.
	*/
	virtual bool isSetup(void);

	/**
	*  Do the principal action of an actionner.
	*
	*  @return an int that is a value or a enum depend of actioner type
	*/
	virtual int doAction(void);


	/**
	*  reset the actioner. For exemple for the encodeur ...
	*/
	virtual void reset(void);

	/**
	*  get the name of the actioner
	*
	*  @return a sting corresponding to the name of the actioner
	*/
	virtual char* getActionerName(void);

	/**
	*  get the type of the actioner
	*
	*  @return an int corresponding to the enum actioner type
	*/
	virtual int getActionerType(void);
	void colorWipe(uint32_t c, uint8_t wait);
	void rainbow(uint8_t wait);
	void rainbowCycle(uint8_t wait);
	void theaterChase(uint32_t c, uint8_t wait);
	void theaterChaseRainbow(uint8_t wait);
	uint32_t Wheel(byte WheelPos);
	/**
	*  A new adafruit neopixel
	*/
	Adafruit_NeoPixel strip;

};

extern LightClass Light;

#endif

