#include <Wire.h>

#include <Omnidireccional.h>

#include <HTInfraredSeeker.h>

InfraredSeeker infra = InfraredSeeker();
InfraredInput infraInput;
Omnidireccional robot = Omnidireccional();

void setup()
{

  Wire.begin();
  Serial.begin(9600);
 
}

void loop() 
{

  infraInput = infra.ReadAC();
  followball(infraInput.Direction, infraInput.Strength);

}

void followball(byte k,byte f)
{

  Serial.print(k);
  Serial.print(" , ");
  Serial.println(f);
  
  switch(k)
  {
  
    case 0:
        
        robot.eIDer(150);
        
          break;
       
     case 1:
  
        robot.eIDer(150);
       
           break;
        
      case 2:
   
         robot.eIDer(150);
      
            break;
         
       case 3:
    
          robot.eIDer(150);
       
             break;
          
        case 4:
            
           robot.eIIzq(150);         
        
              break;
              
         case 5:
    
            robot.adelante(150);
       
               break;
          
          case 6:
     
             robot.eIDer(150);
        
                break;
           
          case 7:
     
             robot.eIIzq(150);
        
                break;
           
           case 8:
      
              robot.eIIzq(150);
         
                 break;
            
           case 9:
           
              robot.eIIzq(150);
              
                  break;
        
  }

}

