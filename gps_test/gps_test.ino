#include <SoftwareSerial.h>
#include <TinyGPS++.h>

int RXPin = 1;
int TXPin = 2;
int GPSBaud = 9600;

SoftwareSerial serial_connection(RXPin, TXPin);
TinyGPSPlus gps;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  serial_connection.begin(9600);
  Serial.println("GPS Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  while (serial_connection.available()){
    gps.encode(serial_connection.read());
  }
  if(gps.location.isUpdated()){
    Serial.println("Satellite Count: ");
    Serial.print(gps.satellites.value());
    Serial.println("Lattitude: ");
    Serial.print(gps.location.lat(), 6);
    Serial.println("Longitude: ");
    Serial.print(gps.location.lng(), 6);
    Serial.println("Altitude Feet: ");
    Serial.print(gps.altitude.feet());
  }
}
