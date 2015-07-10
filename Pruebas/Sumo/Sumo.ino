#include <TCS3200.h>

#include <Omnidireccional.h>

Omnidireccional robot = Omnidireccional();
TCS3200 color1 = TCS3200();
TCS3200 color2 = TCS3200();
TCS3200 color3 = TCS3200();

void setup()
{

  robot.setM1puente1(10,11,12,13);
  robot.setM1puente2(6,7,8,9);
  robot.setM2puente1(2,17,16,15);
  robot.setM2puente2(3,14,4,5);
  
  robot.encenderPuente1();
  robot.encenderPuente2();

}

void loop()
{
  
  robot.derecha();
  
  if(color1 == 400)
  {
  
    
  
  }
  
}
