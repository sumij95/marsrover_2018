#include "IBT.h"
#include "L298.h"
#include <Servo.h>

#define DEBUG 1


//body
IBT left(12, 11);
IBT right(10, 9);

// arms
IBT base(8, 7);
IBT roll(6, 5);
Servo grabber;
Servo kg30;


// body


// 8 channel reciever, first one is removed to eradicate amiguity because of ZERO indexing
int ch[9];

void setup() {

  grabber.attach(3);
  grabber.write(40);
  kg30.attach(2);
  kg30.write(40);

  
#if DEBUG
  Serial.begin(9600);
#endif

  // ch[ channel no. ] = pin number in arduino
  ch[1] = 23;
  ch[2] = 25;
  ch[3] = 27;
  ch[4] = 29;
  ch[5] = 31;
  ch[6] = 33;
  ch[7] = 35;
  ch[8] = 37;

  //reciever_setup
  for (int i = 0; i < 9; i++)pinMode(ch[i], INPUT);
}

void loop() {
  int in = pulseIn(ch[6], HIGH);
  if (in > 1700) arm();
  else if ( in < 1200) body();
//  reciever_test();
}
