#include "Robot.h"


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

	//this->sensorTab = sensorTab;
	//this->motorTab = motorTab;
	//this->actionerTab = actionerTab;


}

Robot::~Robot()
{
	delete[] this->sensorTab;
	delete[] this->motorTab;
	delete[] this->actionerTab;
}


void Robot::forward()
{
	for (int i = 0; i < sensorTabSize; i++)
	{
		if (this->motorTab[i].getMotorType() == motorType::courantContinu && this->motorTab[i].isMovingMotor)
		{
			this->motorTab[i].move(150);
		}
	}
}

void Robot::backward()
{
	for (int i = 0; i < sensorTabSize; i++)
	{
		if (this->motorTab[i].getMotorType() == motorType::courantContinu && this->motorTab[i].isMovingMotor)
		{
			this->motorTab[i].move(-150);
		}
	}
}

void Robot::forwardAt(int distance)
{

}

void Robot::backwardAt(int distance)
{

}

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
			}
		}
	}
}

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
			}
		}
	}
}

void Robot::stop()
{
	for (int i = 0; i < sensorTabSize; i++)
	{
		if (this->motorTab[i].getMotorType() == motorType::courantContinu && this->motorTab[i].isMovingMotor)
		{
			this->motorTab[i].stop();
		}
	}
}

void Robot::followLine()
{

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

void Robot::turn45degreeLeft()
{

}

void Robot::turn45degreeRight()
{

}

void Robot::turnAround()
{

}

void Robot::playSound()
{

}

int Robot::getSensorIndexWithName(char* name)
{
	for (int i = 0; i < this->sensorTabSize; i++)
	{
		if (this->sensorTab[i].getSensorName() == name) {
			return i;
		}
	}
	return -1;
}

int Robot::getMotorIndexWithName(char* name)
{
	for (int i = 0; i < this->motorTabSize; i++)
	{
		if (this->motorTab[i].getMotorName() == name) {
			return i;
		}
	}
	return -1;
}

int Robot::getActionerIndexWithName(char* name)
{
	for (int i = 0; i < this->actionerTabSize; i++)
	{
		if (this->actionerTab[i].getActionerName() == name) {
			return i;
		}
	}
	return -1;
}