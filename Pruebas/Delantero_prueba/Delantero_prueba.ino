#include <Wire.h>

#include <TCS3200.h>

#include <HMC5883L.h>

#include <Omnidireccional.h>

#include <HTInfraredSeeker.h>

TCS3200 color1 = TCS3200();
TCS3200 color2 = TCS3200();
TCS3200 color3 = TCS3200();
HMC5883L compass = HMC5883L();
Omnidireccional robot = Omnidireccional();
InfraredSeeker infra = InfraredSeeker();
InfraredInput infraInput;

void setup()
{

  color1.setPin(47, 45, 51, 49, 53);
  color2.setPin(37, 35, 41, 39, 43);
  color3.setPin(50, 52, 46, 48, 44);
  robot.setM1puente1(10, 11, 12, 13);
  robot.setM1puente2(6, 7, 8, 9);
  robot.setM2puente1(2, 17, 16, 15);
  robot.setM2puente2(3, 14, 4, 5);

  robot.encenderPuente1();
  robot.encenderPuente2();  

  seguirPelota();

}

void loop()
{

  
  
}

void seguirPelota(byte k, byte f)
{

  switch(k)
  {
  
    case 0:
    
       
    
        break;
    
  }

}

void adelante()
{
  
  robot.Aadelante(100, 255,255 , 120);

}

void esquinaSupIzq()
{

  robot.Aadelante(0, 255,255 , 0);

}

void esquinaSupDer()
{

  robot.Aadelante(255,0,0,255);

}

void esquinaInfIzq()
{

  robot.Aatras(255,0,0,255);

}

void esquinaInfDer()
{

  robot.Aatras(0,255,255,0);

}

void derecha()
{

  robot.derecha(150); 

}

void izquierda()
{

  robot.izquierda(150);

}

void alinearDer()
{

  robot.alinearDer(65);

}

void alinearIzq()
{

  robot.alinearIzq(65);

}

void atras()
{

  robot.Aatras(200,200,200,200);

}

