//Intelirobot escuela de robotica
// intelirobot.com.mx
//....................... programa hecho por yoalli y diego 

//Motor 1 en puente 1 pines: 10,11,12,13
//Motor 2 en puente 1 pines: 2,17,16,15
//Motor 1 en puente 2 pines: 6,7,8,9
//Motor 2 en puente 2 pines: 3,14,4,5

//Sensor de color: 47,45,51,49,53
//Sensor de color 2: 37,35,41,39,43
//Sensor de color 3: 50,52,46,48,44

//Sensor ultrasonico pines: 33, 31, 11900

//sensor compas e infrarrojo por I2C

//Librerias necesarias..............
#include <Omnidireccional.h>
#include <TCS3200.h>
#include <HMC5883L.h>
#include <HCSR04.h>
#include <HTInfraredSeeker.h>
#include <Wire.h>
//.............................

//Instanceas de librerias...................................................

HMC5883L compass = HMC5883L(); //Sensor de compas
HCSR04 us= HCSR04(33, 31, 11900); //Pines sensor ultrasonico //Sensor ultrasonico
TCS3200 sensor_color;//sensor de color1
TCS3200 sensor_color2;//sensor de color2
TCS3200 sensor_color3;//sensor de color3
Omnidireccional robot = Omnidireccional();//Para motores con ambos puentes H
InfraredSeeker seeker=InfraredSeeker();//Sensor infrarrrojo
InfraredInput seekerInput; //estructura InfraredInput

//variables globales.......................................................
int verde1, verde2, verde3,cm;
int ultrasonico;
byte ir, intensidad;
//Variables necesarias para compass
float headingDegrees,heading;
int error = 0;
int MilliGauss_OnThe_XAxis;
float declinationAngle = 0.0457;
int c_actual, c_inicio,brujula;

//Inicia setup ............................................................
void setup() {
  //Para leer valores
    //Serial.begin(9600);
  //Comunicacion wire para i2c
    Wire.begin();
  //Se declaran los pines de los sensores y motores
    sensor_color.setPin(47,45,51,49,53); // pines de sensor de color 1
    sensor_color2.setPin(37,35,41,39,43); // pines de sensor de color 2
    sensor_color3.setPin(50,52,46,48,44); // pines de sensor de color 3
    robot.setM1puente2(6,7,8,9);//Pines de motor 1 en puente h segundo
    robot.setM2puente1(2,17,16,15); //Pines de motor 2 en puentte h primero
    robot.setM2puente2(3,14,4,5); //Pines de motor 2 en puente h segundo
    robot.setM1puente1(10,11,12,13);//Pines de motor 1 en puentte h primero 
   //....................................................
  
  //Encendemos puentes H
    robot.encenderPuente1();
    robot.encenderPuente2();

  //Se inicia el compas y se comprueba si no existen errores, asi como se le da la escala
    error = compass.SetScale(1.3); // Set the scale of the compass.
    if(error != 0) // If there is an error, print it out.
      Serial.println(compass.GetErrorText(error));
  
    error = compass.SetMeasurementMode(Measurement_Continuous); // Set the measurement mode to Continuous
    if(error != 0) // If there is an error, print it out.
      Serial.println(compass.GetErrorText(error));
   
   //Obtenemos los grados con los que esta viendo el sensor con la variable c_inicio
    c_inicio=obtenerGrados();
}

//Iniciamos ciclo..............................................
void loop() {
  //Obtenemos el valor de los grados actuales
    c_actual = obtenerGrados();
  //Obtenemos los grados ya reseteados como inicio el robot, brujula es donde estan los grados ya bien
    brujula = arreglarCompas();

  //Necesario llamar metodo color de los sensores de color para leer datos
    sensor_color3.color();
    sensor_color2.color();
    sensor_color.color();
  //.......................

  //Obtenemos el valor de los sensores de color
    verde1=sensor_color3.getGreen();
    verde2=sensor_color2.getGreen();
    verde3=sensor_color.getGreen();
  //........
  
  //Obtenemos el valor de ultrasonico
    ultrasonico=us.Ranging(cm);

  //Leemos valores de infrarrojo
    seekerInput=seeker.ReadAC();
  
  //Obtenermos la direccion y la fuerza de infrarrojo
    ir=seekerInput.Direction;
    intensidad=seekerInput.Strength;
  
  //Imprimir valores de prueba.....................
    //imprimir_valores();
 
  //Que el robot juegue fut :)
    followball();
}

//FUNCIONES.......................................................................

//Devuelbe un entero con los grados que de el sensor, codigo sacado del provedor del sensor de compas
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

//Devuelve el valor en grados ya arreglado con respecto del robot
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

//MOTORES..........................................................................................
//IMPORTANTE:
//Motor 1 es el parametro 1
//Motor 2 es el parametro 2
//Motor 3 es el parametro 4
//Motor 4 es el parametro 3

void adelante()
{
  robot.Aadelante(100, 255,255 , 120);
}
void esquinaSupIzq()
{
  robot.Aadelante(0, 110,110 , 0);
}
void esquinaSupDer()
{   
  robot.Aadelante(110,0,0,110);
}
void esquinaInfIzq()
{
  robot.Aatras(110,0,0,110);
}
void esquinaInfDer()
{
  robot.Aatras(0,110,110,0);
}
void derecha()
{
 robot.derecha(110); 
}
void izquierda()
{
  robot.izquierda(110);
}
void alinearDer()
{
   robot.alinearDer(70);
}
void alinearIzq()
{
  robot.alinearIzq(70);
}
void atras()
{
  robot.Aatras(110,110,110,110);
}
//...............................................................
 
//IMPRIMIR VALORES........................................
void imprimir_valores()
{
  Serial.print("Infra: ");
  Serial.print(ir);
  Serial.print(" , ");
  Serial.print(" Inten: ");
  Serial.print(intensidad);
  Serial.print(" Ultra: ");
  Serial.print(ultrasonico); 
  Serial.print(" , ");
  Serial.print(" verde1: ");
  Serial.print(verde1);
  Serial.print(" , ");
  Serial.print(" verde2 ");
  Serial.print(verde2);
  Serial.print(" , ");
  Serial.print(" verde3: ");
  Serial.print(verde3);
  Serial.print(" compas: ");
  Serial.println(brujula);
}
//......................................

//Funcion principal donde el robot puede jugar futbol...........................
void followball() 
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
    switch(ir) // switch que sirve como if , con el cual detectara la ubicacion de la pelota con numeros de 0 a 9
    {
      case 0:
        if(ultrasonico>3)
        {  
          if(verde1>1000  &&  verde2>11  && verde3>11)
          {
            robot.alto();
            atras();
          }
         else
         {
          robot.alto();
          adelante();
          delay(400);
         }
        }
       else
       {
        robot.alto();
       }  
      break;
    case 1:
      if(ultrasonico>3)
      {
        if(verde1>1000  &&  verde2>11  && verde3>11)
        {
          robot.alto();
          esquinaInfIzq();
        }
        else
        {
          robot.alto();
          esquinaSupDer();
          delay(400);
        }
      }
      else
      {
        robot.alto();
      }
      break;
    case 2:
      if(ultrasonico>3)
      { 
        if(verde1>1000  &&  verde2>11  && verde3>11)
        {
          robot.alto();
          esquinaInfIzq();
        }
        else
        {
          robot.alto();
          esquinaSupDer();
          delay(400);
        }
      }
      else
      {
        robot.alto();
      } 
      break;
    case 3:
      if(verde1>1000  &&  verde2>11  && verde3>11)
      {
        robot.alto();
        izquierda();
      }
      else
      {
        robot.alto();
        derecha();
        delay(400);
      }
      break;
    case 4:
     if(verde1>1000  &&  verde2>11  && verde3>11)
     {
      if(intensidad<25)
      {
        if(ultrasonico>3)
        {
          robot.alto();
          esquinaInfIzq();
        }
        else
        {
          robot.alto();
        }
      } 
      else
      {
        robot.alto();
        esquinaSupIzq();    
      }
    }
    else
    {
      if(intensidad<25)
      {
        robot.alto();
        esquinaSupDer();
        delay(400);
      } 
      else
      {
        robot.alto();
        esquinaInfDer();
        delay(400);   
      }
     }
     break;
    case 5:
      if(verde1>1000  &&  verde2>11  && verde3>11)
      {
       if(intensidad<25)
       {
        if(ultrasonico>3)
        {
          robot.alto();
          esquinaInfIzq();
        }
        else
        {
          robot.alto();
        }
       } 
       else
       {
        robot.alto();
        adelante();   
       }
     }
     else
     {
      if(intensidad<25)
      {
        robot.alto();
        esquinaSupDer();
        delay(400);
      } 
      else
      {
        robot.alto();
        atras(); 
        delay(400);  
      }
     }
     break;
    case 6:
      if(verde1>1000  &&  verde2>11  && verde3>11)
      {
        if(intensidad>24)
        {
          robot.alto();
          esquinaSupDer();
        } 
        else
        {
          if(ultrasonico>3)
          {
            robot.alto();
            esquinaInfDer();
          }
          else
          {
            robot.alto();
          }   
         }
      }
      else
      {
        if(intensidad>24)
        {
          robot.alto();
          esquinaInfIzq();
          delay(400);
         } 
         else
         {
          robot.alto();
          esquinaSupIzq();  
          delay(400); 
         }
      }
     break;
    case 7:
     if(verde1>1000  &&  verde2>11  && verde3>11)
     {
      if(intensidad>24)
      {
        robot.alto();
        esquinaSupDer();
      } 
      else
      {
        if(ultrasonico>3)
        {
          robot.alto();
          esquinaInfDer(); 
        }
        else
        {
          robot.alto();
        }  
      }
     }
     else
     {
      if(intensidad>24)
      {
        robot.alto();
        esquinaInfIzq();
        delay(400);
      } 
      else
      {
        robot.alto();
        esquinaSupIzq(); 
        delay(400);  
      }
     }
     break;
    case 8:
      if(ultrasonico>3)
      {
       if(verde1>1000  &&  verde2>11  && verde3>11)
       {
        robot.alto();
        esquinaInfDer();
       }
       else
       {
        robot.alto();
        esquinaSupIzq();
        delay(400);
       }
     }
     else
     {
      robot.alto();
     }
     break; 
    case 9:
      if(ultrasonico>3)
      {
       if(verde1>1000  &&  verde2>11  && verde3>11)
       {
        robot.alto();
        esquinaInfDer();
       }
       else
       {
        robot.alto();
        esquinaSupIzq();
        delay(400);
       }
      }
      else
      {
        robot.alto();
      } 
     break;
   }
 }
}




