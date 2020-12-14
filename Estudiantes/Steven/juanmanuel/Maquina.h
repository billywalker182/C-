#include <iostream>
#include "Jugador.h"

using namespace std;


class Maquina: public Jugador{
	
	private:
		string nombre;
	public:
		Maquina(){
			
		}
		
		void Dato(){
			nombre = "Maquina";
		}
		
		string getNombre(){
			return nombre;
		}
};
