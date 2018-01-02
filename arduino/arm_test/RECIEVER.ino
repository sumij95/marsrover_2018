void reciever_test()
{
#if DEBUG
  for (int i = 3; i < 4; i++)
  {
    int in = pulseIn(ch[i], HIGH);
    Serial.print(i);
    Serial.print(' ');
    Serial.print(in);
    Serial.print(' ');
    Serial.print( map( in, 1000, 2000, -255, 255));
    Serial.print(' ');
  }
  Serial.println();
#endif
}

