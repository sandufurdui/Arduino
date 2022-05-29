#include <Wire.h>
#include "DHT.h"
#include <LiquidCrystal.h>
#include <math.h>

#define DHTTYPE DHT11
#define sensorPin A0
DHT dht(sensorPin, DHTTYPE);
const int rs = 13,
  en = 12,
  d4 = 11,
  d5 = 10,
  d6 = 9,
  d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int motorPort1 = A4;
const int motorPort2 = A5;
const int LDR_port = A1;
const int GAS_port = A2;
const int led_port = 6;

const int heaterPort = 7;
int tempTreshold = 27;
int humidTreshold = 75;
int lightTreshold = 900;
int co2Treshold = 300;
int speed = 250;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(led_port, OUTPUT);
  lcd.begin(16, 4);
  lcd.print("Starting...");
  delay(1000);
  dht.begin();
  lcd.setCursor(0, 0);lcd.print("T(C)|H(%) |L(%)|C(%) ");
  lcd.setCursor(4, 1);lcd.print("|");
  lcd.setCursor(10, 1);lcd.print("|");
  lcd.setCursor(15, 1);lcd.print("|");
}

void loop() {
  int humid = dht.readHumidity();
  int temp = dht.readTemperature();
  int LDR = analogRead(LDR_port); 
  int GAS1 = analogRead(GAS_port); 

  int GAS = GAS1 / 100;
  GAS = ceil( GAS );
  GAS = GAS * 10;

  lcd.setCursor(1, 1);lcd.print(temp);
  lcd.setCursor(6, 1);lcd.print(humid);
  lcd.setCursor(12, 1);lcd.print(LDR / 10);
  lcd.setCursor(17, 1);lcd.print(GAS);
 
  if (temp < tempTreshold) {
    digitalWrite(heaterPort, HIGH);
  }
  if (temp > tempTreshold) {
    digitalWrite(heaterPort, LOW);
  }
  if (humid < humidTreshold or GAS1 < co2Treshold or temp < tempTreshold) {
    analogWrite(motorPort2, 0);
    analogWrite(motorPort1, 0);
  }
  if (humid > humidTreshold or GAS1 > co2Treshold or temp > tempTreshold){
    analogWrite(motorPort2, speed);
    analogWrite(motorPort1, 0);
  }
  if (LDR > 900) {
    digitalWrite(led_port, LOW);
  }
  if (LDR < 900) {
    digitalWrite(led_port, HIGH);
  }   
}
