#include "Movimientos.h"
#include "Arduino.h"

void Movimientos::Movimientos()
{



}

void Movimientos::setM1(int M1PWM, int M1INB, int M1INA, int M1EN)
{
  
  M1PWM = this M1PWM;
  M1INB = this M1INB;
  M1INA = this M1INA;
  M1EN = this M1EN;  
  pinMode(M1PWM, OUTPUT);
  pinMode(M1INB, OUTPUT);
  pinMode(M1INA, OUTPUT);
  pinMode(M1EN, OUTPUT);
  
}

void Movimientos::setM2(int M2PWM, int M2INB, int M2INB, int M2INA, int M2EN)
{

  M2PWM = this M2PWM;
  M2INB = this M2INB;
  M2INA = this M2INA;
  M2EN = this M2EN;
  pinMode(M2PWM, OUTPUT);
  pinMode(M2INB, OUTPUT);
  pinMode(M2INA, OUTPUT);
  pinMode(M2EN, OUTPUT);

}

void Movimientos::encenderM1()
{

  digitalWrite(M1EN, HIGH);

}

void Movimientos::apagarM1()
{

  digitalWrite(M1EN, LOW);

}

void Movimientos::encederM2()
{

  digitalWrite(M2EN, HIGH);

}

void Movimientos::apagarM2()
{

  digitalWrite(M2EN, LOW);

}

void Movimientos::adelante1(int vel)
{

  digitalWrite(M1INB, HIGH);
  digitalWrite(M1INA, LOW);
  analogWrite(M1PWM, vel);

}

void Movimientos::atras1(int vel)
{

  digitalWrite(M1INB, LOW);
  digitalWrite(M1INA, HIGH);
  analogWrite(M1PWM, vel);

}

void Movimientos::alto1()
{

  digitalWrite(M1INB, HIGH);
  digitalWrite(M1INA, HIGH);

}

void Movimientos::adelante2(int vel)
{

  digitalWrite(M2INB, HIGH);
  digitalWrite(M2INA, LOW);
  analogWrite(M2PWM, vel);

}

void Movimientos::atras2(int vel)
{

  digitalWrite(M2INB, LOW);
  digitalWrite(M2INA, HIGH);
  analogWrite(M2PWM, vel);

}

void Movimientos::alto2()
{

  digitalWrite(M2INB, LOW);
  digitalWrite(M2INA, LOW);

}

void Movimientos::adelante(int vel)
{

  adelante1(vel);
  adelante2(vel);

}

void Movimientos::atras(int vel)
{

  atras1(vel);
  atras2(vel);

}

void Movimientos::alto()
{

  alto1();
  alto2();

}
