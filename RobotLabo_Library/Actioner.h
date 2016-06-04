
// Actioner.h

#ifndef _ACTIONER_h
#define _ACTIONER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

enum actionerFamily { lightActioner = 0, soundActioner = 1 };

class Actioner
{
protected:

	Actioner(void)
	{
	}

	Actioner(const Actioner & actioner)
	{
	}

	virtual Actioner &operator= (const Actioner &    actioner)
	{
		return *this;
	}

public:
	/**
	*  Setup the actioner.
	*
	*  @return true if setup was successfull, false otherwise.
	*/
	virtual bool setup(void) = 0;

	/**
	*  Check if the actioner is setup.
	*
	*  @return true if the actioner is setup, false otherwise.
	*/
	virtual bool isSetup(void) = 0;

	/**
	*  Do the principal action of an actionner.
	*
	*  @return an int that is a value or a enum depend of actioner type
	*/
	virtual int doAction(void) = 0;


	/**
	*  reset the actioner. For exemple for the encodeur ...
	*/
	virtual void reset(void) = 0;

	/**
	*  get the name of the actioner
	*
	*  @return a sting corresponding to the name of the actioner
	*/
	virtual char* getActionerName(void) = 0;

	/**
	*  get the type of the actioner
	*
	*  @return an int corresponding to the enum actioner type
	*/
	virtual int getActionerType(void) = 0;

};
#endif


