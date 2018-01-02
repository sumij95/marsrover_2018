

#ifndef ServoMOD_H
#define ServoMOD_H

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#include<Servo.h>
#define _minimumPosition 10
#define _maximumPosition 170

class ServoMOD
{
  public:
    ServoMOD(byte pin);
    void rotPos();
    void rotNeg();
    byte poistion();
  private:
    Servo obj;
    byte _currentPosition;
    byte _pin;
};

#endif
