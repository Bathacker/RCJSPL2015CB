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

	puente1.atras1(vel); //motor1
	puente1.atras2(vel); //motor2
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
<<<<<<< Updated upstream
 void Omnidireccional::Motor4alto()
{
	puente2.apagarM2();

}
void Omnidireccional::Motor4Atras()
{
	puente2.atras2(vel);
}
void Omnidireccional::Motor4Adel()
{
	puente2.Adelante2(vel);
}
void Omnidireccional::Motor3alto()
{
	puente2.apagarM1();
}
void Omnidireccional::Motor3atras()
{
	puente2.atras1(vel);
}
void Omnidireccional::Motor3adel()
{
	puente2.adelante1(vel);
}
void Omnidireccional::Motor2alto()
{
	puente1.apagarM2();
}
void Omnidireccional::Motor2atras()
{
	puente1.atras2(vel);
}

void Omnidireccional::Motor2adel()
{
	puente1.adelante2(vel);
}
void Omnidireccional::Motor1alto()
{
	puente1.apagarM1();

}
void Omnidireccional::Motor1atras()
{
	puente1.atras1(vel);
}
void Omnidireccional::Motor1adel()
{
	puente1.adelante1(vel);
}




















=======

void Omnidireccional::izquierda(int vel)
{

	puente1.adelante1(vel);
	puente1.atras2(vel);
	puente2.adelante1(vel);
	puente2.atras2(vel);

}

void Omnidireccional::izquierda()
{

	puente1.adelante1(255);
	puente1.atras2(255);
	puente2.adelante1(255);
	puente2.atras2(255);

}

void Omnidireccional::derecha(int vel)
{

	puente1.atras1(vel);
	puente1.adelante2(vel);
	puente2.atras1(vel);
	puente2.adelante2(vel);

}

void Omnidireccional::derecha()
{

	puente1.atras1(255);
	puente1.adelante2(255);
	puente2.atras1(255);
	puente2.adelante2(255);

}

void Omnidireccional::eSDer(int vel)
{

	puente1.alto1();
	puente1.adelante2(vel);
	puente2.alto1();
	puente2.adelante2(vel);

}

void Omnidireccional::eSDer()
{

	puente1.alto1();
	puente1.adelante2(255);
	puente2.alto1();
	puente2.adelante2(255);

}

void Omnidireccional::eSIzq(int vel)
{

	puente1.aelante1(vel);
	puente1.alto2();
	puente2.aelante1(vel);
	puente2.alto2();

}

void Omnidireccional::eSIzq()
{

	puente1.aelante1(255);
	puente1.alto2();
	puente2.aelante1(255);
	puente2.alto2();

}
>>>>>>> Stashed changes
