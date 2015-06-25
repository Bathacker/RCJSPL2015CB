#include "LCD.h"
#include "Arduino.h"

LCD::LCD()
{

	us(4, 6);

}

void setPin(int RS, int RW, int D4, int D5, int D6, int D7, int A)
{

	LiquidCrystal lcd(RS, RW, E, D4, D5, D6, D7);
	pinMode(A, OUTPUT);
	anologWrite(A, 150);

}

void imprimirValores()
{

	lcd.begin(16, 2);
	lcd.print(compas.leerX());
	lcd.print(coloruno.imprimirValores();
	lcd.print(colordos.imprimirValores());
	lcd.print(colortres.imprimirValores());
	lcd.print(us.imprimirValores());
	lcd.print(ir.ReadAC());

}