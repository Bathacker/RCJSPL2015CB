#include <HTInfraredSeeker.h>
#include <HCSR04.h>
#include <MAG3110.h>
#include <TCS3200.h>
#ifndef ImprimirValores_h
#define ImprimirValores_h
#include "Arduino.h"

class ImprimirValores
{
	public:
		
		ImprimirValores();
		void imprimirValoresSensores();

	private:
		
		MAG3110 compas;
		TCS3200 coloruno;
		TCS3200 colordos;
		TCS3200 colortres;
		HCSR04 US;
		InfraredSeeker IR;

};
#endif