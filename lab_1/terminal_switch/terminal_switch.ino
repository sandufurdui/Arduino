#include <stdio.h>
#include <stdlib.h>

char command;     // for incoming serial data
int commandLength = 0;
const int ledPin =  13;      // the number of the LED pin

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // send data only when you receive data:
  if (Serial.available() > 0) {
      command = Serial.read();
      if (command == 111){
        Serial.println("turning the led on \n");
        digitalWrite(ledPin, HIGH);
      }else if (command == 102){
        Serial.println("turning the led off \n");
        digitalWrite(ledPin, LOW);
      }
  }
}