#include <Wire.h>

#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13,
  en = 12,
  d4 = 11,
  d5 = 10,
  d6 = 9,
  d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int buttonPin2 = 6; //button pin for incrementing
const int buttonPin3 = 5; //button pin for decrementing
const int buttonPin4 = 4; //button pin for incrementing
const int buttonPin5 = 3; //button pin for decrementing
const int motorPort1 = A4;
const int motorPort2 = A5;

const int sensorPin = A0;
const int heaterPort = 7;
int treshold = 20;
int speed = 150;

void setup() {
  // pinMode (aqSensor,INPUT); // MQ135 is connected as INPUT to arduino
  pinMode(7, OUTPUT);
  lcd.begin(16, 4);
  lcd.print("Starting");
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  // delay(1000);
}

void loop() {
  int reading = analogRead(sensorPin);
  
  if (digitalRead(buttonPin2) == LOW) {
    while (digitalRead(buttonPin2) == LOW) {};
    treshold++;
  }
  if (digitalRead(buttonPin3) == LOW) {
    while (digitalRead(buttonPin3) == LOW) {};
    treshold--;
  }
  if (digitalRead(buttonPin4) == LOW) {
    while (digitalRead(buttonPin4) == LOW) {};
    speed++;
  }
  if (digitalRead(buttonPin5) == LOW) {
    while (digitalRead(buttonPin5) == LOW) {};
    speed--;
  }
  

  // converting that reading to voltage, for 3.3v arduino use 3.3
  float voltage = reading * 5.0;
  voltage /= 1024.0;

  // now print out the temperature
  float temperatureC = (voltage - 0.5) * 100; //converting from 10 mv per degree with 500 mV offset                                                      
  lcd.setCursor(0, 0);lcd.print("Current ");lcd.print(temperatureC);lcd.println(F(" \xDF""C"));
  lcd.setCursor(0, 1);lcd.print("Goal ");lcd.println(treshold);lcd.print(F("\xDF""C"));
  lcd.setCursor(0, 2);lcd.print("Speed ");lcd.println(speed);   
  
  if (temperatureC < treshold) {
    digitalWrite(heaterPort, HIGH);
    analogWrite(motorPort2, 0);
    analogWrite(motorPort1, 0);
  }
  if (temperatureC > treshold) {
    digitalWrite(heaterPort, LOW);
    analogWrite(motorPort2, speed);
    analogWrite(motorPort1, 0);
  }
}