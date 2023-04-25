#include<SoftwareSerial.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 nrf(9, 8);  // CE, CSN

const byte linkAddress[6] = "link1";
//float QNH = 1022.67; //Change the "1022.67" to your current sea level barrometric pressure (https://www.wunderground.com)
//const int BMP_address = 0x76;

//float pressure;   
//float message;  
char data[3];
char charVal[17];
////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);
  Serial.println("NRF24L01 link");
  nrf.begin(); 
  nrf.openWritingPipe(linkAddress);  //set the address 
  //nrf.setPALevel(RF24_PA_LOW);   //keep tx level low to stop psu noise, can remove this but then put in decoupling caps
  // Options are: RF24_PA_MIN=-18dBm, RF24_PA_LOW=-12dBm,  RF24_PA_HIGH=0dBm.
  nrf.setPALevel(RF24_PA_HIGH); 
  nrf.stopListening();  //act as a transmitter
}
///////////////////////////////////////////////////
void loop()
{  
 //pressure = bmp.readPressure()/100;  //and conv Pa to hPa
 //message = bmp.readTemperature(); //change to read message
  Serial.print(F("\nEnter Command: \n1 Read Pressure\n2 Read ToF\n3 Read GPS\n4 Toggle R1\n5 Toggle R2\n6 Toggle R3\n7 Toggle R4\n8 End Program"));
  while (Serial.available() == 0) {}  //wait for data available
  char ans = Serial.read();  //read until timeout
  delay(100);
  Serial.flush();
  
 //data[0] = pressure;
 //data[1] = message;
  data[2] = ans;
 //----- display on local monitor: ------------
 //Serial.print(data[0]); Serial.print("hPa  ");
 //Serial.print(data[1]); 
 //Serial.write(0xC2);  //send degree symbol
 //Serial.write(0xB0);  //send degree symbol
 //Serial.print("C   ");  
  Serial.print(data[2]);
 //---------------------------------------------
 
  nrf.write(data, sizeof(data)); //spit out the data array
  
  delay(300);
}