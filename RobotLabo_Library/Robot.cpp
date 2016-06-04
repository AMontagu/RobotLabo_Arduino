#include "Robot.h"


<<<<<<< HEAD
Robot::Robot(Sensor* sensorTab[], Motor* motorTab[], Actioner* actionerTab[], bool is4Wheel)
{
	this->sensorTabSize = sizeof(sensorTab);
	this->motorTabSize = sizeof(motorTab);
	this->actionerTabSize = sizeof(actionerTab);

	this->is4Wheel = is4Wheel;

	this->sensorTab = (Sensor *)malloc(this->sensorTabSize * sizeof(Sensor));
	this->sensorTab = *sensorTab;

	this->motorTab = (Motor *)malloc(this->motorTabSize * sizeof(Motor));
	this->motorTab = *motorTab;

	this->actionerTab = (Actioner *)malloc(this->actionerTabSize * sizeof(Actioner));
	this->actionerTab = *actionerTab;
=======
Robot::Robot(Sensor* sensorTab[], Motor* motorTab[], Actioner* actionerTab[], bool is4Wheelchar, char* distanceFrontName, char* distanceBackName, char* distanceRightName, char* distanceLeftName)
{
	/*this->sensorTabSize = sizeof(sensorTab);
	this->motorTabSize = sizeof(motorTab);
	this->actionerTabSize = sizeof(actionerTab);*/

	this->sensorTabSize = 4;
	this->motorTabSize = 4;
	this->actionerTabSize = 2;

	this->distanceFrontName = distanceFrontName;
	this->distanceBackName = distanceBackName;
	this->distanceLeftName = distanceLeftName;
	this->distanceRightName = distanceRightName;

	/*Serial.print("sensorTabSize = ");
	Serial.println(sensorTabSize);
	Serial.print("motorTabSize = ");
	Serial.println(motorTabSize);
	Serial.print("actionerTabSize = ");
	Serial.println(actionerTabSize);*/

	this->is4Wheel = is4Wheel;

	for (int i = 0; i < motorTabSize; i++)
	{
		this->motorTab[i] = motorTab[i]->clone();
	}
	Serial.println("cloneMotor OK");

	Serial.println(sensorTab[0]->getSensorName());
	
	for (int i = 0; i < sensorTabSize; i++)
	{
		Serial.println(i);
		Serial.println("loop clone sensor");
		//Serial.println(sensorTab[i]->getSensorName());
		this->sensorTab[i] = sensorTab[i]->clone();
	}
	Serial.println("cloneSensor OK");
	Serial.println(actionerTab[0]->getActionerName());
	/*actionerTab[0]->setup();
	actionerTab[0]->doAction(1);*/
	Serial.println(actionerTab[1]->getActionerName());
	for (int i = 0; i < actionerTabSize; i++)
	{
		Serial.println("loop clone actionner");
		this->actionerTab[i] = actionerTab[i]->clone();
	}
	Serial.println("cloneActioner OK");

#pragma region comment
	//this->sensorTab = (Sensor *)malloc(this->sensorTabSize * sizeof(Sensor));
	//this->sensorTab = *sensorTab;


	//sprintf(buffer, "with %%p:  motorTab    = %p\n", motorTab);
	//Serial.print(buffer);

	//this->motorTab = (Motor *)malloc(this->motorTabSize * sizeof(Motor));
	//memcpy(this->motorTab, motorTab, 30 * sizeof(Motor));
	//this->motorTab = *motorTab;

	/*this->motorTab = {
	new MotorContinu("motorFrontRight", _motorFrontRight, true, true, true),
	new MotorContinu("motorFrontLeft", _motorFrontLeft, true, false, true),
	new MotorContinu("motorBackRight", _motorBackRight, true, true, false),
	new MotorContinu("motorBackLeft", _motorBackLeft, true, false, false) };*/



	/*for (int i = 0; i < motorTabSize; i++)
	{
	Serial.println("in loop");
	//this->motorTab = *motorTab;
	//motorTab[i]->setup();
	//motorTab[i]->move(150);
	this->motorTab[i] = motorTab[i]->clone();
	Serial.println("after setup loop");
	}*/


	//this->actionerTab = (Actioner *)malloc(this->actionerTabSize * sizeof(Actioner));
	//this->actionerTab = *actionerTab;
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523

	//this->sensorTab = sensorTab;
	//this->motorTab = motorTab;
	//this->actionerTab = actionerTab;
<<<<<<< HEAD

=======
#pragma endregion
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523

}

Robot::~Robot()
{
	delete[] this->sensorTab;
	delete[] this->motorTab;
	delete[] this->actionerTab;
}

<<<<<<< HEAD

void Robot::forward()
{
	for (int i = 0; i < sensorTabSize; i++)
	{
		if (this->motorTab[i].getMotorType() == motorType::courantContinu && this->motorTab[i].isMovingMotor)
		{
			this->motorTab[i].move(150);
=======
void Robot::setup() 
{
	Serial.print("sensorTabSize = ");
	Serial.println(sensorTabSize);
	Serial.print("motorTabSize = ");
	Serial.println(motorTabSize);
	Serial.print("actionerTabSize = ");
	Serial.println(actionerTabSize);
	for (int i = 0; i < motorTabSize; i++)
	{
		Serial.println("in loop");
		this->motorTab[i]->setup();
		Serial.println("after setup loop");
	}
	for (int i = 0; i < sensorTabSize; i++)
	{
		this->sensorTab[i]->setup();
	}
	for (int i = 0; i < actionerTabSize; i++)
	{
		this->actionerTab[i]->setup();
	}
}


void Robot::forward(int speed)
{
	Serial.println("in forward");
	for (int i = 0; i < motorTabSize; i++)
	{
		Serial.println(this->motorTab[i]->getMotorType());
		Serial.println(motorType::courantContinu);
		Serial.println(this->motorTab[i]->isMovingMotor);

		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			Serial.print("move motor");
			this->motorTab[i]->move(speed);
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
		}
	}
}

<<<<<<< HEAD
void Robot::backward()
{
	for (int i = 0; i < sensorTabSize; i++)
	{
		if (this->motorTab[i].getMotorType() == motorType::courantContinu && this->motorTab[i].isMovingMotor)
		{
			this->motorTab[i].move(-150);
=======
void Robot::backward(int speed)
{
	Serial.println("in backward");
	for (int i = 0; i < motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			Serial.println("bacwardMotor");
			this->motorTab[i]->move(-speed);
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
		}
	}
}

void Robot::forwardAt(int distance)
{

}

void Robot::backwardAt(int distance)
{

}

<<<<<<< HEAD
void Robot::turnLeft()
{
	for (int i = 0; i < sensorTabSize; i++)
	{
		if (this->motorTab[i].getMotorType() == motorType::courantContinu && this->motorTab[i].isMovingMotor)
		{
			if (this->motorTab[i].isRight) 
			{
				this->motorTab[i].move(-150);
			}
			else
			{
				this->motorTab[i].move(150);
=======
void Robot::turnLeft(int speed)
{
	for (int i = 0; i < motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			if (this->motorTab[i]->isRight) 
			{
				this->motorTab[i]->move(-speed);
			}
			else
			{
				this->motorTab[i]->move(speed);
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
			}
		}
	}
}

<<<<<<< HEAD
void Robot::turnRight()
{
	for (int i = 0; i < sensorTabSize; i++)
	{
		if (this->motorTab[i].getMotorType() == motorType::courantContinu && this->motorTab[i].isMovingMotor)
		{
			if (this->motorTab[i].isRight)
			{
				this->motorTab[i].move(150);
			}
			else
			{
				this->motorTab[i].move(-150);
=======
void Robot::turnRight(int speed)
{
	for (int i = 0; i < motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			if (this->motorTab[i]->isRight)
			{
				this->motorTab[i]->move(speed);
			}
			else
			{
				this->motorTab[i]->move(-speed);
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
			}
		}
	}
}

void Robot::stop()
{
<<<<<<< HEAD
	for (int i = 0; i < sensorTabSize; i++)
	{
		if (this->motorTab[i].getMotorType() == motorType::courantContinu && this->motorTab[i].isMovingMotor)
		{
			this->motorTab[i].stop();
=======
	Serial.println("inStop");
	for (int i = 0; i < motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			Serial.println("StopMotor");
			this->motorTab[i]->stop();
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
		}
	}
}

void Robot::followLine()
{
<<<<<<< HEAD
	int colorValue;   // Variable qui nous permet de stocker la couleur
	int speed = 20;
	bool findAtRight = true;
	bool currentTurnAtRight = true ; 
	int numberMove = 0 ; 
	int numberMoveExpected = 5; 
	int precision = 20;
	int countScan = 1;

		while(true) 
		{ 
			if (currentTurnAtRight){
				findAtRight = true; 
			}
			else{
				findAtRight = false;
			}
		colorValue = getColor();
		while (colorValue == 1) {
			forward()
			colorValue = getColor();
		}
		while (colorValue == 0){
			numberMove = 0;
			while(numberMove < numberMoveExpected && colorValue = 0){
				if findAtRight{
					currentTurnAtRight = true ; 
					turnRight() 
				}
				else{
					currentTurnAtRight = false; 
					turnLeft()
				}
			//delay 200
			colorValue = getColor();
			numberMove++; 
		}
		if(numberMove == numberMoveExpected*countScan) {
			if findAtRight{
				turnLeft()
			}
			else{
				turnRight()
			}
		}
		}

}

void Robot::foolwWall(bool isRightWall,int distanceToWall) 
{
	int indexSensor;
	if ( isRightWall ) {

		indexSensor = this->getSensorIndexWithName("ir10To80Right");

	} else {

		indexSensor = this->getSensorIndexWithName("ir4To30Left");
	}

	Serial.print("index sensor for follow wall = ");
	Serial.print(indexSensor);
	Serial.println(this->sensorTab[indexSensor]->getValue());

	int valeur = this->sensorTab[indexSensor]->getValue() 

	int indexMotor; 

	if ( valeur < distanceToWall ) {

		turnLeft();

	} else {

		turnRight();
	}
}


=======

}

void Robot::foolwWall(bool isRightWall) 
{
	int indexSensor;
	if (isRightWall)
	{
		indexSensor = this->getSensorIndexWithName("ir10To80Right");
	}
	else
	{
		indexSensor = this->getSensorIndexWithName("ir4To30Left");
	}
	Serial.print("index sensor for follow wall = ");
	Serial.print(indexSensor);

}

>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
void Robot::turn45degreeLeft()
{

}

void Robot::turn45degreeRight()
{

}

void Robot::turnAround()
{

}

<<<<<<< HEAD
void Robot::playSound()
{

}

=======
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
int Robot::getSensorIndexWithName(char* name)
{
	for (int i = 0; i < this->sensorTabSize; i++)
	{
<<<<<<< HEAD
		if (this->sensorTab[i].getSensorName() == name) {
=======
		if (this->sensorTab[i]->getSensorName() == name) {
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
			return i;
		}
	}
	return -1;
}

int Robot::getMotorIndexWithName(char* name)
{
	for (int i = 0; i < this->motorTabSize; i++)
	{
<<<<<<< HEAD
		if (this->motorTab[i].getMotorName() == name) {
=======
		if (this->motorTab[i]->getMotorName() == name) {
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
			return i;
		}
	}
	return -1;
}

int Robot::getActionerIndexWithName(char* name)
{
	for (int i = 0; i < this->actionerTabSize; i++)
	{
<<<<<<< HEAD
		if (this->actionerTab[i].getActionerName() == name) {
=======
		if (this->actionerTab[i]->getActionerName() == name) {
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
			return i;
		}
	}
	return -1;
<<<<<<< HEAD
=======
}

void Robot::calibrate()
{
	//find the way for escape
}

int Robot::getDistanceFront() {
	for (int i = 0; i < this->sensorTabSize; i++)
	{
		if (this->sensorTab[i]->getSensorName() == this->distanceFrontName) {
			return this->sensorTab[i]->getValue();
		}
	}
	return -1;

}
int Robot::getDistanceBack() {
	for (int i = 0; i < this->sensorTabSize; i++)
	{
		if (this->sensorTab[i]->getSensorName() == this->distanceBackName) {
			return this->sensorTab[i]->getValue();
		}
	}
	return -1;
}
int Robot::getDistanceRight() {
	for (int i = 0; i < this->sensorTabSize; i++)
	{
		if (this->sensorTab[i]->getSensorName() == this->distanceRightName) {
			return this->sensorTab[i]->getValue();
		}
	}
	return -1;
}
int Robot::getDistanceLeft() {
	for (int i = 0; i < this->sensorTabSize; i++)
	{
		if (this->sensorTab[i]->getSensorName() == this->distanceLeftName) {
			return this->sensorTab[i]->getValue();
		}
	}
	return -1;
}

//DoAction fucntions

void Robot::playSound(int actionNumber) {
	for (int i = 0; i < this->actionerTabSize; i++)
	{
		if (this->actionerTab[i]->getActionerType() == actionerFamily::soundActioner) {
			this->actionerTab[i]->doAction(actionNumber);
		}
	}
}
void Robot::doLight(int actionNumber) {
	for (int i = 0; i < this->actionerTabSize; i++)
	{
		if (this->actionerTab[i]->getActionerType() == actionerFamily::lightActioner) {
			this->actionerTab[i]->doAction(actionNumber);
		}
	}
>>>>>>> 31a0673bdfaa671c974188ba3ee14890ae388523
}