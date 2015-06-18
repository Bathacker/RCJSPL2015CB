#include <HTInfraredSeeker.h>
#include <HCSR04.h>
#include <MAG3110.h>
#include <TCS3200.h>
#include <Wire.h>
#ifndef LCD_h
#define LCD_h
#include <LiquidCrystal.h>
#include "Arduino.h"

class LCD
{

	public:

		LCD();
		void setPin(int RS, int RW, int D4, int D5, int D6, int D7, int A);
		void imprimirValores();

	private:

		MAG3110 compas;
		TCS3200 coloruno;
		TCS3200 colordos;
		TCS3200 colortres;
		HCSR04 us;
		InfraredSeeker ir;	

};
#endif