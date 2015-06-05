#ifndef MAG3110_h
#define MAG3110_h
#define MAG_ADDR  0x0E //7-bit address for the MAG3110, doesn't change

struct Valores
{
	
	//Variables
	int x;
	int y;
	int z;

};

class MAG3110
{

	public:

		//Metodos
		MAG3110();
		void iniciar();
		Valores imprimirValores();
		int leerX();
		int leerY();
		int leerZ();

	private:

};
#endif