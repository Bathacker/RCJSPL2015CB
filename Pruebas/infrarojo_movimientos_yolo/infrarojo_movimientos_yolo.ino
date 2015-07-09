#include <Omnidireccional.h>
#include <VNH5019.h>
#include <Wire.h>
#include <HTInfraredSeeker.h>
InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;
Omnidireccional robot = Omnidireccional();
VNH5019 puente1 = VNH5019();
VNH5019 puente2 = VNH5019();
int v = 150;
int infra;

void setup() {
 Wire.begin();
  Serial.begin(9600);
  robot.setM1puente1(10,11,12,13);
  robot.setM1puente2(6,7,8,9);
  robot.setM2puente1(3,14,4,5);
  robot.setM2puente2(2,17,16,15);
  robot.encenderPuente1();
  robot.encenderPuente2();
}

void loop() 
{
  seekerInput=seeker.ReadAC();
  followball(seekerInput.Direction, seekerInput.Strength);
 }
void followball(byte k,byte f)
{
  switch(infra);
  {
    case 0:
    robot.atras(v);
    break;
    case 1:
    robot.eIDer(v);
    break:;
    case 2:
    robot.eIIzq(v);
    break;
    case 3:
    robot.izquierda(v);
    break;
    case 4:
    eSIzq(v);
    break;
    case 5:
    robot.adelante(v);
    break;
    case 6:
    robot.eSDer(v);
    break;
    case 7:
    robot.derecha(v);
    break;
    case 8:
    robot.eIDer(v);
    break;
    case :
    robot.eIIzq(v);



    
    
    
  }
  Serial.print(k);
  Serial.print(" , ");
  Serial.println(f);
}

