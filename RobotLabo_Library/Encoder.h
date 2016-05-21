// Encoder.h

#ifndef _ENCODER_h
#define _ENCODER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"

class Encoder : public Sensor
{
private:
	/**
	*  Name of the sensor
	*/
	char* sensorName;

	/**
	*  Name of the sensor
	*/
	int sensorTypeVar;

	/**
	*  Name of the sensor
	*/
	int sensorFamilyVar;

	/**
	*  return true is the sensor is setup.
	*/
	bool isSetupVar;

	/**
	*  number for the interrupt pin on the arduino
	*/
	int interruptPin;

	/**
	*  encoder counter
	*/
	int counter;

	/**
	*  function called by attach interrupt for get the encoder increment
	*/
	void getEncoder(void);

public :
	/**
	*  Constructor.
	*
	*  @param name is the name of the encoder.
	*  @param interruptPin pin where the encoder is plugged. (need to be 2,3,18,19,20 or 21)
	*/
	Encoder(char* name, int interruptPin);

	/**
	*  Copy constructor.
	*
	*  @param ss the Encoder to copy.
	*/
	Encoder(const Encoder &    ss);

	/**
	*  Destructor.
	*/
	virtual ~Encoder(void);

	/**
	*  Assignment operator.
	*
	*  @param ss the Encoder to assign this to.
	*  @return a reference to this Encoder.
	*/
	virtual Encoder &operator= (const Encoder &    ss);

	/**
	*  Setup the sensor.
	*
	*  @return true if setup was successfull, false otherwise.
	*/
	virtual bool setup(void);

	/**
	*  Check if the sensor is setup.
	*
	*  @return true if the sensor is setup, false otherwise.
	*/
	virtual bool isSetup(void);

	/**
	*  get the counter attached to the encoder...
	*
	*  @return an int that is a value or a enum depend of sensor type
	*/
	virtual int getValue(void);

	/**
	*  get the precision value interest of the sensor. For color is an enum of color, for distance is distance...
	*
	*  @return an long that is a value
	*/
	virtual long getPrecisionValue(void);

	/**
	*  reset the sensor. For exemple for the encodeur ...
	*/
	virtual void reset(void);

	/**
	*  get the name of the sensor
	*
	*  @return a sting corresponding to the name of the sensor
	*/
	virtual char* getSensorName(void);

	/**
	*  get the type of the sensor
	*
	*  @return an int corresponding to the enum sensor type
	*/
	virtual int getSensorType(void);

	/**
	*  get the type of the sensor
	*
	*  @return an int corresponding to the enum sensor Family
	*/
	virtual int getSensorFamily(void);
	
};

#endif

