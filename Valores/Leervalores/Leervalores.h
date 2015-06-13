#include <HTInfraredSeeker.h>
#include <HCSR04.h>
#include <MAG3110.h>
#include <TCS3200.h>
#ifndef Leervalores_h
#define Leervalores_h
#include "Arduino.h"

class Leervalores
{
	
	public:
		
		Leervalores();
		void LeerValoresSensores();

	private:
		
		MAG3110 compas;
		TCS3200 coloruno;
		TCS3200 colordos;
		TCS3200 colortres;
		HCSR04 us;
		InfraredSeeker ir;

};
#endif