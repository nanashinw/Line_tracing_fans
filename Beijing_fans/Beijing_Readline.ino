int ReadLine()
{
  int k;
  on_line = 0;
  unsigned long avg = 0;
  unsigned int sum = 0;
  unsigned long value = 0;
  on_line = 0;
  Read();
  avg = 0;
  sum = 0;
  for (int i = 0; i < numsensor; i++)
  {
    value = sensorValue[i];
    if (Background == 1)
    {
      value = 1000 - value;
      sensorValue[i] = value;
    }
    if (value > 200)
      on_line = 1;
    if (value > 50)
    {
      avg += value * (i * 1000);
      sum += value;
    }
  }
  if (on_line == 0)
  {
    if (last_value < ((numsensor - 1) * 1000) / 2)
    {
      return 0;
    }
    else
    {
      return (numsensor - 1) * 1000;
    }
  }
  else
  {
    last_value = avg / sum;
  }
  return last_value;
}