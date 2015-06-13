#include <HTInfraredSeeker.h>
#include <HCSR04.h> //ultrasonico
#include <MAG3110.h>
#include <TCS3200.h>
#include "Leervalores.h"
#include "Arduino.h"
#include "Wire.h"

Leervalores::Leervalores()
{



}

void Leervalores::LeerValoresSensores()
{
	 compas.imprimirValores();
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



}
