// ColorSensorTCS3200.h

#ifndef _COLORSENSORTCS3200_h
#define _COLORSENSORTCS3200_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"

enum color{red, blue, yellow, black, white, green};

ISR(TIMER2_OVF_vect);
void TCS();
void timer2_init(void);
void ISR_INTO();

class ColorSensorTCS3200 : public Sensor
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

	void getRGB();
	void setRGB();

public:

	int s0, s1, s2, s3, out;
	int flag = 0;
	int counter = 0;
	int countR = 0, countG = 0, countB = 0;

	/**
	*  Constructor.
	*
	*  @param name is the name of the ultrasonic sensor.
	*  @param pin digital pin where to ultrasoni sensor is plugged.
	*/
	ColorSensorTCS3200(char* name, int s0, int s1, int s2, int s3, int out);

	/**
	*  Copy constructor.
	*
	*  @param ss the TcpSocket to copy.
	*/
	ColorSensorTCS3200(const ColorSensorTCS3200 &    ss);

	/**
	*  Destructor.
	*/
	virtual ~ColorSensorTCS3200(void);

	/**
	*  Assignment operator.
	*
	*  @param ss the UltrasonicSensor to assign this to.
	*  @return a reference to this UltrasonicSensor.
	*/
	virtual ColorSensorTCS3200 &operator= (const ColorSensorTCS3200 &    ss);

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

