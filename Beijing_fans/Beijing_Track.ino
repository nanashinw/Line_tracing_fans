void TrackNormal(int BaseSpeed, float kp, float kd)
{
  position = ReadLine();
  error = position - 7500;
  powermotor = (kp * error) + (kd * (error - last_error));
  last_error = error;
  leftmotor = BaseSpeed + powermotor;
  rightmotor = BaseSpeed - powermotor;
  if (leftmotor > 100)
    leftmotor = 100;
  if (leftmotor <= -100)
    leftmotor = -100;
  if (rightmotor > 100)
    rightmotor = 100;
  if (rightmotor <= -100)
    rightmotor = -100;
  Motor(leftmotor, rightmotor);
}

void trackTime(int BaseSpeed, float kp, float kd, long timer)
{
  unsigned long Last_time = millis();
  while (millis() - Last_time < timer)
  {
    TrackNormal(BaseSpeed, kp, kd);
  }
}

void trackObject(int BaseSpeed, float kp, float kd)
{
  unsigned long Last_time = millis();
  while (digitalRead(11))
  {
    TrackNormal(BaseSpeed, kp, kd);
  }
}

void DodgeR()
{
  Motor(0, 0);
  delay(100);

  Motor(50, -50); // SpinR
  delay(70);

  Motor(30, 80); // Run back to line
  delay(150);

  ReadLine();
  unsigned long Last_time = millis();
  while (sensorValue[0] < 400 && millis() - Last_time < 1000)
  {
    ReadLine();
    Motor(10, 85);
  }
}

void DodgeL()
{
  Motor(0, 0);
  delay(100);

  Motor(-50, 50); // SpinR
  delay(80);

  Motor(80, 30); // Run back to line
  delay(100);

  ReadLine();
  unsigned long Last_time = millis();
  while (sensorValue[15] < 400)
  {
    ReadLine();
    Motor(85, 10);
  }
}

// void closeline(int BaseSpeed, float kp, float kd, long timer)
// {
//   unsigned long Last_time = millis();
//   ReadLine();
//   while (on_line && millis() - Last_time < timer)
//   {
//     TrackNormal(BaseSpeed, kp, kd);
//   }

void TrackB(int BaseSpeed, float kp, float kd)
{
  unsigned long Last_time = millis();
  while (digitalRead(11))
  {
    TrackNormal(BaseSpeed, kp, kd);
  }
  trackTime(50, 0.0135, 0.13, 100);
  ReadLine();
  // while (sensorValue[0] < 200 || sensorValue[15] < 200)
  // {
  //   TrackNormal(10, 0.0135, 0.13);
  // }
  ReadLine();
  Motor(0, 0);
  delay(275);
}