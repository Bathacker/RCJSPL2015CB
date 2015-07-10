#include <HMC5883L.h>

#include <HCSR04.h>

#include <TCS3200.h>

#include <HTInfraredSeeker.h>

#include <Wire.h>

int cm;
HCSR04 us = HCSR04(33, 31, 11900);
HMC5883L compass = HMC5883L();
TCS3200 sensor_color;
TCS3200 sensor_color2;
TCS3200 sensor_color3;
int verde1;
int verde2;
int verde3;
InfraredSeeker seeker=InfraredSeeker();
InfraredInput seekerInput;
float headingDegrees,heading;
int error=0;
int MilliGauss_OnThe_XAxis;
float declinationAngle = 0.0457;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  sensor_color.setPin(47,45,51,49,53);
  sensor_color2.setPin(37,35,41,39,43);
  sensor_color3.setPin(50,52,46,48,44);

  error = compass.SetScale(1.3); // Set the scale of the compass.
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
  
    Serial.println("Setting measurement mode to continous.");
  error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
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
  alinearse();
  //followball(seekerInput.Direction, seekerInput.Strength);
   }
void followball(byte k,byte f)
{

}

void alinearse()
{
  MagnetometerRaw raw = compass.ReadRawAxis();
   MagnetometerScaled scaled = compass.ReadScaledAxis();
  
  // Values are accessed like so:
  MilliGauss_OnThe_XAxis = scaled.XAxis;// (or YAxis, or ZAxis)

  // Calculate heading when the magnetometer is level, then correct for signs of axis.
  heading = atan2(scaled.YAxis, scaled.XAxis);
  

  heading += declinationAngle;
  
  // Correct for when signs are reversed.
  if(heading < 0)
    heading += 2*PI;
  // Check for wrap due to addition of declination.
  if(heading > 2*PI)
    heading -= 2*PI;
  // Convert radians to degrees for readability.
  headingDegrees = heading * 180/M_PI; 
 
   Serial.println(" Grados   \t");
   Serial.print(headingDegrees);

}


  
