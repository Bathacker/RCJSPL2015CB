#include <Wire.h>

#include <HCSR04.h>

#include <MAG3110.h>

#include <TCS3200.h>

#include <LiquidCrystal.h>

#include <Omnidireccional.h>

#include <HTInfraredSeeker.h>

MAG3110 compas();
HCSR04 ultrasonico(1, 2);
TCS3200 color();
Omnidireccional omni();
InfraredSeeker ir();
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);
int backLight = 13;

void setup()
{

  pinMode(backLight, OUTPUT);
  analogWrite(backLight, 150);

  lcd.begin(16, 2);
  lcd.clear();
    
  lcd.setCursor(0, 0);
  
  lcd.print(ultrasonico.imprimirValores());
 
}

void loop()
{

  
  
}
