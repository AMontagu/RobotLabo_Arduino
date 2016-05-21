// MotorContinu.cpp

#include <MotorContinu.h>


MotorContinu::MotorContinu(char* name, int pin1, int pin2)
{
	this->motorName = name;
	this->motorFamily = motorFamily::courantContinu;
	this->pin1 = pin1;
	this->pin2 = pin2;

	this->setup();
}


char* MotorContinu::getMotorName(void)
{
	return this->motorName;
}

void MotorContinu::setup(void)
{
	

}

bool MotorContinu::isSetup(void)
{
	return this->isSetup;
}


void MotorContinu::move(int direction)
{

}

bool MotorContinu::getIsMove()
{
	return this->isMove;
}

void MotorContinu::setIsMove(bool value)
{
	this->isMove = value;
}