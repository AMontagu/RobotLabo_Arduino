#include <Servo.h>

Servo myservoarm;  // create servo object to control a servo
Servo myservohand;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

void setup() {
  myservoarm.attach(9);  // attaches the servo on pin 9 to the servo object
  myservohand.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 90; pos <= 135; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservohand.write(pos);              // tell servo to go to position in variable 'pos'
     myservoarm.write(pos);              // tell servo to go to position in variable 'pos'
           
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 135; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservohand.write(pos);              // tell servo to go to position in variable 'pos'
    
    myservoarm.write(pos);              // tell servo to go to position in variable 'pos'
    
    delay(15);                       // waits 15ms for the servo to reach the position
  }











.












}

