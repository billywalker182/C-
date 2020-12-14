#include "Producto.h"
// Porgrama presentado por Lina Marcela Bonill Rincon 20201578111
Producto::Producto()
{
	setNombre("Vacio");
	setPrecio(0);
	
}

Producto::~Producto()
{
 ;
}
Producto::Producto(string n, int p){
	setNombre(n);
	setPrecio(p);
}
void Producto::setNombre(string n){
	Nombre=n;
	
}
void Producto::setPrecio(int p){
  Precio=p;
	
}
string Producto::getNombre(){
	return Nombre;
	
	
}
int Producto::getPrecio(){
	
	return Precio;
	
}
void Producto::Imprimir(){
	
	cout<<"["<<getNombre()<<" "<<getPrecio()<<"]"<<"\t";
}
