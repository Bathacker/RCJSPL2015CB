#include <HCSR04.h>

int cm;
HCSR04 us = HCSR04(33, 31);

void setup()
{

  Serial.begin(9600);

}

void loop()
{

  Serial.println("\n Ultrasonico: ");
  Serial.println(us.Ranging(cm));
  
}
