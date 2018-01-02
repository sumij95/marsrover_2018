#include<Servo.h>
#include "ServoMOD.h"


#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

ServoMOD::ServoMOD(byte pin) {
  _pin = pin;
  obj.attach(pin);
  _currentPosition = obj.read();
}

void ServoMOD::rotPos()
{
  if(_maximumPosition > _currentPosition)
  {
    _currentPosition ++;
    obj.write(_currentPosition);
  }
}

void ServoMOD::rotNeg()
{
  
  if(_minimumPosition < _currentPosition)
  {
    _currentPosition --;
    obj.write(_currentPosition);
  }
}

byte ServoMOD::poistion()
{
  return obj.read();
}

