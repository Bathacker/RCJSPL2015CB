
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
  robot.alinearDer(65);
  delay(1000);
  robot.alinearIzq(65);
  delay(1000);
  robot.derecha(150);
  delay(1000);
  robot.izquierda(150);
  delay(1000);
  robot.alto();
  
}

void loop()
{
  
    

}
