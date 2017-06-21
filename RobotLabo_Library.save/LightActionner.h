// LightActionner.h

#ifndef _LIGHTACTIONNER_h
#define _LIGHTACTIONNER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Adafruit_NeoPixel.h>
#include "Actioner.h"

class LightActionner : public Actioner
{
public:
	LightActionner(char* actionName, int lightPin, int num_leds, int brightness, int* gamma, int delay, int first_arg, int second_arg);
	LightActionner(const LightActionner &la);
	virtual LightActionner &operator= (const LightActionner &    la);
	virtual ~LightActionner ();

	virtual LightActionner * create() const       // Virtual constructor (creation) 
	{
		return new LightActionner(this->actionnerName, this->lightPin, this->num_leds, this->brightness, this->gamma, this->delaytime, this->first_arg, this->second_arg);
	}
	virtual LightActionner * clone() const        // Virtual constructor (copying) 
	{
		return new LightActionner(*this);
	}

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
	virtual void doAction(int actionNumber);


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

	/**
	*  
	*/
	void loop();

	void colorWipe(uint32_t c, uint8_t wait);

	void pulseWhite(uint8_t wait);

	void rainbowFade2White(uint8_t wait, int rainbowLoops, int whiteLoops);

	void whiteOverRainbow(uint8_t wait, uint8_t whiteSpeed, uint8_t whiteLength);

	void fullWhite();

	void rainbowCycle(uint8_t wait);

	void rainbow(uint8_t wait);

	uint32_t Wheel(byte WheelPos);

	uint8_t red(uint32_t c);

	uint8_t green(uint32_t c);

	uint8_t blue(uint32_t c);

	//Actionner name
	char* actionnerName;
	
	//Actionner family
	int actionnerFamily;

	//If is setup
	bool isSetupVar;

	//Pin value
	int lightPin;

	//Number of leds
	int num_leds;

	//Brightness
	int brightness;

	//NeoPixel 
	Adafruit_NeoPixel strip;

	//Gamma
	int* gamma;

	//delay
	int delaytime;

	//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
	//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
	int first_arg;

	//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
	//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
	int second_arg;

};

#endif

