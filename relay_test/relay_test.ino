int R1 = 9;
int R2 = 8;
int R3 = 7;
int R4 = 6;
#define ON  0
#define OFF 1



void setup() {
  // put your setup code here, to run once:
  RELAY_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
  RELAY_Toggle();
}

void RELAY_Init(){
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  pinMode(R3, OUTPUT);
  pinMode(R4, OUTPUT);
  digitalWrite(R1, OFF);
  digitalWrite(R2, OFF);
  digitalWrite(R3, OFF);
  digitalWrite(R4, OFF);
}

void RELAY_Toggle(){
  digitalWrite(R1, ON);
  delay(1000);
  digitalWrite(R1, OFF);
  delay(1000);
  digitalWrite(R2, ON);
  delay(1000);
  digitalWrite(R2, OFF);
  delay(1000);
}