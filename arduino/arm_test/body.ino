int speed_ = 0, dir_ = 0;


void body()
{
  speed_ = map( pulseIn(ch[2] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);
  dir_ = map( pulseIn(ch[4] , HIGH), FROMLOW, FROMHIGH, TOLOW, TOHIGH);


  if ( abs(speed_) < ACTIVATION_VALUE) speed_ = 0;
  if ( abs(dir_) < (ACTIVATION_VALUE + 50)) dir_ = 0;

#ifdef DEBUG
  Serial.print(speed_);
  Serial.print(' ');
  Serial.println(dir_);
#endif

  if (dir_ == 0) // no direction only forward and backward
  {
    if (speed_ < 0) //forward
    {
      speed_ = speed_ * (-1);
      move_it(left, speed_);
      move_it(right, speed_);
    }

    else if (speed_ > 0) {
      speed_ = speed_ * (-1);
      move_it(left, speed_);
      move_it(right, speed_);
    }
    else
    {
      move_it(left, 0);
      move_it(right, 0);

    }
  }
  else
  {
    if (dir_ < 0) // left
    {

      move_it(left, -100);
      move_it(right, 200);
    }
    else if (dir_ > 0) // right
    {
      move_it(left, 200);
      move_it(right, -100);
    }
  }
}
