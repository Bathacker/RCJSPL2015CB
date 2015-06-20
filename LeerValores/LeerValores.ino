#include <Wire.h>

#include <HCSR04.h>

#include <TCS3200.h>

#include <MAG3110.h>

#include <HTInfraredSeeker.h>

HCSR04 us(1, 2);
TCS3200 color;
MAG3110 compas;
InfraredSeeker ir;

void setup()
{

  Serial.begin(9600);
  

}

void loop()
{
  +

  Serial.println("Color: ");
  color.imprimirValores();
  Serial.println("Compas: ");
  Serial.println(compas.leerZ());
  Serial.println("Ultrasonico: ");
  us.imprimirValores();
  
}
