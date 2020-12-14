#include <iostream>

#include "Jugador.h"

using namespace std;

class JugadorHumano : public Jugador{
	
	private:
		string nombre;
	
	public:
		JugadorHumano(){
			
		}
		
		void Dato(){
			cout<<"Ingrese su NickName: ";
			getline(cin,nombre);
		}
		
		string getNombre(){
			return nombre;
		}
};
