#include "VNH5019.h"
#include "Arduino.h"

VNH5019::VNH5019()
{



}

void VNH5019::setM1(int M1PWM, int M1INB, int M1INA, int M1EN)
{
  
  pinMode(M1PWM, OUTPUT);
  pinMode(M1INB, OUTPUT);
  pinMode(M1INA, OUTPUT);
  pinMode(M1EN, OUTPUT);
  
}

void VNH5019::setM2(int M2PWM, int M2INB, int M2INA, int M2EN)
{

  pinMode(M2PWM, OUTPUT);
  pinMode(M2INB, OUTPUT);
  pinMode(M2INA, OUTPUT);
  pinMode(M2EN, OUTPUT);

}

void VNH5019::encenderM1()
{

  digitalWrite(M1EN, HIGH);

}

void VNH5019::apagarM1()
{

  digitalWrite(M1EN, LOW);

}

void VNH5019::encenderM2()
{

  digitalWrite(M2EN, HIGH);

}

void VNH5019::apagarM2()
{

  digitalWrite(M2EN, LOW);

}

void VNH5019::adelante1(int vel)
{

  digitalWrite(M1INB, HIGH);
  digitalWrite(M1INA, LOW);
  analogWrite(M1PWM, vel);

}

void VNH5019::atras1(int vel)
{

  digitalWrite(M1INB, LOW);
  digitalWrite(M1INA, HIGH);
  analogWrite(M1PWM, vel);

}

void VNH5019::alto1()
{

  digitalWrite(M1INB, HIGH);
  digitalWrite(M1INA, HIGH);

}

void VNH5019::adelante2(int vel)
{

  digitalWrite(M2INB, HIGH);
  digitalWrite(M2INA, LOW);
  analogWrite(M2PWM, vel);

}

void VNH5019::atras2(int vel)
{

  digitalWrite(M2INB, LOW);
  digitalWrite(M2INA, HIGH);
  analogWrite(M2PWM, vel);

}

void VNH5019::alto2()
{

  digitalWrite(M2INB, LOW);
  digitalWrite(M2INA, LOW);

}
