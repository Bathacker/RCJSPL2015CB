#ifndef MAG3110_h
#define MAG3110_h
#define MAG_ADDR  0x0E //7-bit address for the MAG3110, doesn't change

class MAG3110
{

	public:

		//contructor
		MAG3110();
		void iniciar(); // metodo empezar
		void imprimirValores();
		int leerX(); // variables de los valores que se obtendran de los ejes
		int leerY();
		int leerZ();

	private:

};
#endif