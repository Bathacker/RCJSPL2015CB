#include <HCSR04.h>

//Intelirobot escuela de robotica
// intelirobot.com.mx
// programa hecho por yoalli y diego 

//Librerias necesarias..............
#include <Omnidireccional.h>
#include <TCS3200.h>

#include <HTInfraredSeeker.h>
#include <Wire.h>
//.............................

//Instanceas de librerias
HCSR04 us= HCSR04(33, 31, 11900); //Pines sensor ultrasonico //Sensor ultrasonico
TCS3200 sensor_color;//sensor de color1
TCS3200 sensor_color2;//sensor de color2
TCS3200 sensor_color3;//sensor de color3
Omnidireccional robot = Omnidireccional();//Para motores con ambos puentes H
InfraredSeeker seeker=InfraredSeeker();//Sensor infrarrrojo
InfraredInput seekerInput; //estructura InfraredInput

//variables
int verde1, verde2, verde3,cm;
int ultrasonico;
byte ir, intensidad;
//int luz;  //Verde alrededor de 25, negro alrededor de 15, blanco alrededor de 40   

void setup() {
  //Para leer valores
  //Serial.begin(9600);
  //Comunicacion wire para i2c
  Wire.begin();
  //Se declaran los pines de los sensores y motores
  sensor_color.setPin(47,45,51,49,53); // pines de sensor de color 1
  sensor_color2.setPin(37,35,41,39,43); // pines de sensor de color 2
  sensor_color3.setPin(50,52,46,48,44); // pines de sensor de color 3
   robot.setM1puente1(10,11,12,13);
  robot.setM1puente2(6,7,8,9);//Pines de motor 1 en puente h segundo
  robot.setM2puente1(2,17,16,15); //Pines de motor 2 en puentte h primero
  robot.setM2puente2(3,14,4,5); //Pines de motor 2 en puente h segundo
  robot.setM1puente1(10,11,12,13);//Pines de motor 1 en puentte h primero 
  //....................................................
  
  //Encendemos puentes H
  robot.encenderPuente1();
  robot.encenderPuente2();
}

void loop() {



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
 
  //Que el robot juegue fut
  followball();
}



//MOTORES..........................................................................................
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
  Serial.println(verde3);
}
//......................................

void followball() 
{
  
  switch(ir) // switch que sirve como if , de lo contrario de no ver linea blanca hara todos los demas movimientos de los casos
  {
    case 0:
      robot.alto();
      esquinaInfDer();
      break;
    case 1:
    robot.alto();
      esquinaInfDer();
      break;
    case 2:
    robot.alto();
      izquierda();
      break;
    case 3:
    robot.alto();
       esquinaSupIzq();
       break;
    case 4:
    robot.alto();
       esquinaSupIzq();
       break;
    case 5:
      robot.alto();
      adelante();
      break;
    case 6:
    robot.alto();
    robot.adelante();
    break;
    case 7:
     robot.alto();
     esquinaSupDer();
     break;
    case 8:
     robot.alto();
     derecha();
     break;
    case 9:
     robot.alto();
     esquinaInfDer();
     break;

}

}



