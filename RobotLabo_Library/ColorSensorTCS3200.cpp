/*
Color :

blue : red=424 green=759 blue=754grey : red=753 green=572 blue=591

*/

#include "ColorSensorTCS3200.h"

ColorSensorTCS3200* currentColorSensor;

ColorSensorTCS3200::ColorSensorTCS3200(char* name, int s0, int s1, int s2, int s3, int out)
{
	this->sensorName = name;
	this->sensorFamilyVar = sensorFamily::colorSensor;
	this->sensorTypeVar = sensorType::color;
	this->s0 = s0;
	this->s1 = s1;
	this->s2 = s2;
	this->s3 = s3;
	this->out = out;

	this->isSetupVar = false;

	//this->setup();
}

ColorSensorTCS3200::ColorSensorTCS3200(const ColorSensorTCS3200 &    ss) : Sensor(ss)
{
	this->sensorFamilyVar = ss.sensorFamilyVar;
	this->sensorName = ss.sensorName;
	this->sensorTypeVar = ss.sensorTypeVar;
	this->s0 = ss.s0;
	this->s1 = ss.s1;
	this->s2 = ss.s2;
	this->s3 = ss.s3;
	this->out = ss.out;
	this->flag = ss.flag;
	this->counter = ss.counter;
	this->countB = ss.countB;
	this->countG = ss.countG;
	this->countR = ss.countR;

	this->setup();
}

ColorSensorTCS3200 &ColorSensorTCS3200 :: operator= (const ColorSensorTCS3200 &    ss)
{
	if (this != &ss) {
		this->sensorFamilyVar = ss.sensorFamilyVar;
		this->sensorName = ss.sensorName;
		this->sensorTypeVar = ss.sensorTypeVar;
		this->isSetupVar = ss.isSetupVar;
		this->s0 = ss.s0;
		this->s1 = ss.s1;
		this->s2 = ss.s2;
		this->s3 = ss.s3;
		this->out = ss.out;
		this->flag = ss.flag;
		this->counter = ss.counter;
		this->countB = ss.countB;
		this->countG = ss.countG;
		this->countR = ss.countR;

		this->setup();
	}

	return *this;
}


ColorSensorTCS3200::~ColorSensorTCS3200() {}

bool ColorSensorTCS3200::setup(void) {

	//Initiate
	pinMode(s0, OUTPUT);
	pinMode(s1, OUTPUT);
	pinMode(s2, OUTPUT);
	pinMode(s3, OUTPUT);

	this->isSetupVar = true;

	return this->isSetupVar;
}

bool ColorSensorTCS3200::isSetup(void) {
	return this->isSetupVar;
}

int ColorSensorTCS3200::getValue(void) 
{
	int colorReturn = white;
	currentColorSensor = this;
	//Serial.println("before TCS");
	TCS();
	delay(200);
	//Serial.println("after TCS");
	/*Serial.print("red=");
	Serial.println(currentColorSensor->countR, DEC);
	Serial.print("green=");
	Serial.println(currentColorSensor->countG, DEC);
	Serial.print("blue=");
	Serial.println(currentColorSensor->countB, DEC);*/
	if ((countR < 15) || (countG < 15) || (countB < 15)) {
		colorReturn = black;
	}
	return colorReturn;
	/*if ((countR > 10) || (countG > 10) || (countB > 10))
	{
		//Serial.println("in condition in getvalue");
		if ((countR > countG) && (countR > countB))
		{
			Serial.print("red");
			Serial.print("\n");
		}
		else if ((countG >= countR) && (countG > countB))
		{
			Serial.print("green");
			Serial.print("\n");
		}
		else if ((countB > countG) && (countB > countR))
		{
			Serial.print("blue");
			Serial.print("\n");
		}
	}
	else
	{
		//Serial.println("in else in getvalue");
	}*/
	
	//Serial.println("before delete");
	//delete[] currentColorSensor;
	//Serial.println("after delete");
	//delay(1000);
}

long ColorSensorTCS3200::getPrecisionValue(void) {
	return 0;
}

void ColorSensorTCS3200::reset(void) {}

char* ColorSensorTCS3200::getSensorName(void) {
	return this->sensorName;
}

int ColorSensorTCS3200::getSensorType(void) {
	return this->sensorTypeVar;
}

int ColorSensorTCS3200::getSensorFamily(void) {
	return this->sensorFamilyVar;
}

void TCS()
{
	digitalWrite(currentColorSensor->s1, HIGH);
	digitalWrite(currentColorSensor->s0, LOW);
	currentColorSensor->flag = 0;
	//Serial.println("before attach interrupt");
	attachInterrupt(0, ISR_INTO, CHANGE);
	//getRGB();
	//Serial.println("after attach interrupt");
	timer2_init();
	//Serial.println("before timer init");
}

void ISR_INTO()
{
	currentColorSensor->counter++;
}

void timer2_init(void)
{
	TCCR2A = 0x00;
	TCCR2B = 0x07; //the clock frequency source 1024 points
	TCNT2 = 100;    //10 ms overflow again
	TIMSK2 = 0x01; //allow interrupt
}

ISR(TIMER2_OVF_vect)//the timer 2, 10ms interrupt overflow again. Internal overflow interrupt executive function
{
	//Serial.println("in TCS");
	TCNT2 = 100;
	currentColorSensor->flag++;
	if (currentColorSensor->flag == 1)
	{
		currentColorSensor->counter = 0;
	}
	else if (currentColorSensor->flag == 2)
	{
		digitalWrite(currentColorSensor->s2, LOW);
		digitalWrite(currentColorSensor->s3, LOW);
		currentColorSensor->countR = currentColorSensor->counter / 1.051;
		digitalWrite(currentColorSensor->s2, HIGH);
		digitalWrite(currentColorSensor->s3, HIGH);
	}
	else if (currentColorSensor->flag == 3)
	{
		currentColorSensor->countG = currentColorSensor->counter / 1.0157;
		digitalWrite(currentColorSensor->s2, LOW);
		digitalWrite(currentColorSensor->s3, HIGH);

	}
	else if (currentColorSensor->flag == 4)
	{
		currentColorSensor->countB = currentColorSensor->counter / 1.114;
		digitalWrite(currentColorSensor->s2, LOW);
		digitalWrite(currentColorSensor->s3, LOW);
	}
	else
	{
		//Serial.println("in else ISR primary condition");
		currentColorSensor->flag = 0;
		TIMSK2 = 0x00;
	}
	currentColorSensor->counter = 0;
	//Serial.println("before delay in ISR");
	delay(2);
}

