#include "nodo.h"

nodo::nodo()
{
	setSiguienteptr(0);
}

nodo::~nodo()
{
	;
}


void nodo::setdato(Producto d){
	dato=d;
	
}
void nodo::setSiguienteptr(nodo *s){
	 Siguienteptr=s;
	
	
}
Producto nodo::getdato(){
	return dato;
	
}
nodo * nodo::getSiguienteptr(){
	return  Siguienteptr;
	
	
}
void nodo::Imprimir(){
	cout<<"Dato"<<endl;
	getdato().Imprimir();
	cout<<endl;
	cout<<"El nodo apunta a "<<getSiguienteptr()<<endl;
}



