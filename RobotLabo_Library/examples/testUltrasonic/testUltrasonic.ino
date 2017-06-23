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
UltrasonicSensorHCSR04 ultrasonicRight("firstSensor", 45, 44);
UltrasonicSensorHCSR04 ultrasonicLeft("firstSensor", 41, 40);

void setup() {
  Serial.begin(115200);

  while (!Serial)
  {}

  ultrasonicFront.setup();
  ultrasonicBack.setup();
  ultrasonicRight.setup();
  ultrasonicLeft.setup();
}

void loop() {
  if (ultrasonicFront.isSetup()) {
    Serial.print("front = ");
    Serial.println(ultrasonicFront.getValue());
  }

  if (ultrasonicBack.isSetup()) {
    Serial.print("back = ");
    Serial.println(ultrasonicBack.getValue());
  }

  if (ultrasonicRight.isSetup()) {
    Serial.print("right = ");
    Serial.println(ultrasonicRight.getValue());
  }

  if (ultrasonicLeft.isSetup()) {
    Serial.print("left = ");
    Serial.println(ultrasonicLeft.getValue());
  }

  Serial.println();
  Serial.println();
  Serial.println();

  
  delay(2000);
}
