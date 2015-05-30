#include "arduino.h"
#include "Color.h"
Color::Color()
{
	//:)
} 
void Color::Color()
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
void Color::setPin(int _s0, int _s1, int _s2, int _s3 ,int _out)
{
	s0=_s0;
	s1=_s1;
	s2=_s2;
	s3=_s3;
	out=_out;
}
