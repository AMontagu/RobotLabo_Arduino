// UltrasonicSensor.h

#ifndef _ULTRASONICSENSOR_h
#define _ULTRASONICSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"

const long MEASURE_TIMEOUT = 25000L; // 40Hz = 25ms = ~8m � 340m/s

class UltrasonicSensorHCSR04 : public Sensor
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
	 int triggerPin;

	 /**
	 *  number of echo pin on the arduino
	 */
	 int echoPin;

	 /**
	 *  return true is the sensor is setup.
	 */
	 bool isSetupVar;

 public:

	 /**
	 *  Constructor.
	 *
	 *  @param name is the name of the ultrasonic sensor.
	 *  @param pin digital pin where to ultrasoni sensor is plugged.
	 */
	 UltrasonicSensorHCSR04(char* name, int triggerPin, int echoPin, bool isFront = false, bool isRight = false);

	 /**
	 *  Copy constructor.
	 *
	 *  @param ss the TcpSocket to copy.
	 */
	 UltrasonicSensorHCSR04(const UltrasonicSensorHCSR04 &    ss);

	 /**
	 *  Destructor.
	 */
	 virtual ~UltrasonicSensorHCSR04(void);

	 /**
	 *  Assignment operator.
	 *
	 *  @param ss the UltrasonicSensor to assign this to.
	 *  @return a reference to this UltrasonicSensor.
	 */
	 virtual UltrasonicSensorHCSR04 &operator= (const UltrasonicSensorHCSR04 &    ss);

	 virtual UltrasonicSensorHCSR04 * create() const       // Virtual constructor (creation) 
	 {
		 return new UltrasonicSensorHCSR04(this->sensorName, this->triggerPin, this->echoPin, this->isFront, this->isRight);
	 }
	 virtual UltrasonicSensorHCSR04 * clone() const        // Virtual constructor (copying) 
	 {
		 return new UltrasonicSensorHCSR04(*this);
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

