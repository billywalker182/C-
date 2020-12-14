
#ifndef REGLAS_H
#define REGLAS_H

#include<iostream>

using namespace std;


class Reglas{
	//Atributos
	private:
		string Posicion;

	public:
		//Metodos
		
		Reglas(){
			
		}
		
		bool FichasJugador(int perfil,int fila,string *info);
	
};

#endif
