#define RS 5
#define RW 6
#define EN 7

void setup() {
  // put your setup code here, to run once:
  pinMode(RS,OUTPUT); // High is Display Data
  digitalWrite(RS,0); // Low is Configuration Registers
  pinMode(RW,OUTPUT); // Read or Write 
  digitalWrite(RW,0); // always writing -- LOW
  pinMode(EN,OUTPUT); // Data Clock
  digitalWrite(EN,1); // Pulse low to latch data
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT); 
  pinMode(11,OUTPUT); // 4 bit wide Databus to write to LCD
  setupLCD();
  writeLCD("Hello World");
}

void setupLCD(){
  //Setup sequence
  digitalWrite(RS,0);
  LCDByte(0b00001100); // Turn on Display
  delayMicroseconds(40);
  LCDByte(0b00101000); // 4 bit interface, 2 lines, 5x8 font
  delayMicroseconds(40);
  LCDByte(0b00000001); // Clear Display and set cursor at home
  delay(2);
}

void writeLCD(char *displayData){
  int stringIndex = 0;
  digitalWrite(RS,1);
  do{
    LCDByte(displayData[stringIndex++]);
    delayMicroseconds(40);
  }while (displayData[stringIndex] !=0);
}
void LCDByte(byte data){
  PORTB = (PORTB & 0XF0) | ((data >>4) & 0x0F);// MSBits
  digitalWrite(EN,0); // Latch data into LCD
  digitalWrite(EN,1);
  PORTB = (PORTB & 0XF0) | (data & 0x0F); // LSBits
  digitalWrite(EN,0); // Latch data into LCD
  digitalWrite(EN,1);
}
void loop() {
  // put your main code here, to run repeatedly:

}
