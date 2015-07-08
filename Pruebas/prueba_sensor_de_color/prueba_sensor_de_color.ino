#include <TCS3200.h>
TCS3200 sensor_color;
TCS3200 sensor_color2;
TCS3200 sensor_color3;
int verde1;
int verde2;
int verde3;


void setup()   
{  
  Serial.begin(9600);
  sensor_color.setPin(47,45,51,49,53);
  sensor_color2.setPin(37,35,41,39,43);
  sensor_color3.setPin(50,52,46,48,44);


}    
void loop() 
{  
  sensor_color3.color();
  sensor_color2.color();
  sensor_color.color();
  verde1=sensor_color3.getGreen();
  verde2=sensor_color2.getGreen();
  verde3=sensor_color.getGreen();
  Serial.print("Sensor 1:  ");
  Serial.print(verde1);
  Serial.print(" , ");
  Serial.print("Sensor 2:  ");
  Serial.print(verde2);
  Serial.print(" , ");
  Serial.print("Sensor 3:  ");
  Serial.println(verde3);
  
}  
