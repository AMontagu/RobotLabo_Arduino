// Robot.h

#ifndef _ROBOT_h
#define _ROBOT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Sensor.h"
#include "Actioner.h"
#include "Motor.h"

class Robot
{

private:

	bool is4Wheel = false;

	//Sensor** sensorTab = new Sensor*[10];
	Sensor* sensorTab;
	int sensorTabSize;

	//Motor** motorTab = new Motor*[8];
	Motor* motorTab;
	int motorTabSize;

	//Actioner** actionerTab = new Actioner*[8];
	Actioner* actionerTab;
	int actionerTabSize;

public:
	Robot(Sensor* sensorTab[], Motor* motorTab[], Actioner* actionerTab[], bool is4Wheel = false);

	~Robot(void);

	void forward();

	void backward();

	void forwardAt(int distance);

	void backwardAt(int distance);

	void turnLeft();

	void turnRight();

	void stop();

	void followLine();

	void foolwWall(bool isRightWall, int distanceToWall = 10);

	void turn45degreeLeft();

	void turn45degreeRight();

	void turnAround();

	void playSound();

	int getSensorIndexWithName(char* name);

	int getMotorIndexWithName(char* name);

	int getActionerIndexWithName(char* name);
};

#endif
