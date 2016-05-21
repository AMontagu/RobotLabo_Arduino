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

	virtual void forward(int value) = 0;

	virtual void backward(int value) = 0;

	virtual void turnLeft(int value) = 0;

	virtual void turnRight(int value) = 0;
	
};
#endif
