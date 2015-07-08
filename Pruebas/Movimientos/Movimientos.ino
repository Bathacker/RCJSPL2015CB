#include <Omnidireccional.h>
#include <VNH5019.h>

Omnidireccional robot = Omnidireccional();
VNH5019 puente1 = VNH5019();
VNH5019 puente2 = VNH5019();
int v = 150;
int e = 2000;

void setup()
{

  robot.setM1puente1(10,11,12,13);
  robot.setM1puente2(6,7,8,9);
  robot.setM2puente1(3,14,4,5);
  robot.setM2puente2(2,17,16,15);
  robot.encenderPuente1();
  robot.encenderPuente2();
 
}

void loop()
{

  robot.adelante(v);   //El robot va hacia adelante durante 2 segundos y se detiene
  delay(e);
  robot.alto();
  delay(e);  
  robot.atras(v);      //El robot va hacia atras durante 2 segundos y se detiene
  delay(e);
  robot.alto();
  delay(e);
  robot.derecha(v);    //El robot va hacia la derecha durante 2 segundos y se detiene
  delay(e);
  robot.alto();
  delay(e);
  robot.izquierda(v);  //El robot va hacia la izquierda durante 2 segundos y se detiene
  delay(e);
  robot.alto();
  delay(e);
  robot.eSDer(v);      //El robot va hacia la esquina superior derecha durante 2 segundos y se detiene
  delay(e);
  robot.alto();
  delay(e);
  robot.eSIzq(v);      //El robot va hacia la esquina superior izquierda durante 2 segundos y se detiene
  delay(e);
  robot.alto();
  delay(e);
  robot.eIDer(v);      //El robot va hacia la esquina inferior derecha durante 2 segundos y se detiene
  delay(e);
  robot.alto();
  delay(e);
  robot.eIIzq(v);      //El robot va hacia la esquina inferior izquierda durante 2 segundos y se detiene durante otros 2 segundos
  delay(e);
  robot.alto();
  delay(e);
  
}
