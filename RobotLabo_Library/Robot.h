// Robot.h

#ifndef _ROBOT_h
#define _ROBOT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
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
	char* colorRightName;
	char* encoderRightName;
	char* encoderLeftName;
	char* motorHandName;
	char* motorArmName;
	int encoderRatio = 5;
    int encoderRatioDistance = 18;
    int encoderRatioAngle = 6;

	long position = 0;

public:
	Robot(Sensor* sensorTab[], Motor* motorTab[], Actioner* actionerTab[], bool is4Wheel = false, char* distanceFrontName = "distanceFront", char* distanceBackName = "distanceBack", char* distanceRightName = "distanceRight", char* distanceLeftName = "distanceLeft");

	~Robot(void);

	void setup();

	void forward(int speed);

	void forwardDifferentSpeed(int speedRight, int speedLeft);

	void forwardTime(int speed, int dealyMs);

	void backward(int speed);

	void forwardAt(int speed, int position);

	void backwardAt(int speed, int position);

	void turnLeftAt(int speed, int position);

	void turnRightAt(int speed, int position);

    void turnLeftAtDegre(int speed, int position);

    void turnRightAtDegre(int speed, int position);

    void forwardAtDistance(int speed, int distance);

	void backwardAtDistance(int speed, int distance);

	void turnLeft(int speed);



	void turnRight(int speed);

	void turnLeftTime(int speed, int delayMs);

	void turnRightTime(int speed, int delayMs);

	void armUp();

	void armDown();

	void armPosition(int positionArm, int positionHand);

	void stop();

	void followLine();

	void lineFollower();

    void goToWall(char* capteurName, int distanceToStop, int speed);

	void followWall(bool isRightWall, int distanceToWall);

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


	int getPositionRight();
	int setPositionRight(long position);

	int getPositionLeft();

	//getColorDroite
	int getColorRight();

	//DoAction fucntions

	void playSound(int actionNumber);
	void doLight(int actionNumber);
};

#endif

