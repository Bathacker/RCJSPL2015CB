#ifndef VNH5019_h
#define VNH5019_h

class VNH5019
{
  public:	
   
   VNH5019();
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
  
  private:
  
    int M2PWM;
    int M2INB;
    int M2INA;
    int M2EN;
    int M1PWM;
    int M1INB;
    int M1INA;
    int M1EN; 

};
#endif