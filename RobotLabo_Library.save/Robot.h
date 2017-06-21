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

	Sensor** sensorTab = new Sensor*[10];
	//Sensor* sensorTab;
	int sensorTabSize;

	Motor** motorTab = new Motor*[8];
	//Motor** motorTab;
	int motorTabSize;

	Actioner** actionerTab = new Actioner*[8];
	//Actioner* actionerTab;
	int actionerTabSize;

	char* distanceFrontName;
	char* distanceBackName;
	char* distanceRightName;
	char* distanceLeftName;

public:
	Robot(Sensor* sensorTab[], Motor* motorTab[], Actioner* actionerTab[], bool is4Wheel = false, char* distanceFrontName = "distanceFront", char* distanceBackName = "distanceBack", char* distanceRightName = "distanceRight", char* distanceLeftName = "distanceLeft");

	~Robot(void);

	void setup();

	void forward(int speed);

	void backward(int speed);

	void forwardAt(int distance);

	void backwardAt(int distance);

	void turnLeft(int speed);

	void turnRight(int speed);

	void stop();

	void followLine();

	void foolwWall(bool isRightWall);

	void turn45degreeLeft();

	void turn45degreeRight();

	void turnAround();

	int getSensorIndexWithName(char* name);

	int getMotorIndexWithName(char* name);

	int getActionerIndexWithName(char* name);

	void calibrate();

	//GetDistance functions

	int getDistanceFront();
	int getDistanceBack();
	int getDistanceRight();
	int getDistanceLeft();

	//DoAction fucntions

	void playSound(int actionNumber);
	void doLight(int actionNumber);
};

#endif
