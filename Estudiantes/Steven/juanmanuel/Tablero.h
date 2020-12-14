#include <iostream>

using namespace std;


class Tablero{
	
	private:
		string tablero[6][6];
		string jugador1, jugador2;
	
	
	public:
		Tablero(){
			
		}
		
		void InicalizarTablero();
		void MostrarTablero();
		void setJugador1(string nombre);
		void setJugador2(string nombre);
		
};
