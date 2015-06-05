#include "arduino.h"
#include "TCS3200.h"

TCS3200::TCS3200() //Constructor
{
	
  //:)

} 

void TCS3200::color()
{

	digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  //count OUT, pRed, RED  
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
  //count OUT, pBLUE, BLUE  
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  //count OUT, pGreen, GREEN  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  

}

void TCS3200::setPin(int _s0, int _s1, int _s2, int _s3 ,int _out) //Declaramos los pines del sensor
{

	s0=_s0;
	s1=_s1;
	s2=_s2;
	s3=_s3;
	out=_out;

}

int TCS3200::getGreen() //Obtenemos el color verde
{

  return green;  

}

int TCS3200::getBlue() //Obtenemos el color azul
{

  return blue;

}

int TCS3200::getRed() //Obtenemos el color rojo
{

  return red;

}
