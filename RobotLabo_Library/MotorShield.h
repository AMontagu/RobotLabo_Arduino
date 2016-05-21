// MotoeShield.h


#ifndef _MOTORSHIELDV23_h
#define _MOTORSHIELDV23_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

//#include "Sensor.h"


class MotorShield : public Motor
{
private:

	char * motorName;

	int motorType;

	bool isSetup;

	
public:

	MotorShield(char * name);

	void setup(void);

	void isSetup();

	char * getMotorName(void);

	int getMotorType(void);

	void forward(int vitesse);

	void backward(int vitesse);

	void turnLeft(int direction);

	void turnRight(int direction);
};