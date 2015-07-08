#include <Wire.h>

#include <HMC5883L.h>

HMC5883L compas = HMC5883L();
MagnetometerScaled compasValores;

compasValores = compas.ReadScaledAxis();

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
