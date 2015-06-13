#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x3F

void setPin(int Backlight, int En, int Rw, int Rs, int D4, int D5, int D6, int D7)
{

	LiquidCrystal lcd(En, Rw, Rs, D4, D5, D6, D7);
	pinMode(Backlight, OUTPUT);

}

