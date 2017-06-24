#include "Robot.h"


Robot::Robot(Sensor* sensorTab[], Motor* motorTab[], Actioner* actionerTab[], bool is4Wheelchar, char* distanceFrontName, char* distanceBackName, char* distanceRightName, char* distanceLeftName)
{
	/*this->sensorTabSize = sizeof(sensorTab);
    this->motorTabSize = sizeof(motorTab);
    this->actionerTabSize = sizeof(actionerTab);*/

	this->sensorTabSize = 5;
	this->motorTabSize = 4;
	this->actionerTabSize = 2;

	this->distanceFrontName = distanceFrontName;
	this->distanceBackName = distanceBackName;
	this->distanceLeftName = distanceLeftName;
	this->distanceRightName = distanceRightName;
	this->colorRightName = "colorRight";
	this->encoderRightName = "encoderRight";
	this->encoderLeftName = "encoderLeft";

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
	//Serial.println("cloneMotor OK");

	//Serial.println(sensorTab[0]->getSensorName());

	for (int i = 0; i < sensorTabSize; i++)
	{
		//Serial.println(i);
		//Serial.println("loop clone sensor");
		//Serial.println(sensorTab[i]->getSensorName());
		this->sensorTab[i] = sensorTab[i]->clone();
	}
	//Serial.println("cloneSensor OK");
	//Serial.println(actionerTab[0]->getActionerName());
	/*actionerTab[0]->setup();
    actionerTab[0]->doAction(1);*/
	//Serial.println(actionerTab[1]->getActionerName());
	for (int i = 0; i < actionerTabSize; i++)
	{
		//Serial.println("loop clone actionner");
		this->actionerTab[i] = actionerTab[i]->clone();
	}
	//Serial.println("cloneActioner OK");

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

	//this->sensorTab = sensorTab;
	//this->motorTab = motorTab;
	//this->actionerTab = actionerTab;
#pragma endregion

}

Robot::~Robot()
{
	delete[] this->sensorTab;
	delete[] this->motorTab;
	delete[] this->actionerTab;
}

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
		//Serial.println("in loop");
		this->motorTab[i]->setup();
		//Serial.println("after setup loop");
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
	//Serial.println("in forward");
	for (int i = 0; i < motorTabSize; i++)
	{
		/*Serial.println(this->motorTab[i]->getMotorType());
        Serial.println(motorType::courantContinu);
        Serial.println(this->motorTab[i]->isMovingMotor);*/

		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			//Serial.print("move motor");
			this->motorTab[i]->move(speed);
		}
	}
}

void Robot::forwardDifferentSpeed(int speedRight, int speedLeft)
{
	for (int i = 0; i < motorTabSize; i++)
	{
		/*Serial.println(this->motorTab[i]->getMotorType());
        Serial.println(motorType::courantContinu);
        Serial.println(this->motorTab[i]->isMovingMotor);*/

		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			if (this->motorTab[i]->isRight)
			{
				this->motorTab[i]->move(speedRight);
			}
			else
			{
				this->motorTab[i]->move(speedLeft);
			}
		}
	}
}

void Robot::forwardTime(int speed, int delayMs) {
	for (int i = 0; i < motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			this->motorTab[i]->move(speed);
		}
	}
	delay(delayMs);
	stop();
}

void Robot::backward(int speed)
{
	//Serial.println("in backward");
	for (int i = 0; i < motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			//Serial.println("bacwardMotor");
			this->motorTab[i]->move(-speed);
		}
	}
}

void Robot::forwardAt(int speed, int distance)
{
	int oldPostion = this->getPositionRight();
	int distanceInPosition = distance * this->encoderRatio;
	this->forward(speed);
	while(this->getPositionRight() - oldPostion < distanceInPosition){
		delay(10);
	}
	this->stop();
}

void Robot::backwardAt(int speed, int distance)
{
	int oldPostion = this->getPositionRight();
	int distanceInPosition = distance * this->encoderRatio;
	this->backward(speed);
	while(this->getPositionRight() - oldPostion > -distanceInPosition){
		delay(10);
	}
	this->stop();
}

void Robot::turnLeft(int speed)
{
	for (int i = 0; i < this->motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			if (this->motorTab[i]->isRight)
			{
				//Serial.print("is right =");
				Serial.println(this->motorTab[i]->getMotorName());
				this->motorTab[i]->move(-speed);
			}
			else
			{
				//Serial.print("is left =");
				//Serial.println(this->motorTab[i]->getMotorName());
				this->motorTab[i]->move(speed);
			}
		}
	}
}

void Robot::turnRight(int speed)
{
	for (int i = 0; i < this->motorTabSize; i++)
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
			}
		}
	}
}

void Robot::turnLeftTime(int speed, int delayMs)
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
			}
		}
	}
	delay(delayMs);
	stop();
	delay(200);
}

void Robot::turnRightTime(int speed, int delayMs)
{
	for (int i = 0; i < this->motorTabSize; i++)
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
			}
		}
	}
	delay(delayMs);
	stop();
	delay(200);
}

void Robot::stop()
{
	//Serial.println("inStop");
	for (int i = 0; i < motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorType() == motorType::courantContinu && this->motorTab[i]->isMovingMotor)
		{
			//Serial.println("StopMotor");
			this->motorTab[i]->stop();
		}
	}
}

void Robot::followLine(void)
{
	int colorValue; // Variable qui nous permet de stocker la couleur
	int numberMove = 0, numberMoveExpected = 5, temps = 200, countScan = 1;
	int bigTourne = 0;
	int speed = 80;
	colorValue = getColorRight(); //Recupere la couleur retourne 1 si c est noir 0 sinon
	while (true)
	{
		while (colorValue == black) //Tant que l on est sur du noir
		{
			if (bigTourne != 0) {
				while (true)
				{
					forward(150);
				}
			}
			Serial.println("in black");
			forward(speed); // On fait avancer notre robot
			colorValue = getColorRight();
		}
		while (colorValue != black) //Tant que l on est pas sur du noir
		{
			Serial.println("different black");
			Serial.println(colorValue);
			numberMove = 0;
			while (numberMove  < numberMoveExpected && colorValue != black)
			{
				Serial.println("first turn");
				turnRightTime(speed, temps);// On tourne a droite sur l amplitude precision
				//delay(200);  //Si votre robot ne s arrete pas sur la ligne mais un peu apres decochez cette ligne
				colorValue = getColorRight();
				numberMove++;
			}
			if (numberMove == numberMoveExpected*countScan) // Si on c�est deplace au maximum choisi en fonction du nombre de balayage effectu�
			{
				Serial.println("5 move turn");
				//On retourne un peu avant la ou on a commence a tourner
				turnLeftTime(speed, temps);
				numberMove = 0; // On remet a 0 pour recommencer a tourner
				numberMoveExpected++; // on est un peu avant le debut de la ou on a perdu la ligne donc on fait un mouvement de plus
				while (numberMove  < numberMoveExpected*countScan && colorValue != black)
				{
					Serial.println("in while turn other sens");
					turnLeftTime(speed, temps); // On tourne � droite sur l�amplitude precision
					//delay(200);  //Si votre robot ne s�arr�te pas sur la ligne mais un peu apr�s d�cochez cette ligne
					colorValue = getColorRight();
					Serial.println("color value after big turn = ");
					Serial.println(colorValue);
					numberMove++;

				}
				if (numberMove == numberMoveExpected*countScan) // Si on c�est deplace au maximum choisi
				{
					//On retourne la ou on a perdu la ligne
					turnRightTime(speed, temps);
					countScan++; //On a fait un balayge entier on ajoute 1 a count scan pour pouvoir multiplier numberMoveExpected
					colorValue = getColorRight();
					bigTourne++;
					Serial.println("color value after infinite turn = ");
					Serial.println(colorValue);
				}
			}
		}
	}
}
void Robot::followWall(bool isRightWall, int distanceToWall)
{
	int indexSensor = 0;
	int speedNormal = 80;
	int speedPlus = 80;

	int timeForward = 750;
	int timeRotation = 400;

	if (isRightWall) {
		indexSensor = this->getSensorIndexWithName(this->distanceRightName);
	}
	else {
		indexSensor = this->getSensorIndexWithName(this->distanceLeftName);
	}
	Serial.print("index sensor for follow wall = ");
	Serial.println(indexSensor);

	int counter = 0;

	while (true)
	{
		timeRotation = 500;
		int valeur = this->sensorTab[indexSensor]->getValue();
		Serial.print("valeur = ");
		Serial.println(valeur);

		Serial.print("distanceToWall - valeur = ");
		Serial.println(distanceToWall - valeur);

		if (distanceToWall - valeur >= 0)
		{
			timeRotation = timeRotation + (distanceToWall - valeur) * 50;
		}
		else
		{
			timeRotation = timeRotation + (valeur - distanceToWall) * 50;
		}

		if (timeRotation > 1000)
		{
			timeRotation = 1000;
		}

		Serial.print("timeRotation = ");
		Serial.println(timeRotation);

		if (valeur < distanceToWall) {
			if (isRightWall)
			{
				Serial.println("1");
				//forwardDifferentSpeed(speedPlus + 60, speedNormal);
				turnRightTime(80, timeRotation);
				forwardTime(80, timeForward);
				turnLeftTime(80, timeRotation);
			}
			else {
				Serial.println("2");
				//forwardDifferentSpeed(speedNormal, speedPlus + 60);

				turnLeftTime(80, timeRotation);
				forwardTime(80, timeForward);
				turnRightTime(80, timeRotation);
			}
		}
		else if (valeur > distanceToWall) {
			if (isRightWall)
			{
				Serial.println("3");
				turnLeftTime(80, timeRotation);
				forwardTime(80, timeForward);
				turnRightTime(80, timeRotation);
			}
			else {
				Serial.println("4");

				turnRightTime(80, timeRotation);
				forwardTime(80, timeForward);
				turnLeftTime(80, timeRotation);
			}
		}
		else {
			Serial.println("5");
			forwardDifferentSpeed(speedNormal, speedNormal);
		}
		delay(1000);
	}
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

int Robot::getSensorIndexWithName(char* name)
{
	for (int i = 0; i < this->sensorTabSize; i++)
	{
		if (this->sensorTab[i]->getSensorName() == name) {
			return i;
		}
	}
	return -1;
}

int Robot::getMotorIndexWithName(char* name)
{
	for (int i = 0; i < this->motorTabSize; i++)
	{
		if (this->motorTab[i]->getMotorName() == name) {
			return i;
		}
	}
	return -1;
}

int Robot::getActionerIndexWithName(char* name)
{
	for (int i = 0; i < this->actionerTabSize; i++)
	{
		if (this->actionerTab[i]->getActionerName() == name) {
			return i;
		}
	}
	return -1;
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

int Robot::getColorRight() {
	for (int i = 0; i < this->sensorTabSize; i++)
	{
		if (this->sensorTab[i]->getSensorFamily() == sensorFamily::colorSensor && this->sensorTab[i]->getSensorName() == this->colorRightName) {
			delay(500);
			return this->sensorTab[i]->getValue();
		}
	}
	return -1;
}

int Robot::getPositionRight() {

	return this->position;
}

int Robot::setPositionRight(long position) {

    this->position = position;
}

int Robot::getPositionLeft() {

	for (int i = 0; i < this->sensorTabSize; i++)
	{
		if (this->sensorTab[i]->getSensorFamily() == sensorFamily::encoderSensor && this->sensorTab[i]->getSensorName() == this->encoderLeftName) {
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
}

void Robot::lineFollower(void) {
	int colorValue; // Variable qui nous permet de stocker la couleur
	bool findAtRight = true, currentTurnAtRight = true; //On veut commencer � chercher � droite
	int speedForward = 60;
	int  speed = 120, numberMove = 0, numberMoveExpected = 5, precision = 150, countScan = 1;
	while (true)
	{
		if (currentTurnAtRight)
		{
			findAtRight = true;
		}
		else
		{
			findAtRight = false;
		}
		colorValue = getColorRight(); //R�cup�re la couleur retourne 1 si c�est noir 0 sinon
		Serial.println("colorValue = ");
		Serial.println(colorValue);
		if (colorValue == black)
		{
			numberMoveExpected = 5;
			countScan = 1;
		}
		while (colorValue == black) //Tant que l�on est sur du noir
		{
			forward(speedForward); // On fait avancer notre robot
			delay(300);
			stop();
			colorValue = getColorRight();
		}
		while (colorValue != black) //Tant que l�on est pas sur du noir
		{
			numberMove = 0;
			while (numberMove  < numberMoveExpected && colorValue != black)
			{
				if (findAtRight)
				{
					currentTurnAtRight = true;
					turnRightTime(speed, precision); // On tourne � droite sur l�amplitude precision
				}
				else
				{
					currentTurnAtRight = false;
					turnLeftTime(speed, precision); // On tourne � droite sur l�amplitude precision
				}
				//delay(200);  //Si votre robot ne s�arr�te pas sur la ligne mais un peu apr�s d�cochez cette ligne
				colorValue = getColorRight();
				numberMove++;
			}
			if (numberMove == numberMoveExpected*countScan) // Si on c�est deplace au maximum choisi en fonction du nombre de balayage effectu�
			{
				//On retourne un peu avant la ou on a commence a tourner
				if (findAtRight)
				{
					currentTurnAtRight = false;
					turnLeftTime(speed, ((numberMoveExpected*countScan) - 1) * precision);
				}
				else
				{
					currentTurnAtRight = true;
					turnRightTime(speed, (numberMoveExpected*countScan - 1) * precision);
				}

				numberMove = 0; // On remet a 0 pour recommencer a tourner
				numberMoveExpected++; // on est un peu avant le debut de la ou on a perdu la ligne donc on fait un mouvement de plus
				while (numberMove  < numberMoveExpected*countScan && colorValue != black)
				{
					if (findAtRight)
					{
						currentTurnAtRight = false;
						turnLeftTime(speed, precision); // On tourne � droite sur l�amplitude precision
					}
					else
					{
						currentTurnAtRight = true;
						turnLeftTime(speed, precision); // On tourne � droite sur l�amplitude precision
					}
					//delay(200);  //Si votre robot ne s�arr�te pas sur la ligne mais un peu apr�s decommenttez cette ligne
					colorValue = getColorRight();
					numberMove++;
				}
				if (numberMove == numberMoveExpected*countScan) // Si on c�est deplace au maximum choisi
				{
					//On retourne la ou on a perdu la ligne
					if (findAtRight)
					{
						currentTurnAtRight = true;
						turnRightTime(speed, (numberMoveExpected*countScan - 1) * precision);
					}
					else
					{
						currentTurnAtRight = false;
						turnLeftTime(speed, (numberMoveExpected*countScan - 1) * precision);
					}
					countScan++; //On a fait un balayge entier on ajoute 1 a count scan pour pouvoir multiplier numberMoveExpected
				}
			}
		}
	}
}