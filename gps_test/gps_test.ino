#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <Wire.h>
#include <String.h>

int RXPin = 0;
int TXPin = 1;
int GPSBaud = 9600;

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
  //char lat[6] = gps.location.lat();
  //Wire.write(gps.location.lat(), 2);
  //Wire.write(gps.location.lng(), 2);
  int x = 1;
  Wire.write(x);
  Wire.endTransmission();
  delay(2000);
}
