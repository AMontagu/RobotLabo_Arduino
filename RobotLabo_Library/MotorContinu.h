// MotoeShield.h


#ifndef _MOTORCONTINUV23_h
#define _MOTORCONTINUV23_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#include "Sensor.h"


class MotorContinu : public Motor
{
private:

	char * motorName;

	int motorType;

	bool isSetup;

	bool isMove;

	int pin1;

	int pin2;

	
public:

	MotorContinu(char * name);

	void setup(void);

	void isSetup();

	char * getMotorName(void);

	int getMotorType(void);

	bool getIsMove();

	void setIsMove(bool value);

	void move(int direction);
};