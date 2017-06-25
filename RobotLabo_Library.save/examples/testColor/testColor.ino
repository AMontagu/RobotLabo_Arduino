#include <Actioner.h>
#include <ColorSensorTCS3200.h>
#include <Encoder.h>
#include <IRSharp10To80.h>
#include <IRSharp4To30.h>
#include <LightActionner.h>
#include <Motor.h>
#include <MotorContinu.h>
#include <resource.h>
#include <Robot.h>
#include <Sensor.h>
#include <Servo180.h>
#include <Sound.h>
#include <UltrasonicSensorHCSR04.h>

int s0=3,s1=4,s2=5,s3=6;
int out=2;

ColorSensorTCS3200 myColorSensor("colorRight", s0, s1, s2, s3, out);

void setup() {
  Serial.begin(115200);

  while (!Serial)
  {
  }

  Serial.println("begin");
  
  myColorSensor.setup();

}

void loop() {
  int color = myColorSensor.getValue();
  Serial.println(color);
  delay(3000);
}
