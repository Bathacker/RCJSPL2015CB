//Librerias
#include <Wire.h>
#include <MAG3110.h>
#include <Omnidireccional.h>
//robot pertenece a Omnidireccional :. robot puede acceder a los metodos de Omnidireccional
Omnidireccional robot= Omnidireccional();
int infra;
void setup() {

 //
  robot.setM1puente1(8,6,7,9);
  robot.setM1puente2(5,4,3,1);
  robot.setM2puente1(12,15,2,10);
  robot.setM2puente2(13,17,20,22);
  robot.adelante(255);
 delay(3000);

}

void loop() {
 
  delay(5);
  switch(infra){
   case 0:
   robot.atras();
    break;
    case 1:
    robot.eIIzq();
    break;
    case 2:
    robot.eIIzq();
    break;
    case 3:
     robot.izquierda();
    break;
     case 4:
     robot.eSIzq();
    break;
    case 5:
    robot.adelante();
    break;
    case 6:
    robot.eSDer();
    break;
    case 7:
    robot.derecha();
    break;
    case 8:
    robot.eIDer();
    case 9:
    robot.eIDer();
    break;
    
     
  }
   
}
