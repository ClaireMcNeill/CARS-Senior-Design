#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Wire.h>
#include <String.h>

int RXPin = 0;
int TXPin = 1;
int GPSBaud = 9600;

unsigned int x = 40444;
unsigned int y = 7401;

SoftwareSerial serial_connection(RXPin, TXPin);
TinyGPSPlus gps;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(9);
  gps.encode(serial_connection.read());
  //Wire.write(gps.location.lat(), 2);
  //Wire.write(gps.location.lng(), 2);
  Serial.println(x);
  Serial.println(y);
  Wire.print(x);
  Wire.print(y);
  Wire.endTransmission();
  delay(2000);
}
