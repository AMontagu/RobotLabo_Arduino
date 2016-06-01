// MotoeShield.h

#ifndef _MOTORCONTINUV23_h
#define _MOTORCONTINUV23_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#include "Sensor.h"


// MotoeShield.h

#include "Wire.h"
#include "Adafruit_MotorShield.h"
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

	MotorContinu(Adafruit_DCMotor* motorIn);
	
	virtual bool setup(void);

	virtual bool isSetup();

	virtual char* getMotorName(void);

	virtual int getMotorType(void);

	virtual bool getIsMove();

	virtual void move(int value);

	virtual void setSpeeda(int speed);

	virtual int getSpeed();
};

#endif
