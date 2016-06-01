// Sensor.h

#ifndef _MOTOR_h
#define _MOTOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum motorType { courantContinu, pasapas, servoMotor};


class Motor
{
public:
	Motor(void){}

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
