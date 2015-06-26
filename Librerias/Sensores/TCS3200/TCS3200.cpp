#include "arduino.h"
#include "TCS3200.h"

TCS3200::TCS3200() //Constructor
{
	
  //:)

} 

void TCS3200::color() //Se determinan los colores
{

	digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  //count OUT, pRed, RED
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW  : HIGH);
  digitalWrite(s3, HIGH);
  //count OUT, pBLUE, BLUE
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  //count OUT, pGreen, GREEN
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

}

void TCS3200::setPin(int _s0, int _s1, int _s2, int _s3 ,int _out) //Declaramos los pines del sensor
{

	//Declaramos que son iguales que las variables del.h
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

void TCS3200::imprimirValores() //Se usa para imprimir el color que detecta a la pantalla de la computadora
{

  Serial.println(getGreen());
  Serial.println(getBlue());
  Serial.println(getRed());

}
