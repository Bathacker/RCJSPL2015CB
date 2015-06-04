#ifndef TCS3200_h
#define TCS3200_h

class TCS3200 
{
  
  	public:
   		
   		TCS3200();
   		void color();
   		void setPin(int _s0, int _s1, int _s2, int _s3 ,int _out);
   		int getRed();
   		int getGreen();
   		int getBlue();

	private:
 
		int s0;  
		int s1;  
		int s2;  
		int s3;  
		int out;

		// Variables  
		int red = 0;  
		int green = 0;  
		int blue = 0; 

};
#endif