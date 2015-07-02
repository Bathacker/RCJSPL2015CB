#ifndef Omnidireccional_h
#define Omnidireccional_h
#include "VNH5019.h"

class Omnidireccional //En esta libreria se usan los cuatro motores
{

	public:

		//Constructor
		Omnidireccional();
		//Metodos 
		void setM1puente1(int , int , int , int );
        void setM2puente1(int , int , int , int );
        void encenderPuente1();
        void apagarPuente1();
        void setM1puente2(int , int , int , int );
        void setM2puente2(int , int , int , int );
        void encenderPuente2();
        void apagarPuente2();
		void adelante(int vel);
		void adelante();
		void atras(int vel);
		void atras();
		void izquierda(int vel);
		void izquierda();
		void derecha(int vel);
		void derecha();
		void eSDer(int vel);
		void eSDer();
		void eSIzq(int vel);
		void eSIzq();
		void eIIzq(int vel);
		void eIIzq();
		void eIDer(int vel);
		void eIDer();
		void alto();
		void Motor1adel(int vel);
		void Motor1atras(int vel);
		void Motor1alto();
		void Motor2adel(int vel);
		void Motor2atras(int vel);
		void Motor2alto();
		void Motor3adel(int vel);
		void Motor3atras(int vel);
		void Motor3alto();
		void Motor4adel(int vel);
		void Motor4atras(int vel);
		void Motor4alto();

	private:

		//Puentes H
		VNH5019 puente1;
		VNH5019 puente2;

};
#endif
