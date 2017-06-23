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
    this->oldPinState = 0;

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

    //Initiate
    /*if (this->isRight)
    {
        encoderRight = this;
        attachInterrupt(this->interruptPin, getEncoderRight, CHANGE);
    }
    if (!this->isRight)
    {
        encoderLeft = this;
        attachInterrupt(this->interruptPin, getEncoderLeft, CHANGE);
    }*/

    pinMode(this->encoderPinA, INPUT);
    pinMode(this->encoderPinB, INPUT);

    attachInterruptHack(this->encoderPinA, this->isRight);
    attachInterruptHack(this->encoderPinB, this->isRight);

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

    int NewPositionState = readPinA * 2 + readPinB;           // Convert binary input to decimal value
    encoderRight->position += encoderRight->QEM [encoderRight->oldPinState * 4 + NewPositionState];

    Serial.print("position = ");
    Serial.println(encoderRight->position);


    encoderRight->oldPinState = NewPositionState;
}

void updatePositionLeft() {
    int readPinA = digitalRead(encoderLeft->encoderPinA);
    int readPinB = digitalRead(encoderLeft->encoderPinB);

    /*Serial.print("pina = ");
    Serial.print(readPinA);

    Serial.print(", pinb = ");
    Serial.println(readPinB);

    Serial.println("");*/

    int NewPositionState = readPinA * 2 + readPinB;           // Convert binary input to decimal value
    encoderLeft->position += encoderLeft->QEM [encoderLeft->oldPinState * 4 + NewPositionState];

    Serial.print("position = ");
    Serial.println(encoderLeft->position);


    encoderLeft->oldPinState = NewPositionState;
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

