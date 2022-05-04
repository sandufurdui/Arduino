#include <Wire.h>
int x = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Wire.onReceive(receive);
  Serial.begin(9600);
}

void receive(int byte){
  x = Wire.read();
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(x);
}
