// IRSharp10To80.h

#ifndef _IRSHARP4TO30_h
#define _IRSHARP4TO30_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"

class IRSharp4To30 : public Sensor
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

	const static int arraySize = 10;

	const int valeur5 = 440; //valeur
	const int valeur10 = 270; //valeur
	const int valeur15 = 170; //valeur
	const int valeur20 = 135; //valeur
	const int valeur30 = 107;//valeur
	const int valeur40 = 75;//valeur
	const int valeur50 = 55;//valeur
	const int valeur60 = 40;//valeur
	const int valeur70 = 30;//valeur
	const int valeur80 = 25;//valeur

	const int tableauValeur[arraySize] = { valeur5, valeur10, valeur15, valeur20, valeur30, valeur40, valeur50, valeur60, valeur70, valeur80 };

	const int ratio = 16;
public:

	/**
	*  Constructor.
	*
	*  @param name is the name of the ultrasonic sensor.
	*  @param pin digital pin where to ultrasoni sensor is plugged.
	*/
	IRSharp4To30(char* name, int analogPin, bool isFront = false, bool isRight = false);

	/**
	*  Copy constructor.
	*
	*  @param ss the TcpSocket to copy.
	*/
	IRSharp4To30(const IRSharp4To30 &    ss);

	/**
	*  Destructor.
	*/
	virtual ~IRSharp4To30(void);

	/**
	*  Assignment operator.
	*
	*  @param ss the UltrasonicSensor to assign this to.
	*  @return a reference to this UltrasonicSensor.
	*/
	virtual IRSharp4To30 &operator= (const IRSharp4To30 &    ss);

	virtual IRSharp4To30 * create() const       // Virtual constructor (creation) 
	{
		return new IRSharp4To30(this->sensorName, this->analogPin, this->isFront, this->isRight);
	}
	virtual IRSharp4To30 * clone() const        // Virtual constructor (copying) 
	{
		return new IRSharp4To30(*this);
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

