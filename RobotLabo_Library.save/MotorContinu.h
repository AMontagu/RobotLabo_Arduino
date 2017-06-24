// MotoeShield.h

#ifndef _MOTORCONTINUV23_h
#define _MOTORCONTINUV23_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "Motor.h"

class MotorContinu : public Motor
{
private:

	Adafruit_DCMotor *myMotor;

	char* motorName;

	int motorTypeVar;

	bool isSetupVar;

	bool isMoveVar;

	int port; 

	int speed;



public:

	MotorContinu(char* name, Adafruit_DCMotor* motorIn, bool isMovingMotor = true, bool isRight = false, bool isFront = false);

	/**
	*  Copy constructor.
	*
	*  @param ss the TcpSocket to copy.
	*/
	MotorContinu(const MotorContinu &    ss);

	/**
	*  Destructor.
	*/
	virtual ~MotorContinu(void);

	/**
	*  Assignment operator.
	*
	*  @param ss the UltrasonicSensor to assign this to.
	*  @return a reference to this UltrasonicSensor.
	*/
	virtual MotorContinu &operator= (const MotorContinu &    ss);

	virtual MotorContinu * create() const       // Virtual constructor (creation) 
	{
		return new MotorContinu(this->motorName, this->myMotor, this->isMovingMotor, this->isRight, this->isFront);
	}
	virtual MotorContinu * clone() const        // Virtual constructor (copying) 
	{
		return new MotorContinu(*this);
	}

	virtual bool setup(void);

	virtual bool isSetup();

	virtual char* getMotorName(void);

	virtual int getMotorType(void);

	virtual bool getIsMove();

	virtual void move(int value);

	virtual void stop();

	virtual void setSpeed(int speed);

	virtual int getSpeed();
};

#endif
