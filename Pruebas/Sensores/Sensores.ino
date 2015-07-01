#include <Wire.h>

#include <HCSR04.h>

#include <MAG3110.h>

#include <TCS3200.h>

#include <Omnidireccional.h>

#include <HTInfraredSeeker.h>

HCSR04 us(9, 8);
TCS3200 color = TCS3200();
Omnidireccional omni();
InfraredSeeker seeker = InfraredSeeker();
InfraredInput seekerInput;
MAG3110 compas = MAG3110();
Valores compasValores;
int cm;

void setup()
{
  
  Serial.begin(9600);
  
}

void loop()
{
  
  seekerInput = seeker.ReadAC();
  compasValores = compas.imprimirValores();
  Serial.println("\n Ultrasonico: ");
  Serial.println(us.Ranging(cm));
  Serial.println("\n Compas: ");
  compasValores;
  Serial.println("\n Infrarrojo: ");
  seekerInput;
  Serial.println("\n Color: ");
  color.imprimirValores();
  Serial.println("\n ");
  
}
