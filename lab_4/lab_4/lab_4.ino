#include <stdio.h>
#include <stdlib.h>

#define M1 7
#define M2 6
String command;
const int ledPin =  13;
String turn_on = "on";
String turn_off = "off";
String turn_forward = "+";
String turn_backward = "-";

void setup() {
  Serial.begin(9600);
  pinMode(M1,OUTPUT) ; 
  pinMode(M2,OUTPUT) ;
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
      // Serial.println("lol");
      command = Serial.readString();
      // command = led_on;
      if (command == turn_on){
        Serial.println("turning the led on \n");
        digitalWrite(ledPin, HIGH);  
        command = ""; 
     }
      if (command == turn_off){
        Serial.println("turning the led off \n");
        digitalWrite(ledPin, LOW);          
        digitalWrite(M1,LOW) ;
        digitalWrite(M2,LOW) ;
        command = ""; 
      }
      if (command == turn_forward){
        Serial.println("turning motor forward \n");          
        digitalWrite(M1,HIGH) ;
        digitalWrite(M2,LOW) ;
        command = ""; 
      }
      if (command == turn_backward){
        Serial.println("turning motor backward \n");          
        digitalWrite(M1,LOW) ;
        digitalWrite(M2,HIGH) ;
        command = ""; 
      }  
  }  
}