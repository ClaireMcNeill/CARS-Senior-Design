#include <SoftwareSerial.h>
#include <DFRobot_LIDAR07.h>
#include <TinyGPS++.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define ON  0
#define OFF 1
RF24 nrf(3, 2);
const byte linkAddress[6] = "link1";
char data[3];



/*
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
  int sensorValue = analogRead(dataPin);
  pressure = sensorValue * (7.25/1023.0);
}
*/
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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  nrf.begin();
  nrf.openReadingPipe(0, linkAddress);
  nrf.startListening();
  RELAY_Init();
  //GPS_Init();
  //TOF_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print(F("\nEnter Command: \n1 Read Pressure\n2 Read ToF\n3 Read GPS\n4 Toggle R1\n5 Toggle R2\n6 Toggle R3\n7 Toggle R4\n8 End Program"));
  if(nrf.available()){
    nrf.read(&data, sizeof(data));
    switch (data[2])  {
      /*case '1': //read pressure sensor
        readPressure();
        Serial.println(F("Pressure: "));
        Serial.print(pressure);
        Serial.print(F(" psi"));
        break;
      case '2': //Read ToF sensor
        ToF_sensor.getValue();
        Serial.print(F("Distance:"));
        Serial.print(ToF_sensor.getDistanceMM());
        Serial.println(F(" mm"));
        Serial.print(F("Amplitude:"));
        Serial.println(ToF_sensor.getSignalAmplitude());
        break;
      case '3':
        gps_antenna.encode(gps_connection.read());
        Serial.println(F("Satellite Count: "));
        Serial.print(gps_antenna.satellites.value());
        Serial.println(F("Lattitude: "));
        Serial.print(gps_antenna.location.lat(), 6);
        Serial.println(F("Longitude: "));
        Serial.print(gps_antenna.location.lng(), 6);
        Serial.println(F("Altitude Feet: "));
        Serial.print(gps_antenna.altitude.feet());
        break;
        */
      case '4':
        if(digitalRead(R1)==0)
          digitalWrite(R1, OFF);
        else
          digitalWrite(R1, ON);
        break;
      case '5':
        if(digitalRead(R2)==0)
          digitalWrite(R2, OFF);
        else
          digitalWrite(R2, ON);
        break;
      case '6':
        if(digitalRead(R3)==0)
          digitalWrite(R3, OFF);
        else
          digitalWrite(R3, ON);
        break;
      case '7':
        if(digitalRead(R4)==0)
          digitalWrite(R4, OFF);
        else
          digitalWrite(R4, ON);
        break;
      case '8':
        exit(0);
        break;
      
    }
  delay(1000);

  }
    

}
