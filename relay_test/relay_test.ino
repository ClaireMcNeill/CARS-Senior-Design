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
  digitalWrite(R1, ON);
  digitalWrite(R2, ON);
  digitalWrite(R3, ON);
  digitalWrite(R4, ON);
  digitalWrite(R1, OFF);
  digitalWrite(R2, OFF);
  digitalWrite(R3, OFF);
  digitalWrite(R4, OFF);
}