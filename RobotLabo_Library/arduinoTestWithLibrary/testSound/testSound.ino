#include <Actioner.h>
#include <ColorSensorTCS3200.h>
#include <Encoder.h>
#include <IRSharp10To80.h>
#include <IRSharp4To30.h>
#include <LightActionner.h>
#include <Motor.h>
#include <MotorContinu.h>
#include <resource.h>
#include <Sensor.h>
#include <Servo180.h>
#include <Sound.h>
#include <UltrasonicSensorHCSR04.h>

Sound mySound("melody", 30);

void setup() {
  Serial.begin(9600);

  while (!Serial)
  {
  }

  mySound.setup();
}

void loop() {
  mySound.doAction(1);
  delay(1000);
  mySound.doAction(4);
  delay(1000);

}
