#include <HCSR04.h>

#include <TCS3200.h>

#include <HTInfraredSeeker.h>

#include <Wire.h>

int cm;
HCSR04 us = HCSR04(33, 31, 11900);
TCS3200 sensor_color;
TCS3200 sensor_color2;
TCS3200 sensor_color3;
int verde1;
int verde2;
int verde3;
InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  sensor_color.setPin(47,45,51,49,53);
  sensor_color2.setPin(37,35,41,39,43);
  sensor_color3.setPin(50,52,46,48,44);
}

void loop() {
  sensor_color3.color();
  sensor_color2.color();
  sensor_color.color();
  verde1=sensor_color3.getGreen();
  verde2=sensor_color2.getGreen();
  verde3=sensor_color.getGreen();
  seekerInput=seeker.ReadAC();

  Serial.print("Infra: ");
  Serial.print(seekerInput.Direction);
  Serial.print(" , ");
  Serial.print(" Inten: ");
  Serial.print(seekerInput.Strength);
  Serial.print(" Ultra: ");
  Serial.print(us.Ranging(cm)); 
  Serial.print(" , ");
  Serial.print(" verde1: ");
  Serial.print(verde1);
  Serial.print(" , ");
  Serial.print(" verde2 ");
  Serial.print(verde2);
  Serial.print(" , ");
  Serial.print(" verde3: ");
  Serial.println(verde3);
  //followball(seekerInput.Direction, seekerInput.Strength);
   }
void followball(byte k,byte f)
{

}


  
