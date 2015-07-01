#include <Wire.h>
#include "MAG3110.h"
#include "Arduino.h"

MAG3110::MAG3110()
{

  
  
}

void MAG3110::iniciar() //Iniciamos la comunicación con el sensor
{

  Wire.beginTransmission(MAG_ADDR);
  Wire.write(0x11);
  Wire.write(0x80);
  Wire.endTransmission();

}

Valores MAG3110::imprimirValores() //Imprimimos los valores de x y z
{

  Valores res;
  res.x = leerX();
  res.y = leerY();
  res.z = leerZ();
  Serial.print("x =");
  Serial.print(leerX()); 
  Serial.print(",");  
  Serial.print("y =");    
  Serial.print(leerY());
  Serial.print(",");       
  Serial.print("z =");    
  Serial.println(leerZ()); 
  return res;    

}

int MAG3110::leerX() //Leemos los datos que nos envia el eje x del sensor
{

  int xl, xh; // xl numero entero ,xh numero decimal
  
  Wire.beginTransmission(MAG_ADDR);
  Wire.write(0x01);
  Wire.endTransmission();
 
  delayMicroseconds(2);
  
  Wire.requestFrom(MAG_ADDR, 1);
  while(Wire.available())
  { 

    xh = Wire.read(); //segundo lee numero decimal

  }
  
  delayMicroseconds(2);
  
  Wire.beginTransmission(MAG_ADDR);
  Wire.write(0x02);
  Wire.endTransmission();
 
  delayMicroseconds(2);
  
  Wire.requestFrom(MAG_ADDR, 1);
  while(Wire.available()) 
  { 

    xl = Wire.read();//primero lee numero entero

  }
  
  int xout = (xl|(xh << 8)); // junta dos valores xl y xh a un solo numero
  return xout; //regresar coordenadas

}

int MAG3110::leerY() //Leemos los datos que nos envia el eje Y del sensor
{

  int yl, yh; //uno es numero entero yl y numero decimal yh
  
  Wire.beginTransmission(MAG_ADDR); 
  Wire.write(0x03);
  Wire.endTransmission();
 
  delayMicroseconds(2);
  
  Wire.requestFrom(MAG_ADDR, 1);
  while(Wire.available())
  { 

    yh = Wire.read(); //Segundo lee numero decimal

  }
  
  delayMicroseconds(2);
  
  Wire.beginTransmission(MAG_ADDR);
  Wire.write(0x04);
  Wire.endTransmission();
 
  delayMicroseconds(2);
  
  Wire.requestFrom(MAG_ADDR, 1);
  while(Wire.available())
  { 

    yl = Wire.read(); //Primero lee numero entero

  }
  
  int yout = (yl|(yh << 8)); // junta dos valores yl , yh a uno solo
  return yout; //regresa coordenadas

}

int MAG3110::leerZ() //Leemos los datos que nos envia el eje z del sensor
{

  int zl, zh; //zl numero enter , zh numero decimal
  
  Wire.beginTransmission(MAG_ADDR);
  Wire.write(0x05);
  Wire.endTransmission();
 
  delayMicroseconds(2);
  
  Wire.requestFrom(MAG_ADDR, 1);
  while(Wire.available())
  { 

    zh = Wire.read(); //Segundo lee numero decimal

  }
  
  delayMicroseconds(2);
  
  Wire.beginTransmission(MAG_ADDR);
  Wire.write(0x06);
  Wire.endTransmission();
 
  delayMicroseconds(2);
  
  Wire.requestFrom(MAG_ADDR, 1);
  while(Wire.available())
  { 

    zl = Wire.read(); // primero lee numero entero

  }
  
  int zout = (zl|(zh << 8)); // junta dos valores zl y zh a uno solo
  return zout; //regresa coordenadas

}
