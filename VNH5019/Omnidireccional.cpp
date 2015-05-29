#include "Omnidireccional.h"
#include <VNH5019.h>

void Omnidireccional::Omnidireccional()
{



}

void Omnidireccional::setM1puente1(int M1PWM, int M1INB, int M1INA, int M1EN)
{

	puente1.setM1(M1PWM, M1INB, M1INA, M1EN);

}

void Omnidireccional::setM2puente1(int M2PWM, int M2INB, int M2INA, int M2EN)
{

	puente2.setM2(M2PWM, M2INB, M2INA, M2EN);

}

void Omnidireccional::setM1puente2(int M1PWM, int M1INB, int M1INA, int M1EN)
{

	puente2.setM1(M1PWM, M1INB, M1INA, M1EN);

}

void Omnidireccional::setM2puente2(int M2PWM, int M2INB, int M2INA, int M2EN)
{

	puente2.setM2(M2PWM, M2INB, M2INA, M2EN);

}

void Omnidireccional::adelante(int vel)
{

	puente1.adelante1(vel);
	puente1.adelante2(vel);
	puente2.adelante1(vel);
	puente2.adelante2(vel);

}

void Omnidireccional::adelante()
{

	puente1.adelante1(255);
	puente1.adelante2(255);
	puente2.adelante1(255);
	puente2.adelante2(255);

}

void Omnidireccional::atras(int vel)
{

	puente1.atras1(vel);
	puente1.atras2(vel);
	puente2.atras1(vel);
	puente2.atras2(vel);

}

void Omnidireccional::atras()
{

	puente1.atras1(255);
	puente1.atras2(255);
	puente2.atras1(255);
	puente2.atras2(255);

}
