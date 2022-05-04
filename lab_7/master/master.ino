#include <Wire.h>

char x = 20;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.beginTransmission(9);
  Wire.write(x);
  Wire.endTransmission();
}
