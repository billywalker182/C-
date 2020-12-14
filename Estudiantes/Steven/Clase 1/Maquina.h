#include <iostream>

#include "Jugador.h"

using namespace std;

class Maquina : public Jugador{
	
	private:
		string nombre;
	
	public:
		void Dato(){
			nombre = "Maquina";
		}
};
