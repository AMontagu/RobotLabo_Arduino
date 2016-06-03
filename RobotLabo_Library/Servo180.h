// Servo180.h

#ifndef _SERVO180_h
#define _SERVO180_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Motor.h"
#include <Servo.h>

class Servo180 : public Motor
{
 private:

	 char* motorName;

	 /**
	 *  Name of the sensor
	 */
	 int motorTypeVar;

	 int speed;

	 int pin; // 9 or 10 -> 10 = servo 1, 9 = servo 2

	 Servo myservo;

	 /**
	 *  return true is the sensor is setup.
	 */
	 bool isSetupVar;

	 bool isMoveVar;

 public:

	 /**
	 *  Constructor.
	 *
	 *  @param name is the name of the ultrasonic sensor.
	 *  @param pin digital pin where to ultrasoni sensor is plugged.
	 */
	 Servo180(char* name, int motorPin, bool isMovingMotor = false, bool isRight = false, bool isFront = false);

	 /**
	 *  Copy constructor.
	 *
	 *  @param ss the Servo180 to copy.
	 */
	 Servo180(const Servo180 &    ss);

	 /**
	 *  Destructor.
	 */
	 virtual ~Servo180(void);

	 /**
	 *  Assignment operator.
	 *
	 *  @param ss the Servo180 motor to assign this to.
	 *  @return a reference to this Servo180.
	 */
	 virtual Servo180 &operator= (const Servo180 &    ss);
	
	 virtual bool setup(void);

	 virtual bool isSetup(void);

	 virtual char* getMotorName(void);

	 virtual int getMotorType(void);

	 virtual void move(int value);

	 virtual void stop();

	 virtual void setSpeed(int speed);

	 virtual int getSpeed();

	 virtual bool getIsMove();
};

#endif

