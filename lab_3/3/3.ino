#include <Wire.h>  
#include <LiquidCrystal.h>

#define powerVoltage 5 // V power voltage
#define resistance 10000 //ohm resistance value
#define kpa2atm 0.00986923267

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int aqSensor = A3;  //output of mq135 connected to A0 pin of Arduino
int threshold = 250;      //Threshold level for Air Quality

float pkPa; // pressure in kPa
float pAtm; // pressure in Atm;

void setup()
{
  pinMode (aqSensor,INPUT); // MQ135 is connected as INPUT to arduino
  lcd.begin(16, 4);
  lcd.print("Starting");
  delay(1000);
}
 
void loop()          
{
  //getting the voltage reading from the temperature sensor
  int reading = analogRead(A0);  
  // converting that reading to voltage, for 3.3v arduino use 3.3
  float tempVoltage = reading * 5.0;
  tempVoltage /= 1024.0; 
  // print out the voltage
  lcd.setCursor(0, 0);
  lcd.print(tempVoltage); lcd.print(" V ");
  // print out the temperature
  float temperatureC = (tempVoltage - 0.5) * 100 ;//converting from 10 mv per degree wit 500 mV offset
  lcd.print(temperatureC); lcd.print(" C");  
  delay(100); 

  int luxValue = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float luxVoltage = luxValue * (5.0 / 1023.0);
  lcd.setCursor(0, 1);
  lcd.print(luxVoltage); lcd.print(" V ");
  float luxResistance = (resistance * (powerVoltage - luxVoltage))/luxVoltage; // Conversion voltage to resistance
  int lux=500/(luxResistance/1000); // Conversion resitance to lumen  
  
  lcd.print(lux); lcd.print(" lux");

  int pressureValue = analogRead(A2);
  float pressureVoltage = pressureValue * (5.0 / 1023.0);
  pkPa = ((float)pressureValue/(float)1023 + 0.095)/0.009;
  pAtm = kpa2atm*pkPa;

  /* send pressure to serial port */
  lcd.setCursor(0, 2);
  lcd.print(pressureVoltage); lcd.print(" V ");
  lcd.print(pAtm);
  lcd.print(" Atm ");

  int AQ = analogRead(aqSensor); //read MQ135 analog outputs at A3 and store it in AQ

  if (AQ > threshold)           
    {
      lcd.setCursor(0,3);       
      lcd.print("AQ Level HIGH");    
    }
  else
    {
      lcd.setCursor(0,3);
      lcd.print ("AQ Level LOW");
    }  
}