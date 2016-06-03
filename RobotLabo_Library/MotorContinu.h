// MotoeShield.h

#ifndef _MOTORCONTINUV23_h
#define _MOTORCONTINUV23_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
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
