#include <Servo.h>

#include <light_CD74HC4067.h>
CD74HC4067 mux(A0, A1, A2, A3); // ตัวรับส่งสัญญาณ

Servo esc;
#define pwmA 5
#define dir1A 2
#define dir2A 3
#define pwmB 6
#define dir1B 4
#define dir2B 7

#define numsensor 16
int Max[numsensor] = {852, 828, 841, 831, 829, 833, 838, 827, 831, 836, 889, 827, 825, 836, 835, 847};
int Min[numsensor] = {287, 162, 204, 172, 174, 190, 253, 178, 201, 225, 203, 187, 220, 261, 255, 202};

const int signal_pin = A4;
unsigned long sensorValue[numsensor];
int Background = 0;
int last_value;
int on_line = 0;
float leftmotor, rightmotor, powermotor, error, last_error, position;

void setup()
{
  initt();

  // view();
  // viewReadLine();
  // viewDistance();

  digitalWrite(13, HIGH);
  while (analogRead(6) > 500)
    ;
  delay(200);
  digitalWrite(13, LOW);

  openfan(1500);
  delay(300);
  trackTime(55, 0.0135, 0.13, 10000);

  // trackTime(35, 0.0135, 0.13, 1000);
  // TrackB(35, 0.0135, 0.13);
  // trackTime(35, 0.0135, 0.13, 600);
  // trackObject(30, 0.0135, 0.13);
  // DodgeL();
  // trackTime(45, 0.0135, 0.13,4000);

  // trackTime(50, 0.0135, 0.13, 4000);
  // trackTime(50, 0.0135, 0.13, 650);
  // trackObject(50, 0.0135, 0.13);
  // DodgeL();
  // trackTime(50, 0.0135, 0.13, 650);
  // TrackB(40, 0.0135, 0.13);

  Motor(0, 0);
  delay(100);
  esc.writeMicroseconds(0);
}

void loop()
{
}