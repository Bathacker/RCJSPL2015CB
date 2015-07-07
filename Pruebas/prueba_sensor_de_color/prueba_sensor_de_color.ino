#include <TCS3200.h>
TCS3200 sensor_color;



void setup()   
{  
  Serial.begin(9600);
  sensor_color.setPin(6,5,8,7,9);
  

}    
void loop() 
{  
  sensor_color.color();
  sensor_color.imprimirValores();
  
}  
