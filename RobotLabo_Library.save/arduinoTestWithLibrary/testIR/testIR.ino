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

IRSharp4To30 irLeft("ir4To30Left", 0);
IRSharp10To80 irRight("ir10To80Right", 2);


void setup() {
  Serial.begin(9600);

  irLeft.setup();
  irRight.setup();

}

void loop() {
  Serial.print("distance value sensor left = ");
  Serial.println(irLeft.getValue());

  Serial.print("distance precision value sensor left = ");
  Serial.println(irLeft.getPrecisionValue());
  delay(1000);


  Serial.print("distance value sensor right = ");
  Serial.println(irRight.getValue());

  Serial.print("distance precision value sensor right = ");
  Serial.println(irRight.getPrecisionValue());
  delay(1000);

}
