#include <Omnidireccional.h>

Omnidireccional robot = Omnidireccional();

void setup()
{

  robot.setM1puente1(10,11,12,13);
  robot.setM1puente2(6,7,8,9);
  robot.setM2puente1(3,14,4,5);
  robot.setM2puente2(2,17,16,15);
  
  robot.apagarPuente1();
  robot.apagarPuente2();
  delay(1000);
  robot.encenderPuente1();
  robot.encenderPuente2();
  delay(1000);
  robot.Motor1adel(255);
  delay(1000);
  robot.alto();
  delay(1000);
  robot.Motor2adel(255);
  delay(1000);
  robot.alto();
  delay(1000);
  robot.Motor3adel(255);
  delay(1000);
  robot.alto();
  delay(1000);
  robot.Motor4adel(255);
  delay(1000);
  robot.alto();
  
}

void loop()
{
  
  

}
