//		:::DECLARACIÓN DE LA CLASE TABLERO:::

#include<iostream>


using namespace std;


class Tablero{
	//Atributos
	private:
		string tablero[6][6];
		string jugador1 , jugador2;

	public:
		//Metodos
		
		Tablero(){
			
		}
		
		
		void MostrarTablero();
		void InicializarTablero();
		void AnalizarJugada();
		void BorrarFicha(string Posicion);
		void CorrerFicha(string Posicion);
		//26-08-20
		void setJugador1(string nombre);
		void setJugador2(string nombre);
		string * getTablero(int nFila);
	
};
