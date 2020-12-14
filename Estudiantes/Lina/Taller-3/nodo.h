#ifndef NODO_H
#define NODO_H
#include "Producto.h"
class nodo
{
	public:
		nodo();
		~nodo();
		void setdato(Producto);
		void setSiguienteptr(nodo *);
		Producto getdato();
		nodo * getSiguienteptr();
		void Imprimir();
	private:
	Producto dato;
	nodo * Siguienteptr;	
	protected:
};

#endif
