#ifndef LCD_h
#define LCD_h
#include "Arduino.h"

	class LCD
	{

		public:

			void setPin(int Backlight, int En, int Rw, int Rs, int D4, int D5, int D6, int D7);
			void imprimirValores();

		private:


	};
#endif