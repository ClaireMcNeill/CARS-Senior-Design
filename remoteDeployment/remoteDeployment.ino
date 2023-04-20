#include <SoftwareSerial.h>
#include <DFRobot_LIDAR07.h>
#include <TinyGPS++.h>

#define ON  0
#define OFF 1

//add wifi communication module

//GPS Antenna Definitions using UART connection
SoftwareSerial gps_connection(0, 1);
TinyGPSPlus gps_antenna;

void GPS_Init(){
  gps_connection.begin(9600);
  Serial.println(F("GPS Antenna Initialized"));
}

//ToF Sensor Definitions defined as IIC connection
DFRobot_LIDAR07_IIC ToF_sensor;

void TOF_Init(){
  ToF_sensor.begin();
  ToF_sensor.setMeasureMode(ToF_sensor.eLidar07Continuous);
  ToF_sensor.setConMeasureFreq(100);
  ToF_sensor.startMeasure();
  ToF_sensor.startFilter();
  Serial.println(F("ToF Sensor Initialized"));
}

//Pressure Sensor Definitions
int dataPin = A0;
float pressure = 0;

float readPressure(){
  int sensorValue = analogRead(dataPin); //read from analog pin
  pressure = sensorValue * (7.25/1023.0); //Converting analog reading to PSI value
}

//Relay Definitions
int R1 = 9;
int R2 = 8;
int R3 = 7;
int R4 = 6;


void RELAY_Init(){ //change initial definitions once air system is finalized
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  digitalWrite(R1, OFF);
  digitalWrite(R2, OFF);
  digitalWrite(R3, OFF);
  digitalWrite(R4, OFF);
  Serial.println(F("Relays Initialized"));
}


void deploy(){
 //open fill solenoid
 //close drain solenoid
 //turn on compressor
}

void hold(){
  //close fill solenoid
  //close drain solenoid
  //turn off compressor

}

void packUp(){
  //open drain solenoid
  //close fill solenoid
  //turn off compressor

}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
