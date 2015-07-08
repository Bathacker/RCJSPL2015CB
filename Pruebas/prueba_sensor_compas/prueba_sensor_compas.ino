#include <Wire.h>

#include <MAG3110.h>

MAG3110 sensor_compas;
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
 x=sensor_compas.leerX();
 Serial.println(x);

}
