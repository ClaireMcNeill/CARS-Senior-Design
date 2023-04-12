#include <SoftwareSerial.h>
#include <DFRobot_LIDAR07.h>

DFRobot_LIDAR07_IIC ToF;

//SoftwareSerial ToF_connect(18, 19);

void setup() {
  // put your setup code here, to run once:
  ToF.begin();
  Serial.begin(9600);
  ToF.setMeasureMode(ToF.eLidar07Continuous);
  ToF.setConMeasureFreq(100);
  ToF.startMeasure();
  ToF.startFilter();
  
}

void loop() {
  // put your main code here, to run repeatedly:
    ToF.getValue();
    Serial.print("Distance:");
    Serial.print(ToF.getDistanceMM());
    Serial.println(" mm");
    Serial.print("Amplitude:");
    Serial.println(ToF.getSignalAmplitude());
    delay(1000);
}