// 
// 
// 

#include "Encoder.h"

Encoder* encoderRight;
Encoder* encoderLeft;

Encoder::Encoder(char* name, int encoderPinA, int encoderPinB, bool isRight)
{
    this->sensorName = name;
    this->sensorFamilyVar = sensorFamily::encoderSensor;
    this->sensorTypeVar = sensorType::encoder;
    this->encoderPinA = encoderPinA;
    this->encoderPinA = encoderPinB;
    this->isRight = isRight;
    //this->New0 = 0;

    if(this->isRight){
        encoderRight = this;
    }else{
        encoderLeft = this;
    }

    this->isSetupVar = false;

    //this->setup();
}

Encoder::Encoder(const Encoder &    ss) : Sensor(ss)
{
    this->sensorFamilyVar = ss.sensorFamilyVar;
    this->sensorName = ss.sensorName;
    this->sensorTypeVar = ss.sensorTypeVar;
    this->encoderPinA = ss.encoderPinA;
    this->encoderPinA = ss.encoderPinB;

    this->setup();
}

Encoder &Encoder :: operator= (const Encoder &    ss)
{
    if (this != &ss) {
        this->sensorFamilyVar = ss.sensorFamilyVar;
        this->sensorName = ss.sensorName;
        this->sensorTypeVar = ss.sensorTypeVar;
        this->encoderPinA = ss.encoderPinA;
        this->encoderPinA = ss.encoderPinB;

        this->setup();
    }

    return *this;
}


Encoder::~Encoder() {}

bool Encoder::setup(void) {


    pinMode(this->encoderPinA, INPUT);
    pinMode(this->encoderPinB, INPUT);

    //Initiate
    /*if (this->isRight)
    {
        encoderRight = this;
        attachInterrupt(this->encoderPinA, updatePositionRight, CHANGE);
        attachInterrupt(this->encoderPinB, updatePositionRight, CHANGE);
    }
    if (!this->isRight)
    {
        encoderLeft = this;
        attachInterrupt(this->encoderPinA, updatePositionLeft, CHANGE);
        attachInterrupt(this->encoderPinB, updatePositionLeft, CHANGE);
    }*/

    this->isSetupVar = true;

    return this->isSetupVar;
}

bool Encoder::isSetup(void) {
    return this->isSetupVar;
}

int Encoder::getValue(void) {
    return this->position;
}

long Encoder::getPrecisionValue(void) {
    return this->position;
}

void Encoder::reset(void) {
    this->position = 0;
}

char* Encoder::getSensorName(void) {
    return this->sensorName;
}

int Encoder::getSensorType(void) {
    return this->sensorTypeVar;
}

int Encoder::getSensorFamily(void) {
    return this->sensorFamilyVar;
}

void updatePositionRight() {
    int readPinA = digitalRead(encoderRight->encoderPinA);
    int readPinB = digitalRead(encoderRight->encoderPinB);

    /*Serial.print("pina = ");
    Serial.print(readPinA);

    Serial.print(", pinb = ");
    Serial.println(readPinB);

    Serial.println("");*/

    encoderRight->Old0 = encoderRight->New0;
    encoderRight->New0 = readPinA * 2 + readPinB;           // Convert binary input to decimal value
    encoderRight->position += encoderRight->QEM [encoderRight->Old0 * 4 + encoderRight->New0];

    Serial.print("position = ");
    Serial.println(encoderRight->position);
}

void updatePositionLeft() {
    int readPinA = digitalRead(encoderLeft->encoderPinA);
    int readPinB = digitalRead(encoderLeft->encoderPinB);

    /*Serial.print("pina = ");
    Serial.print(readPinA);

    Serial.print(", pinb = ");
    Serial.println(readPinB);

    Serial.println("");*/

    encoderLeft->Old0 = encoderLeft->New0;
    encoderLeft->New0 = readPinA * 2 + readPinB;           // Convert binary input to decimal value
    encoderLeft->position += encoderLeft->QEM [encoderLeft->Old0 * 4 + encoderLeft->New0];

    Serial.print("position = ");
    Serial.println(encoderLeft->position);
}

void attachInterruptHack(int pin, bool isRight) {
    if (isRight)
    {
        attachInterrupt(digitalPinToInterrupt(pin), updatePositionRight, CHANGE);
    }
    if (!isRight)
    {
        attachInterrupt(digitalPinToInterrupt(pin), updatePositionLeft, CHANGE);
    }
}

