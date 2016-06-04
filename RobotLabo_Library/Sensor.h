// Sensor.h

#ifndef _SENSOR_h
#define _SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum sensorType { ultrason = 0, infrared = 1, color = 3, encoder = 4};
enum sensorFamily { distanceSensor = 0, colorSensor = 1, encoderSensor = 2};

class Sensor
{
 protected:

	 /**
	 *  Default constructor.
	 */
	 Sensor(void)
	 {
	 }

	 /**
	 *  Copy constructor.
	 *
	 *  @param sink the Sink to copy.
	 */
	 Sensor(const Sensor &    sensor)
	 {
	 }

	 /**
	 *  Assignment operator.
	 *
	 *  @param sensor the Sensor to assign this to.
	 *  @return a reference to this Sink.
	 *  @exception Exception
	 */
	 virtual Sensor &operator= (const Sensor &    sensor)
	 {
		 return *this;
	 }

 public:

	 /**
	 *  Setup the sensor.
	 *
	 *  @return true if setup was successfull, false otherwise.
	 */
	 virtual bool setup(void) = 0;

	 /**
	 *  Check if the sensor is setup.
	 *
	 *  @return true if the sensor is setup, false otherwise.
	 */
	 virtual bool isSetup(void) = 0;

	 /**
	 *  get the principal value interest of the sensor. For color is an enum of color, for distance is distance...
	 *
	 *  @return an int that is a value or a enum depend of sensor type
	 */
	 virtual int getValue(void) = 0;

	 /**
	 *  get the precision value interest of the sensor. For color is an enum of color, for distance is distance...
	 *
	 *  @return an long that is a value
	 */
	 virtual long getPrecisionValue(void) = 0;

	 /**
	 *  reset the sensor. For exemple for the encodeur ...
	 */
	 virtual void reset(void) = 0;

	 /**
	 *  get the name of the sensor
	 *
	 *  @return a sting corresponding to the name of the sensor
	 */
	 virtual char* getSensorName(void) = 0;

	 /**
	 *  get the type of the sensor
	 *
	 *  @return an int corresponding to the enum sensor type
	 */
	 virtual int getSensorType(void) = 0;

	 /**
	 *  get the type of the sensor
	 *
	 *  @return an int corresponding to the enum sensor Family
	 */
	 virtual int getSensorFamily(void) = 0;
};

#endif

