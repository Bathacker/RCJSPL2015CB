#include <Omnidireccional.h>
 
Omnidireccional omni = Omnidireccional();

void setup()
{
  
  omni.setM1puente1(10,11,12,13);
  omni.setM1puente2(6,7,8,9);
  omni.setM2puente1(3,14,4,5);
  omni.setM2puente2(2,17,16,15);
  omni.encenderPuente1();
  omni.encenderPuente2();
  omni.adelante();
  delay(3000);
  
}

void loop() 
{

  
  
}
