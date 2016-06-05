#include <SoftwareSerial.h>

SoftwareSerial mySerial(45, 44); // RX, TX

void setup() {
   mySerial.begin(9600);
   mySerial.print("AT+NAME123456789012345");
}

void loop() {
  mySerial.print("blabla");
  delay(1000);
}
