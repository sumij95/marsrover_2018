#define FROMLOW 1000
#define FROMHIGH 2000
#define TOLOW -255
#define TOHIGH 255

#define ACTIVATION_VALUE 50

byte base_, actuator1_, actuator2_, roll_, grabber_;


void arm()
{
  base_ = map( pulseIn(ch[2] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);
  actuator1_ = map( pulseIn(ch[1] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);
  actuator2_ = map (pulseIn(ch[1] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);
  roll_ = map(pulseIn(ch[1] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);
  grabber_ = map(pulseIn(ch[1] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);

  if ( abs(base_) < ACTIVATION_VALUE) base_ = 0;
  if ( abs(actuator1_) < ACTIVATION_VALUE) actuator1_ = 0;
  if ( abs(actuator2_) < ACTIVATION_VALUE) actuator2_ = 0;
  if ( abs(roll_) < ACTIVATION_VALUE) roll_ = 0;
  if (abs(grabber_) < ACTIVATION_VALUE ) grabber_ = 0;

  move_it(base, base_);
  move_it(actuator1, actuator1_);
  move_it(actuator2, actuator2_);
  move_it(roll, roll_);
  move_it(grabber, grabber_);

}


void move_it(IBT &obj, byte pwm)
{
  if ( pwm > 0)
    obj.rotPos(pwm);
  else
    obj.rotNeg(pwm * (-1));
}



void move_it(L298 &obj, byte pwm)
{
  if ( pwm > 0)
    obj.rotPos(pwm);
  else
    obj.rotNeg(pwm * (-1));
}

