#include <Wire.h>
#include <SoftwareSerial.h>
int x = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = Wire.read();
  Serial.println(x * -1);
  delay(2000);
}
