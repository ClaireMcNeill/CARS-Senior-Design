#include <Wire.h>
#include <SoftwareSerial.h>
unsigned int x = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(9);
  Serial.begin(9600);
  Wire.onReceive(receiveEvent);
}

void receiveEvent(int bytes){
  x = Wire.read();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(x);
  delay(2000);
}
