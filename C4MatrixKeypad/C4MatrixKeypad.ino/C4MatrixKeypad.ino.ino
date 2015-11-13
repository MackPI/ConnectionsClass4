#include <TimerOne.h>
#define ROWMASK 0x0F

static bool GotKeypress = false;
static long KeyBuffer;
// the setup function runs once when you press reset or power the board
void setup() {
  digitalWrite(4,0); pinMode(4,INPUT); // These inputs 
  digitalWrite(4,0); pinMode(5,INPUT); // will drive low when
  digitalWrite(4,0); pinMode(6,INPUT); // set to outputs
  digitalWrite(4,0); pinMode(7,INPUT); 
  
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  Timer1.initialize(5000); //Interrupt every 5 milliseconds
  Timer1.attachInterrupt(KeypadScan);
  Serial.begin(9600);
}

/*  KeypadScan() Interrupt Service Routine
 *  Assumes IO 0-3 for Row pins
 *          IO 4-7 for Column pins  */
void KeypadScan(){ // Implements keypad scanning
  static int Column = 4;
  static long KeyState, KeyHistory;
  int Row;
  pinMode(Column,OUTPUT); // Strobe column low
  Row = ~PINB & ROWMASK; 
  KeyState = KeyState | Row<<((Column-4)*4);
  pinMode(Column,INPUT); 
  Column++;
  if (Column > 7){
    if (KeyState != KeyHistory) {
      if (KeyState){
        KeyBuffer = KeyState;
        GotKeypress = true;
      }
      KeyHistory = KeyState;
    }
    Column = 4;
    KeyState = 0;
  }
}

// the loop function runs over and over again forever
void loop() {
  const char KeyVal[] = {'','','','',
                         '','','','',
                         '','','','',
                         '','','',''};
  int KeyIndex;
  if (GotKeypress){
    for (KeyIndex = 0; KeyIndex <16; KeyIndex++){
      if(KeyBuffer & (1 << KeyIndex)) Serial.print(KeyVal[KeyIndex]);
    }
    GotKeypress = false;
  }
}


