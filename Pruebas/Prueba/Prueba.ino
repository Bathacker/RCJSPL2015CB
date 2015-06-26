#include <Wire.h>
#include <HCSR04.h>
#include <MAG3110.h>
#include <TCS3200.h>
#include <VNH5019.h>
#include <Omnidireccional.h>
#include <HTInfraredSeeker.h>

void setup()
{
  
  MAG3110 compas();
  HCSR04 ultra(1, 2, 3);
  TCS3200 color();
  Omnidireccional omni();
  InfraredSeeker ir();
  
}

void loop()
{

  
  
}
