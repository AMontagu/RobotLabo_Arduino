#include <Actioner.h>
#include <ColorSensorTCS3200.h>
#include <Encoder.h>
#include <IRSharp10To80.h>
#include <LightActionner.h>
#include <Motor.h>
#include <MotorContinu.h>
#include <resource.h>
#include <Sensor.h>
#include <Servo180.h>
#include <Sound.h>
#include <UltrasonicSensorHCSR04.h>

UltrasonicSensorHCSR04 ultrasonicFront("firstSensor", 53, 52);
UltrasonicSensorHCSR04 ultrasonicBack("firstSensor", 49, 48);

void setup() {
  Serial.begin(9600);

  while (!Serial)
  {}

  ultrasonicFront.setup();
  ultrasonicBack.setup();
}

void loop() {
  if (ultrasonicFront.isSetup()) {
    Serial.println(ultrasonicFront.getValue());
  }
  delay(1000);

  if (ultrasonicBack.isSetup()) {
    Serial.println(ultrasonicBack.getValue());
  }
  delay(1000);
}
