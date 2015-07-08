#include <Wire.h>
#include <HTInfraredSeeker.h>
InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;
void setup() {
   Wire.begin();
  Serial.begin(9600);

 
}

void loop() 
{
  seekerInput=seeker.ReadAC();
  followball(seekerInput.Direction, seekerInput.Strength);
 }
void followball(byte k,byte f)
{
  Serial.print(k);
  Serial.print(" , ");
  Serial.println(f);
}

