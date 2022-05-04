
#include <Wire.h>
#define RED 8
#define GREEN 9 //Defining lEDS
#define BLUE 7
float x=0;
void setup(){
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(GREEN,OUTPUT);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
  }
  void receiveEvent(int bytes){
    
    x=Wire.read();  
    }
    void loop(){
      
      //applying conditions
      if (x=='r'){
        digitalWrite(RED,HIGH);
        digitalWrite(GREEN,LOW);
        digitalWrite(BLUE,LOW);
        
        }
if (x == 'g'){
        digitalWrite(RED,LOW);
        digitalWrite(GREEN,HIGH);
        digitalWrite(BLUE,LOW);
        }
        if (x == 'b'){
        digitalWrite(RED,LOW);
        digitalWrite(GREEN,LOW);
        digitalWrite(BLUE,HIGH);
        }

if (x == '0'){
        digitalWrite(RED,LOW);
        digitalWrite(GREEN,LOW);
        digitalWrite(BLUE,LOW);
        }

        if (x == 'm'){
        digitalWrite(RED,HIGH);
        digitalWrite(GREEN,HIGH);
        digitalWrite(BLUE,LOW);
        }
        if (x == 'l'){
        digitalWrite(RED,LOW);
        digitalWrite(GREEN,HIGH);
        digitalWrite(BLUE,HIGH);
        }
        if (x == 'f'){
        digitalWrite(RED,HIGH);
        digitalWrite(GREEN,LOW);
        digitalWrite(BLUE,HIGH);
        }

        if (x == 'h'){
        digitalWrite(RED,HIGH);
        digitalWrite(GREEN,HIGH);
        digitalWrite(BLUE,HIGH);
        
        }
      }
