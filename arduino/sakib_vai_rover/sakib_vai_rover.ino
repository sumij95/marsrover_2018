
#define Left_Lpwm 12
#define Left_Rpwm 11

#define Right_Lpwm 10
#define Right_Rpwm 9

int neg = 100;
int dir = 0;
byte pinSpeed = 25;
byte pinDirection = 29;






void setup() {
  Serial.begin(9600);

  pinMode(pinSpeed, INPUT);
  pinMode(pinDirection, INPUT);

  pinMode(Left_Lpwm, OUTPUT);
  pinMode(Left_Rpwm, OUTPUT);

  pinMode(Right_Lpwm, OUTPUT);
  pinMode(Right_Rpwm, OUTPUT);

}

int speed_ = 0, dir_ = 0;

void loop() {

  receiver();
}



void receiver()
{

  speed_ = pulseIn(pinSpeed, HIGH);

  dir_ = pulseIn(pinDirection, HIGH);

  speed_ = (int)((speed_ - 1500) / 1.8);

  if (speed_ < 0)
  {
    speed_ = (-1) * speed_;
    neg = 1;
  }
  else
  {
    neg = 0;
  }

  //Serial.println(dir_);
  dir = dir_;
  if (dir_ > 1550) dir_ = 1;
  else if (dir_ < 1400) dir_ = -1;
  else dir_ = 0;



  if ( dir_ == -1)
  {
    Serial.println(" left");

    dir = 1500 - dir;

    if (dir < 50)
    {
      dir = 0;
    }
    if (dir > 255)
    {
      dir = 255;
    }

    // Serial.println(dir);
    //delay(200);


    analogWrite(Left_Lpwm, dir);
    analogWrite(Left_Rpwm, 0);

    analogWrite(Right_Lpwm, 0);
    analogWrite(Right_Rpwm, dir);

  }
  else if ( dir_ == 1)
  {
    Serial.println(" RIght");

    dir = dir - 1450;

    if (dir < 50)
    {
      dir = 0;
    }
    if (dir > 255)
    {
      dir = 255;
    }
    //  Serial.println(dir);
    //   delay(200);



    analogWrite(Left_Lpwm, 0);
    analogWrite(Left_Rpwm, dir);

    analogWrite(Right_Lpwm, dir);
    analogWrite(Right_Rpwm, 0);

  }
  else
  {
    // Serial.println(" normal");
    if (speed_ < 100)
    {
      speed_ = 0;
    }
    
    if (neg == 0)
    { analogWrite(Left_Lpwm, speed_);
      analogWrite(Left_Rpwm, 0);

      analogWrite(Right_Lpwm, speed_);
      analogWrite(Right_Rpwm, 0);

    }
    else
    { analogWrite(Left_Lpwm, 0);
      analogWrite(Left_Rpwm, speed_);

      analogWrite(Right_Lpwm, 0);
      analogWrite(Right_Rpwm, speed_);
    }

  }
}
