#include <Omnidireccional.h>

Omnidireccional robot = Omnidireccional();

void setup()
{

  robot.setM1puente1(10,11,12,13);
  robot.setM1puente2(6,7,8,9);
  robot.setM2puente1(2,17,16,15);
  robot.setM2puente2(3,14,4,5);
  
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(1000);
  robot.encenderPuente1();
  robot.encenderPuente2();
  delay(1000);
  atras();
// robot.eIDer(100,255,255,110);
 delay(800);
  robot.alto();
 

  
}

void loop()
{
  
  

}

//Motor 1 es el parametro 1
//Motor 2 es el parametro 2
//Motor 3 es el parametro 4
//Motor 4 es el parametro 3
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


