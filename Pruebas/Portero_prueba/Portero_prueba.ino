#include <Wire.h>

#include <HCSR04.h>

#include <TCS3200.h>

#include <HMC5883L.h>

#include <Omnidireccional.h>

#include <HTInfraredSeeker.h>

HCSR04 ultra = HCSR04(33, 31, 11900);
TCS3200 color1 = TCS3200();
TCS3200 color2 = TCS3200();
TCS3200 color3 = TCS3200();
HMC5883L compass = HMC5883L();
Omnidireccional robot = Omnidireccional();
InfraredSeeker infra = InfraredSeeker();
InfraredInput infraInput;
float headingDegrees,heading;
int cm;
int verde1;
int verde2;
int verde3;
int error = 0;
int MilliGauss_OnThe_XAxis;
float declinationAngle = 0.0457;
int c_actual, c_inicio,brujula;

void setup()
{

  color1.setPin(47, 45, 51, 49, 53);
  color2.setPin(37, 35, 41, 39, 43);
  color3.setPin(50, 52, 46, 48, 44);
  robot.setM1puente1(10, 11, 12, 13);
  robot.setM1puente2(6, 7, 8, 9);
  robot.setM2puente1(2, 17, 16, 15);
  robot.setM2puente2(3, 14, 4, 5);

  robot.encenderPuente1();
  robot.encenderPuente2();  
  
  Wire.begin();
  Serial.begin(9600);

  error = compass.SetScale(1.3); // Set the scale of the compass.
  
  if(error != 0) // If there is an error, print it out.
    
    Serial.println(compass.GetErrorText(error));
  
  Serial.println("Setting measurement mode to continous.");
  error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
  
  if(error != 0) // If there is an error, print it out.
    
    Serial.println(compass.GetErrorText(error));
    
   c_inicio = obtenerGrados();

}

void loop()
{

  seguirPelota(infraInput.Direction, infraInput.Strength);
  
}

void seguirPelota(byte k, byte f)
{

  //Motor 1 es el parametro 1
  //Motor 2 es el parametro 2
  //Motor 3 es el parametro 4
  //Motor 4 es el parametro 3
  
  switch(k)
  {
  
    case 0:
    
       esquinaInfIzq();
    
        break;
        
     case 1:
     
       esquinaInfDer();
     
         break;
         
      case 2:
      
        esquinaInfDer();
      
          break;
          
      case 3:
      
         esquinaInfIzq();
      
          break;
          
      case 4:
      
         esquinaInfIzq();
      
          break;
          
      case 5:
      
         adelante();
      
          break;
          
      case 6:
      
        esquinaInfDer();
      
          break;
          
      case 7:
      
        esquinaInfDer();
        
          break;
          
      case 8:
      
        esquinaInfIzq();
      
          break;
          
      case 9:
      
         esquinaInfIzq();
      
          break;
    
  }
  
  alinear();
  acercarPorteria(cm);

}

void acercarPorteria(int cm)
{
  
  cm = distanciaPorteria();
  
  if(cm > 10)
  {
  
    do
    {
    
      atras();
      
    }while(cm < 6);
  
  }
  
  else
  {
  
    seguirPelota(infraInput.Direction, infraInput.Strength);
  
  }

}

int distanciaPorteria()
{

  ultra.Ranging(cm);

}

void alinear()
{

  //Alineamos el robot si esta chueco.................
  if(brujula >= 20 && brujula <= 345)
  {
      
    if(brujula >= 183)
    {
      robot.alto();
      
      do
      {
        
        robot.alinearDer(70);
        robot.Motor2alto();
        robot.Motor4alto();
      
      }while(brujula > 350);
      
    }
	   
    else
    {
       robot.alto();
       
       do
       {          
         
         robot.alinearIzq(70);
         robot.Motor1alto();
         robot.Motor3alto();
       
       }while(brujula < 10);	 
    
    }
    
  }
         //Si esta acomodado entonces.................................
  else
  {
    
    seguirPelota(infraInput.Direction, infraInput.Strength);
    
  }

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

void adelante()
{
  
  robot.Aadelante(100, 255,255 , 120);

}

void esquinaSupIzq()
{

  robot.Aadelante(0, 255,255 , 0);

}

void esquinaSupDer()
{

  robot.Aadelante(255,0,0,255);

}

void esquinaInfIzq()
{

  robot.Aatras(255,0,0,255);

}

void esquinaInfDer()
{

  robot.Aatras(0,255,255,0);

}

void derecha()
{

  robot.derecha(150); 

}

void izquierda()
{

  robot.izquierda(150);

}

void alinearDer()
{

  robot.alinearDer(65);

}

void alinearIzq()
{

  robot.alinearIzq(65);

}

void atras()
{

  robot.Aatras(200,200,200,200);

}

