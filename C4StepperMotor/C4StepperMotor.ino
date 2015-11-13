#define PhA1 2
#define PhA2 3
#define PhB1 12
#define PhB2 13
#define PhaseDelay 100
void setup() {
  // put your setup code here, to run once:
  pinMode(PhA1,OUTPUT);
  pinMode(PhA2,OUTPUT);
  pinMode(PhB1,OUTPUT);
  pinMode(PhB2,OUTPUT);
  digitalWrite(PhA1,0); // no power to motor
  digitalWrite(PhA2,0);
  digitalWrite(PhB1,0);
  digitalWrite(PhB2,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PhA1,1); // Energize Phase A coil Positive \
  delay(PhaseDelay); //let motor find new position
  digitalWrite(PhB2,0); // De Energize Phase B coil       ^
  delay(PhaseDelay); //let motor find new position
  digitalWrite(PhB1,1); // Energize Phase B coil Positive /
  delay(PhaseDelay); //let motor find new position
  digitalWrite(PhA1,0); // De Energize Phase A coil       >
  delay(PhaseDelay); //let motor find new position
  digitalWrite(PhA2,1); // Energize Phase A coil Negative \
  delay(PhaseDelay); //let motor find new position
  digitalWrite(PhB1,0); // De Energize Phase B coil       |
  delay(PhaseDelay); //let motor find new position
  digitalWrite(PhB2,1); // Energize Phase B coil Negative /
  delay(PhaseDelay); //let motor find new position
  digitalWrite(PhA2,0); // De Energize Phase A coil       <
  delay(PhaseDelay); //let motor find new position
  
}
