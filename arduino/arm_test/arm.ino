#define FROMLOW 1000
#define FROMHIGH 2000
#define TOLOW -255
#define TOHIGH 255

#define ACTIVATION_VALUE 50

int base_, kg30_, roll_, grabber_;


void arm()
{
  roll_ = map(pulseIn(ch[1] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);
  base_ = map( pulseIn(ch[4] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);
  grabber_ = map(pulseIn(ch[5] , HIGH), 900, 2100, 0, 180);
  kg30_ = map(pulseIn(ch[3] , HIGH), 850, 1910, 0, 180);


  if ( abs(base_) < ACTIVATION_VALUE) base_ = 0;
  if ( abs(roll_) < ACTIVATION_VALUE) roll_ = 0;

  grabber.write(grabber_);
  kg30.write(kg30_);

  move_it(base, base_);
  move_it(roll, roll_ * (-1));


#ifdef DEBUG
  Serial.print(roll_);
  Serial.print(' ');
  Serial.print(base_);
  Serial.print(' ');
  Serial.print(grabber_);
  Serial.print(' ');
  Serial.print(kg30_);
  Serial.print(' ');
  Serial.println();
#endif

}


void move_it(IBT &obj, int pwm)
{
  if ( pwm > 0)
    obj.rotPos(pwm);
  else
    obj.rotNeg(pwm * (-1));
}



void move_it(L298 &obj, int pwm)
{
  if ( pwm > 0)
    obj.rotPos(pwm);
  else
    obj.rotNeg(pwm * (-1));
}


