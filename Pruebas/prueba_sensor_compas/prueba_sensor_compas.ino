#include <Wire.h>

#include <MAG3110.h>
MAG3110 sensor_compas = MAG3110();
int x;
int y;
int brujulai;


void setup()
{

  Wire.begin();
  Serial.begin(9600);
  sensor_compas.iniciar();

}

void loop()
{

 sensor_compas.imprimirValores();

}
