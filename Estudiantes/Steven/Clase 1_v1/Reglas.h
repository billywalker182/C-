
#ifndef REGLAS_H
#define REGLAS_H

#include<iostream>

using namespace std;


class Reglas{
	//Atributos
	private:
		string Posicion;
		int filaPos=0;

	public:
		//Metodos
		
		Reglas(){
			
		}
		int getValFila(){
			return filaPos;
		}
		bool FichaExiste(string ficha);
		bool FichasDelJugador(int perfil,string *infoTablero);
	
};

#endif
