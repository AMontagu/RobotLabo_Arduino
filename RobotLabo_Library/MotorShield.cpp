// MotoeShield.cpp

#include <MotorShield.h>


MotorShield::MotorShield(char* name)
{
	this->motorName = name;
	this->motorFamily = motorFamily::courantContinu

}

void MotorShield::forward(int vitesse)
{

}

char * MotorShield::getMotorName(void)
{
	return this->motorName;
}

void MotorShield::setup(void)
{

}

bool MotorShield::isSetup(void)
{
	return this->isSetup;
}


void MotorShield::backward(int vitesse)
{

}


void MotorShield::turnLeft(int direction)
{

}


void MotorShield::turnRight(int direction)
{

}