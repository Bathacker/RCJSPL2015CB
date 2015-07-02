//Pines
//motor1 m1en-13 m1enA-12 m1enB-11 m1pwm-10
//motor2 m1en-9 m1enA-8 m1enB-7 m1pwm-6
//motor3 m1en-5 m1enA-4 m1enB-14 m1pwm-3
//motor4 m1en-15 m1enA-16 m1enB-17 m1pwm-2

//ultrasonico echo-31 trig-33
//color1 53 51 49 47 45
//color2 43 41 39 37 35
//color3 44 46 48 50 52 


//Librerias
#include <Wire.h>
#include <MAG3110.h>
#include <VNH5019.h>
#include <Omnidireccional.h>
#include <HTInfraredSeeker.h>

//robot pertenece a Omnidireccional :. robot puede acceder a los metodos de Omnidireccional
Omnidireccional robot= Omnidireccional();
//Instanceas 
//InfraredSeeker seeker=InfraredSeeker();
//InfraredInput seekerInput;
//int infra;
void setup() {
  
 //
  robot.setM1puente1(10,11,12,13);
  robot.setM1puente2(6,7,8,9);
  robot.setM2puente1(3,14,4,5);
  robot.setM2puente2(2,17,16,15);
  robot.encenderPuente1();
  robot.encenderPuente2();
  robot.adelante();
  delay(3000);

}

void loop() {
  //seekerInput=seeker.ReadAC();
  //followball(seekerInput.Direction, seekerInput.Strength);
  //delay(5);     
}

/**
 void followball(byte a, byte b);
    {
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
  }*/ 
