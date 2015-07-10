#include <Wire.h>

#include <HMC5883L.h>

#include <Omnidireccional.h>

HMC5883L compass = HMC5883L();
Omnidireccional robot = Omnidireccional();

float headingDegrees,heading;
int error = 0;
int MilliGauss_OnThe_XAxis;
float declinationAngle = 0.0457;
int c_actual, c_inicio,brujula;

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
    
    c_inicio=obtenerGrados();
  
}

void loop()
{
  
  c_actual=obtenerGrados();
  brujula=arreglarCompas();
  Serial.println(" Grados   \t");
  Serial.print(brujula);

}

int obtenerGrados()
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
   
   return headingDegrees;

}

int arreglarCompas()
{
    
    int b;
    b = c_actual - c_inicio;
    
    if(b < 0)
    {
    
      b+=360;
  
    }
    
    return b;
}

