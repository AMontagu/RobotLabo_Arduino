// Sensor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

enum motorType { courantContinu, pasapas, servoMotor};


class Motor
{
public:
	Motor(void)
	{
	}

	/**
	*  Copy constructor.
	*
	*  @param sink the Sink to copy.
	*/
	Motor(const Motor &    sensor)
	{
	}

	/**
	*  Assignment operator.
	*
	*  @param sensor the Sensor to assign this to.
	*  @return a reference to this Sink.
	*  @exception Exception
	*/
	virtual Motor &operator= (const Motor &    sensor)
	{
		return *this;
	}

	virtual ~Motor() {}
	virtual Motor * create() const = 0; // Virtual constructor (creation) 
	virtual Motor * clone() const = 0;  // Virtual constructor (copying) 

	bool isMovingMotor = true;
	bool isRight = false;
	bool isFront = false;

public:

	virtual bool setup(void) = 0;

	virtual bool isSetup(void) = 0;

	virtual char* getMotorName(void) = 0;

	virtual int getMotorType(void) = 0;

	virtual void move(int value) = 0;

	virtual void stop() = 0;

	virtual void setSpeed(int speed) = 0;

	virtual int getSpeed() = 0;

	virtual bool getIsMove() = 0;
	
};
#endif
