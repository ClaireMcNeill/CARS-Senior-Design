/* 
Startup: 
- Set relays to proper position
- read sensors and confirm connection
- read gps and confirm connection (depends on connection time)

Deployment:
- swich solenoids to fill
- turn on compressor
- monitor pressure/height

At Height:
- monitor pressure/height
  - operate compressor as needed
- start antenna connection
- obtiain readings
- verify position

Collapse: 
- switch off antenna
- switch solenoids to drain/vacuum
- check height/pressure
- wait for full collapse
- exit

** when checking pressure might have to cut compressor and close line ** 

*/
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

//Relay Pin Definition
 int Relay1 = 9; //Compressor 
 int Relay2 = 8; //Solenoid 1
 int Relay3 = 7; //Solenoid 2
 int Relay4 = 6; //Unoccupied

//GPS Pin Definition
 int RXPin = 3;
 int TXPin = 5;
 int GPSBaud = 9600;

//Sensor Reading Definition
int dataPin = A0;
int ms_from_start = 0;
int ms_last_read_pressure = 0;
int ms_last_read_height = 0;
int pressure_interval = 5000;
int height_interval = 5000;
float pressure;
float height;

 SofwareSerial gps_connection(RXPin, TXPin);
 TinyGPSPlus gps;

 #define ON 1;
 #define OFF 0;

void setup() {
  RELAY_Init();

  isError();
  while(!atHeight() && !atPressure()) {
    delay(500); //use millis() and an interval to check
  }
  antennaSetup();
  while(!isMessageRecieved()) {
    delay(500);
  }
  antennaShutdown();
  shutdown();

}

void RELAY_Init(){
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  digitalWrite(Relay1, OFF);
  digitalWrite(Relay2, OFF);
  digitalWrite(Relay3, OFF);
  digitalWrite(Relay4, OFF);
}

void GPS_Connect(){
  Serial.begin(GPS_Baud);
  gps_connection.begin(GPS_Baud);
  Serial.println("Antenna Powered");
}

void GPS_Disconnect(){
  gps_connection.end();
  Serial.println("Antenna Disconnected");
}

//Showing process for sensor reading without delay() function
//need to figure out how we want to implement this with the deployment
void sensorRead(int loop){
  int i = 0;  
  while(i < loop){
    ms_from_start = millis();
    if(ms_from_start - ms_last_read_pressure > pressure_interval){
      ms_last_read_pressure = ms_from_start;
      digitalWrite(Relay2, OFF); //close solenoid to prevent air escape
      digitalWrite(Relay1, OFF); //turn off compressor
      delay(250);
      readPressure();
      digitalWrite(Relay2, ON);
      digitalWrite(Relay1, ON);

    }
    if(ms_from_start - ms_last_read_height > height_interval){
      ms_last_read_height = ms_from_start;
      readHeight();
    }
  }

}

//analogRead() will return a value from 0-1023; can be scaled with sensorValue * (sensorRange/1023.0)
float readPressure(){
  int sensorValue = analogRead(dataPin);

}

float readHeight(){

}

bool atHeight() {
  // Checks the height of the tower consistantly until it is at the correct height
  while(height != 12ft) { // Will check the value of the height sensor
    delay(500)
  }
  return True
}

bool atPressure() {
  // Checks the pressure of the bladder via the pressure sensor
  // Manually open and close the valve to let air out
  while(pressure != ) { // Will check the value of the pressure sensor
    delay(500)
  }
  if(pressure > ) {
    // Release some air to get it back to correct pressure
  }
  return True

}

void isError() {
  // Checks for errors, are sensors all on and connected
  isErrorCritical(error);

}

void isErrorCritical(error) {
  // Checks for critical errors

}

void antennaSetup() {
  // Deploys antenna itself, opens connection and sends a message

}

void antennaShutdown() {
  // Once message is recieved, antenna is shut off

}

bool isMessageRecieved() {
  // Checks if the message was recieved
}

void shutdown() {
  // Brings tower down and shuts it off while checking height and pressure

}
