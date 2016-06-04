#include <Adafruit_MotorShield.h>


#ifndef _MOTORCONTINUV23_h
#define _MOTORCONTINUV23_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

<<<<<<< HEAD
=======
#include <Wire.h>
#include <Adafruit_MotorShield.h>
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
#include "Motor.h"


class MotorContinu : public Motor
{
private:

	Adafruit_DCMotor *myMotor;

	char* motorName;

	motorType motorTypeVar;

	bool isSetupVar;

	bool isMoveVar;

	int port; 

	int speed;



public:

<<<<<<< HEAD
	MotorContinu(Adafruit_DCMotor* motorIn);
	
=======
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

>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
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

