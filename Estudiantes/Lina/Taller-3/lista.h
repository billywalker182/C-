#ifndef LISTA_H
#define LISTA_H

#include<string>
#include <iostream>
#include<fstream>

using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include"nodo.h"
#include "Producto.h"

class lista
{
	public:
		lista();
		~lista();
		
		void Imprimir();
		void setPrimerptr(nodo *);
		void setUltimoptr(nodo *);
		nodo *getPrimerptr();
		nodo *getUltimoptr();
		void InsertarInicio(nodo *);
		void InsertarFinal(nodo *);
		void EliminarInicio(nodo *);
		void EliminarFinal(nodo *);
		void Mostrar();

	private:
	nodo *Primerptr;
	nodo *Ultimoptr;
	protected:

		
		
};

#endif
