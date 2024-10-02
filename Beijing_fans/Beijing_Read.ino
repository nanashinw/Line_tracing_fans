void readPrivate()
{
  for (int i = 0; i < 16; i++) {
    mux.channel(i);
    sensorValue[i]  = analogRead(signal_pin);
  }
}

void Read() {
  readPrivate();
  for (int i = 0; i < numsensor; i++) {
    int x = 0;
    x = map(sensorValue[i], Min[i], Max[i], 0, 1000);
    if (x > 1000) x = 1000;
    if (x < 0) x = 0;
    sensorValue[i] = x;
  }
}

void view() {
  while (true) {
    readPrivate();
    for (int i = 0; i < numsensor; i++) {
      Serial.print(sensorValue[i]);
      Serial.print(",\t");
    }
    Serial.println(" ");
  }
}
void viewReadLine() {
  while (true) {
    ReadLine();
    for (int i = 0; i < numsensor; i++) {
      Serial.print(sensorValue[i]);
      Serial.print('\t');
    }
    Serial.println(ReadLine());
  }
}

void viewDistance(){
  while (true) {
    Serial.println(digitalRead(11));
  }
}