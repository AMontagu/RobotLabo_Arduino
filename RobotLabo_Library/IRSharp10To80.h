// IRSharp10To80.h

#ifndef _IRSHARP10TO80_h
#define _IRSHARP10TO80_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"

class IRSharp10To80 : public Sensor
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
	*  number for the trigger pin on the arduino
	*/
	int analogPin;

	/**
	*  return true is the sensor is setup.
	*/
	bool isSetupVar;

	/*const int valeur10 = 666; //valeur
	const int valeur20 = 350; //valeur
	const int valeur30 = 249;//valeur
	const int valeur40 = 192;//valeur
	const int valeur50 = 163;//valeur
	const int valeur60 = 146;//valeur
	const int valeur70 = 129;//valeur
	const int valeur80 = 112;//valeur*/

	/*const int valeur10 = 285; //valeur
	const int valeur20 = 175; //valeur
	const int valeur30 = 107;//valeur
	const int valeur40 = 75;//valeur
	const int valeur50 = 55;//valeur
	const int valeur60 = 40;//valeur
	const int valeur70 = 30;//valeur
	const int valeur80 = 25;//valeur*/

	static const int arraySize = 10;

	const int valeur5= 650; //valeur
	const int valeur10 = 450; //valeur
	const int valeur15 = 340; //valeur
	const int valeur20 = 270; //valeur
	const int valeur30 = 200;//valeur
	const int valeur40 = 150;//valeur
	const int valeur50 = 120;//valeur
	const int valeur60 = 100;//valeur
	const int valeur70 = 70;//valeur
	const int valeur80 = 50;//valeur

	const float ratio = 30;

	const int tableauValeur[arraySize] = { valeur5, valeur10, valeur15, valeur20, valeur30, valeur40, valeur50, valeur60, valeur70, valeur80 };

public:

	/**
	*  Constructor.
	*
	*  @param name is the name of the ultrasonic sensor.
	*  @param pin digital pin where to ultrasoni sensor is plugged.
	*/
	IRSharp10To80(char* name, int analogPin, bool isFront = false, bool isRight = false);

	/**
	*  Copy constructor.
	*
	*  @param ss the TcpSocket to copy.
	*/
	IRSharp10To80(const IRSharp10To80 &    ss);

	/**
	*  Destructor.
	*/
	virtual ~IRSharp10To80(void);

	/**
	*  Assignment operator.
	*
	*  @param ss the UltrasonicSensor to assign this to.
	*  @return a reference to this UltrasonicSensor.
	*/
	virtual IRSharp10To80 &operator= (const IRSharp10To80 &    ss);

	virtual IRSharp10To80 * create() const       // Virtual constructor (creation) 
	{
		return new IRSharp10To80(this->sensorName, this->analogPin, this->isFront, this->isRight);
	}
	virtual IRSharp10To80 * clone() const        // Virtual constructor (copying) 
	{
		return new IRSharp10To80(*this);
	}

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
	*  get the principal value interest of the sensor. For color is an enum of color, for distance is distance...
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

