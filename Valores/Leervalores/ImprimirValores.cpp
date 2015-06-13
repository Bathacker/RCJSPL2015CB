#include <HTInfraredSeeker.h>
#include <HCSR04.h> //ultrasonico
#include <MAG3110.h>
#include <TCS3200.h>
#include <Wire.h>
#include "imprimirValores.h"
#include "Arduino.h"

ImprimirValores::ImprimirValores()
{

	
	
}

void ImprimirValores::ImprimirValoresSensores()
{
	
	coloruno.getGreen();
	coloruno.getBlue();
	coloruno.getRed();
	colordos.getGreen();
	colordos.getBlue();
	colordos.getRed();
	colortres.getGreen();
	colortres.getBlue();
	colortres.getRed();
	US.Ranging(cm); //ultrasonico
	IR.ReadValues(); //infrarojo
	compas.leerx();

	Serial.println(compas.imprimirValores());
	Serial.println(coloruno.imprimirValores());
	Serial.println(colordos.imprimirValores());
	Serial.println(colortres.imprimirValores());
	Serial.println(US.imprimirValores());
	Serial.println(IR.imprimirValores());

}