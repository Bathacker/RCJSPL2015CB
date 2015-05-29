#ifndef LED_h
#define LED_h
class LED {
  public:
   LED(int x);
   void apagar();
   void prender();
   void parpadeoRapido();
   void parpadeoLento();
private:
	int L;
};
#endif
