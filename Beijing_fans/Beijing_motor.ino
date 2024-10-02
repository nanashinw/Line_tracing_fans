
void Motor(int a, int b) {
  a = (a * 255) / 100;
  b = (b * 255) / 100;
  if (a == 0) {
    analogWrite(pwmA, 255);
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, LOW);
  }
  else if (a > 0) {
    digitalWrite(dir1A, HIGH);
    digitalWrite(dir2A, LOW);
    analogWrite(pwmA, a);
  }
  else {
    digitalWrite(dir1A, LOW);
    digitalWrite(dir2A, HIGH);
    analogWrite(pwmA, -a);
  }
  if (b == 0) {
    analogWrite(pwmB, 255);
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, LOW);
  }
  else if (b > 0) {
    digitalWrite(dir1B, LOW);
    digitalWrite(dir2B, HIGH);
    analogWrite(pwmB, b);
  }
  else {
    digitalWrite(dir1B, HIGH);
    digitalWrite(dir2B, LOW);
    analogWrite(pwmB, -b);
  }
}

void Move(int a, int b, int c) {
  Motor(a, b);
  delay(c);
}

void openfan(int sp) {
  for (int i = 1000; i < sp ; i++) {
    esc.writeMicroseconds(i);
    delay(3);
  }
}


void initt() {
  esc.attach(8);
  pinMode(pwmA, OUTPUT);
  pinMode(dir1A, OUTPUT);
  pinMode(dir2A, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(dir1B, OUTPUT);
  pinMode(dir2B, OUTPUT);
  pinMode(signal_pin, INPUT);
  Serial.begin(9600);
  for (int i = 0; i < 900 ; i++) {
    esc.writeMicroseconds(i);
    delay(5);
  }
}