#include "IBT.h"



#define FROMLOW 1000
#define FROMHIGH 2000
#define TOLOW -255
#define TOHIGH 255
#define ACTIVATION_VALUE 50

IBT actuator1(11, 10);
IBT actuator2(6, 5);


// 8 channel reciever, first one is removed to eradicate amiguity because of ZERO indexing
int ch[9]; 

void setup() {
  ch[2] = 7;
  ch[6] = 8;
  ch[8] = 9;

  //reciever_setup
 pinMode(ch[2], INPUT);
 pinMode(ch[6], INPUT);
 pinMode(ch[8], INPUT);
}

int in;
void loop() {
  in = pulseIn(ch[6], HIGH);
  if (in > 1700) arm();
}

int actuator1_, actuator2_;
void arm()
{
  actuator1_ = map( pulseIn(ch[8] , HIGH), 800, 2100, TOLOW, TOHIGH);
  actuator2_ = map (pulseIn(ch[2] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);

  if ( abs(actuator1_) < ACTIVATION_VALUE) actuator1_ = 0;
  if ( abs(actuator2_) < ACTIVATION_VALUE) actuator2_ = 0;

  move_it(actuator1, (actuator1_ * (-1)));
  move_it(actuator2, actuator2_);
}


void move_it(IBT &obj, int pwm)
{
  if ( pwm > 0)
    obj.rotPos(pwm);
  else
    obj.rotNeg(pwm * (-1));
}

