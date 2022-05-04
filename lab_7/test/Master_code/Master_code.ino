#include <Wire.h>

char incomingByte;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Wire.begin();
  Serial.println("Welcome to my program");
Serial.println("red- r");
Serial.println("blue- b");
Serial.println("green- g");
Serial.println("red, green- f");
Serial.println("green, blue- l");
Serial.println("red, blue- m");
Serial.println("all- h");
Serial.println("all off- 0");
}

void loop() {
  // put your main code here, to run repeatedly:
Wire.beginTransmission(9);
if (Serial.available()){
  
  while(Serial.available()>0){
    
    incomingByte=Serial.read();
    Wire.write(incomingByte);
    Serial.println(incomingByte);
    Wire.endTransmission();
  
    
    
    }
  }
}
