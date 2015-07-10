#include <Wire.h>

#include <HMC5883L.h>

HMC5883L compass = HMC5883L();
float headingDegrees,heading;
int error=0;
int MilliGauss_OnThe_XAxis; 
  // Once you have your heading, you must then add your 'Declination Angle', which is the 'Error' of the magnetic field in your location.
  // Find yours here: http://www.magnetic-declination.com/
  // Mine is: 2� 37' W, which is 2.617 Degrees, or (which we need) 0.0456752665 radians, I will use 0.0457
  // If you cannot find your Declination, comment out these two lines, your compass will be slightly off.
  float declinationAngle = 0.0457;
  
void setup()
{
  
  Wire.begin();
  Serial.begin(9600);

  error = compass.SetScale(1.3); // Set the scale of the compass.
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
  
    Serial.println("Setting measurement mode to continous.");
  error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  if(error != 0) // If there is an error, print it out.
    Serial.println(compass.GetErrorText(error));
  
}

void loop()
{

  alinearse();  
  
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
