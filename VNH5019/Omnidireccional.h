#ifndef Omnidireccional_h
#define Omnidireccional_h
#include <VNH5019.h>

class Ominidireccional
{

	public:

		Ominidireccional();
		adelante(int vel);
		adelante();
		atras(int vel);
		atras();
		izquierda(int vel);
		izquierda();
		derecha(int vel);
		derecha();
		eSDer(int vel);
		eSDer();
		eSIzq(int vel);
		eSIzq();
		eIIzq(int vel);
		eIIzq();
		eIDer(int vel);
		eIDer();
		alto();
		Motor1adel(int vel);
		Motor1atras(int vel);
		Motor1alto();
		Motor2adel(int vel);
		Motor2atras(int vel);
		Motor2alto();
		Motor3adel(int vel);
		Motor3atras(int vel);
		Motor3alto();
		Motor4adel(int vel);
		Motor4atras(int vel);
		Motor4alto();

	private:

		VNH5019 diego, yoalli;

};
#endif