// Encoder.h

#ifndef _ENCODER_h
#define _ENCODER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Sensor.h"

void attachInterruptHack(int pin, bool isRight);

void updatePositionRight();
void updatePositionLeft();

class Encoder : public Sensor
{
private:
    /**
    *  Name of the sensor
    */
    char* sensorName;

    /**
    *  Name of the sensor
    */
    int sensorTypeVar;

    /**
    *  Family of the sensor
    */
    int sensorFamilyVar;

    /**
    *  True if the encoder is setup.
    */
    bool isSetupVar;

    /**
    *  True if the encoder is the right one.
    */
    bool isRight;

public :

    /**
    *  encoder position
    */
    volatile long position;

    /**
    *  Pin for the pinA on the encoder (yellow wire)
    */
    int encoderPinA;

    /**
    *  Pin for the pinB on the encoder (white wire)
    */
    int encoderPinB;

    /**
    *  old value on base 10 of the result of (pinA pinB) base 2
    */
    volatile unsigned char Old0, New0;

    /**
    *  Quadrature Encoder Matrix
    */
    int QEM [16] = {0,-1,1,2,1,0,2,-1,-1,2,0,1,2,1,-1,0};

    /**
    *  Constructor.
    *
    *  @param name is the name of the encoder.
    *  @param encoderPinA pin where the encoder pinA is plugged. (need to be 2,3,18,19,20 or 21)
    *  @param encoderPinB pin where the encoder pinB plugged. (need to be 2,3,18,19,20 or 21)
    */
    Encoder(char* name, int encoderPinA, int encoderPinB, bool isRight);

    /**
    *  Copy constructor.
    *
    *  @param ss the Encoder to copy.
    */
    Encoder(const Encoder &    ss);

    /**
    *  Destructor.
    */
    virtual ~Encoder(void);

    /**
    *  Assignment operator.
    *
    *  @param ss the Encoder to assign this to.
    *  @return a reference to this Encoder.
    */
    virtual Encoder &operator= (const Encoder &    ss);

    Encoder * create() const       // Virtual constructor (creation)
    {
        return new Encoder(this->sensorName, this->encoderPinA, this->encoderPinB, this->isRight);
    }
    Encoder * clone() const        // Virtual constructor (copying)
    {
        return new Encoder(*this);
    }

    /**
    *  Setup the sensor.
    *
    *  @return true if setup was successfull, false otherwise.
    */
    virtual bool setup(void);

    /**
    *  Check if the sensor is setup.
    *
    *  @return true if the sensor is setup, false otherwise.
    */
    virtual bool isSetup(void);

    /**
    *  get the position attached to the encoder...
    *
    *  @return an int that is a value or a enum depend of sensor type
    */
    virtual int getValue(void);

    /**
    *  get the precision value interest of the sensor. For color is an enum of color, for distance is distance...
    *
    *  @return an long that is a value
    */
    virtual long getPrecisionValue(void);

    /**
    *  reset the sensor. For exemple for the encodeur ...
    */
    virtual void reset(void);

    /**
    *  get the name of the sensor
    *
    *  @return a sting corresponding to the name of the sensor
    */
    virtual char* getSensorName(void);

    /**
    *  get the type of the sensor
    *
    *  @return an int corresponding to the enum sensor type
    */
    virtual int getSensorType(void);

    /**
    *  get the type of the sensor
    *
    *  @return an int corresponding to the enum sensor Family
    */
    virtual int getSensorFamily(void);
};

#endif

