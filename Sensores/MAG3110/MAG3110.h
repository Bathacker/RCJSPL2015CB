#ifndef MAG3110_h
#define MAG3110_h
#define MAG_ADDR  0x0E //7-bit address for the MAG3110, doesn't change

struct Valores
{
	
	//Variables de los ejes
	int x;
	int y;
	int z;

};

class MAG3110
{

	public:

		//contructor
		MAG3110();
		void iniciar(); // metodo empezar
		Valores imprimirValores();
		int leerX(); // variables de los valores que se obtendran de los ejes 
		int leerY();
		int leerZ();

	private:

};
#endif