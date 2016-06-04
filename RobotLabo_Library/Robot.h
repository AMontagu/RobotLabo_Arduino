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

<<<<<<< HEAD
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
=======
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
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523

	void forwardAt(int distance);

	void backwardAt(int distance);

<<<<<<< HEAD
	void turnLeft();

	void turnRight();
=======
	void turnLeft(int speed);

	void turnRight(int speed);
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523

	void stop();

	void followLine();

<<<<<<< HEAD
	void foolwWall(bool isRightWall, int distanceToWall = 10);
=======
	void foolwWall(bool isRightWall);
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523

	void turn45degreeLeft();

	void turn45degreeRight();

	void turnAround();

<<<<<<< HEAD
	void playSound();

=======
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
	int getSensorIndexWithName(char* name);

	int getMotorIndexWithName(char* name);

	int getActionerIndexWithName(char* name);
<<<<<<< HEAD
};

#endif
=======

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

>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
