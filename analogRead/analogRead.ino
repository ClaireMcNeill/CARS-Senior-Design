int dataPin = A0;
float pressure = 0;

float readPressure(){
  int sensorValue = analogRead(dataPin);
  pressure = sensorValue * (7.25/1023.0); //change this value once we know the sensors total operating range currently set for 7.25psi but range might be 15.2psi
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readPressure();
  Serial.println("Pressure Reading: ");
  Serial.print(pressure);
  Serial.print(" psi");
  delay(5000);
}
