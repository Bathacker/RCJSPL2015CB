#include <Omnidireccional.h>

Omnidireccional robot = Omnidireccional();

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

  robot.adelante(200);
  delay(1000);
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(100);
  robot.atras(200);
  delay(1000);
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(100);
  robot.derecha(200);
  delay(1000);
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(100);
  robot.izquierda(200);
  delay(1000);
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(100);
  robot.eSDer(200);
  delay(1000);
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(100);
  robot.eSIzq(200);
  delay(1000);
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(100);
  robot.eIDer(200);
  delay(1000);
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(100);
  robot.eIIzq(200);
  delay(1000);
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(100);

}
