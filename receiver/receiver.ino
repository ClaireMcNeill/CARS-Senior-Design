#include <SoftwareSerial.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 nrf(9,8);
const byte linkAddress[6] = "link1";
const byte greenLED = 10;
float data[3];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Waiting to recieve communications");
  pinMode(greenLED, OUTPUT);
 
  nrf.begin();    
  nrf.openReadingPipe(0, linkAddress);  //set the address 
  nrf.startListening();   //Set nrf as receiver
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenLED, HIGH);
   delay(50);
   digitalWrite(greenLED, LOW);
   delay(50);
   
   if (nrf.available())  //Read the data if available in buffer
     {
      nrf.read(&data, sizeof(data));
     //Serial.print(data[0]); Serial.print("hPa  ");
     //Serial.print(data[1]); 
     //Serial.write(0xC2);  //send degree symbol
     //Serial.write(0xB0);  //send degree symbol
     //Serial.print("C   ");  
     Serial.print(data[2]/304.8); Serial.println("mm");  
     }  
}
