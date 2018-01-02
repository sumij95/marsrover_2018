#include "IBT.h"
#include "L298.h"

#define DEBUG 1


// arms
IBT base(1,1);
IBT actuator1(1,1);
IBT actuator2(1,1);
L298 roll(1,1,3);
IBT grabber(1,1);


L298 rot(2, 3, 4);

// 8 channel reciever, first one is removed to eradicate amiguity because of ZERO indexing
int ch[9];




//
//
//void move_it(L298 obj, byte pwm)
//{
//  if ( pwm > 0)
//    obj.rotPos(pwm);
//  else
//    obj.rotNeg(pwm * (-1));
//}


void setup() {
  
#if DEBUG
  Serial.begin(9600);
#endif
  
// ch[ channel no. ] = pin number in arduino
ch[1] = 37;
ch[2] = 39;
ch[3] = 41;
ch[4] = 43;
ch[5] = 45;
ch[6] = 47;
ch[7] = 49;
ch[8] = 51;

  //reciever_setup
  for (int i = 0; i < 9; i++)
  {
    pinMode(ch[i], INPUT);
  }

}

void loop() {
//  arm();
 reciever_test();
}


