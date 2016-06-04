#ifndef _CONTROLROBOT_h
#define _CONTROLROBOT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "MotorContinu.h"
#include "MotorContinu.h"

class ControlRobot
{

private:


public:
	ControlRobot();

	void setUpRobot();

	void forward();

	void backward();

	void forwardAt(int distance);

	void backwardAt(int distance);

	void turnLeft();

	void turnRight();

	void stop();
	
	void followLine();

	void turn45degreeLeft();

	void turn45degreeRight();

	void turnAround();

	void playSound();

};

#endif

