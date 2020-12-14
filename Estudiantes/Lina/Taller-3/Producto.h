#ifndef PRODUCTO_H
#define PRODUCTO_H
#include<string>
#include <iostream>
#include<fstream>

using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::string;


class Producto
{
	public:
		Producto();
		~Producto();
		Producto(string,int);
		void setNombre(string);
		void setPrecio(int);
		string getNombre();
		int getPrecio();
		void Imprimir();
	private:
	string Nombre;
	int Precio;
};

#endif
