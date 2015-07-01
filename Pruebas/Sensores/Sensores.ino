#include <Wire.h>

#include <HCSR04.h>

#include <MAG3110.h>

#include <TCS3200.h>

#include <Omnidireccional.h>

#include <HTInfraredSeeker.h>

HCSR04 us(9, 8);
TCS3200 color();
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
  Serial.println(us.Ranging(cm));
  compasValores;
  seekerInput;
  
}
