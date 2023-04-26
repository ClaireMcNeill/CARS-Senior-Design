#include<SoftwareSerial.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 nrf(9, 8);  // CE, CSN

const byte linkAddress[6] = "link1";
 
char data[3];

////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);
  Serial.println("NRF24L01 link");
  nrf.begin(); 
  nrf.openWritingPipe(linkAddress);  //set the address 
  nrf.setPALevel(RF24_PA_HIGH); 
  nrf.stopListening();  //act as a transmitter
}
///////////////////////////////////////////////////
void loop()
{  
  Serial.print(F("\nEnter Command: \n1 Read Pressure\n2 Read ToF\n3 Read GPS\n4 Toggle R1\n5 Toggle R2\n6 Toggle R3\n7 Toggle R4\n8 End Program"));
  while (Serial.available() == 0) {}  //wait for data available
  char ans = Serial.read();  //read until timeout
  delay(100);
  Serial.flush();
  

  data[2] = ans;
   
  Serial.print(data[2]);
 //---------------------------------------------
 
  nrf.write(data, sizeof(data)); //spit out the data array

  nrf.stopListening();
  
  delay(300);
}