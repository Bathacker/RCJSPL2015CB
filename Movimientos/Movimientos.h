#ifndef Movimientos_h
#define Movimientos_h
class Movimientos
{
  public:	
   
   Movimientos();
   void setM1(int M1PWM, int M1INB, int M1INA, int M1EN);
   void setM2(int M2PWM, int M2INB, int M2INA, int M2EN);
   void encenderM1();
   void apagarM1();
   void encenderM2();
   void apagarM2();
   void adelante1(int vel);
   void atras1(int vel);
   void alto1();
   void adelante2(int vel);
   void atras2(int vel);
   void alto2();
   void adelante(int vel);
   void atras(int vel);
   void derecha(int vel);
   void izquierda(int vel);
   void alto();
  
  private:
  
    byte M2PWM, M2INB, M2INA, M2EN, M1PWM, M1INB, M1INA, M1EN; 

};
#endif