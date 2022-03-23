#include <stdio.h>

const int LED_red = 6;
const int LED_green = 3;
const int buttonPin = 4; //button pin for switch
const int buttonPin2 = 13; //button pin for incrementing
const int buttonPin3 = 12; //button pin for decrementing

int buttonState1 = 0; // variable for reading the pushbutton status

int status = 2;
int i = 0;
int red_status = 0;
int count = 0;
int blinkTemp = 0;
int blinkSpeed = 0;

void setup() {
  pinMode(LED_red, OUTPUT);
  pinMode(LED_green, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  Serial.begin(9600);
  Serial.println("starting ...");
  // Serial.println(buttonState2);
  // Serial.println(buttonState1);
}

void loop() {
  blinkTemp = 0;
  buttonState1 = digitalRead(buttonPin);


  if (digitalRead(buttonPin2) == LOW) {
    while(digitalRead(buttonPin2) == LOW){};
    count++;
  }
  if (digitalRead(buttonPin3) == LOW) {
    while(digitalRead(buttonPin3) == LOW){};
    count--;
  }
  blinkSpeed = 500 / count;

  if (buttonState1 == HIGH) {
    if (status == 1) {
      delay(100);
    } else {
      Serial.write(12);
      Serial.println("button was released");
      digitalWrite(LED_red, HIGH);
      digitalWrite(LED_green, LOW);
      red_status++;
      i++;
      Serial.println("Turning: red on and green off ");
      Serial.print("Red led has changed ");
      Serial.print(red_status);
      Serial.println(" times");
      Serial.println("Number of times leds were ");
      Serial.print("turned on/off: ");
      Serial.println(i);
    }
    status = 1;
  } else {
    if (status == 2) {
      delay(100);
    } else { 
      Serial.write(12);
      Serial.println("button was pressed");
      digitalWrite(LED_red, LOW);
      // digitalWrite(LED_green, HIGH);
      i++;
      Serial.println("Turning: red off and green on");
      Serial.println("Number of times leds were ");
      Serial.print("turned on/off: ");
      Serial.println(i);
      Serial.print("Frequency ");
      Serial.println(count);
        while (blinkTemp < count) {
          digitalWrite(LED_green, HIGH);
          delay(blinkSpeed);
          digitalWrite(LED_green, LOW);
          delay(blinkSpeed);
          blinkTemp++;
      }
    }
    status = 2;
  }

}