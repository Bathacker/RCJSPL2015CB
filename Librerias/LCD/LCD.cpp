#include "LCD.h"
#include "arduino.h"

LCD::LCD(int TP, int EP)
{

	us(, 2);

}

void setPin(int RS, int RW, int E, int D4, int D5, int D6, int D7, int backLight)
{

	LiquidCrystal lcd(RS, RW, E, D4, D5, D6, D7);
	pinMode(backLight, OUTPUT);
	anologWrite(backLight, 150);

}

void imprimirValores(MAG3110 compas, TCS3200 coloruno, TCS3200 colordos, TCS3200 colortres, HCSR04 us, InfraredSeeker ir, LiquidCrystal lcd)
{

	lcd.begin(16, 2);
	lcd.print(compas.leerX());
	lcd.print(coloruno.imprimirValores());
	lcd.print(colordos.imprimirValores());
	lcd.print(colortres.imprimirValores());
	lcd.print(us.imprimirValores());
	lcd.print(ir.ReadAC());

}