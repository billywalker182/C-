
//https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C%2B%2B/Sobrecarga_de_Operadores#:~:text=La%20sobrecarga%20de%20operadores%20es,definici%C3%B3n%20de%20una%20funci%C3%B3n%20cualquiera.
#include <iostream>
#include "Punto.h"

using namespace std;

// Mostrar segundo paso
// Sobrecarga del operador +
Punto& operator +(const Punto &p1, const Punto &p2){
	Punto res(p1.x + p2.x , p1.y + p2.y);
	return res;
}

int main(int argc, char** argv) {
	
	Punto A(0.0,-1.5);
	Punto B(2.4,5.23);
	Punto C = A + B;
	
	//Mostrar Segunda Parte
	//Punto C = A + B;
	
	cout<<"A = "<<A.getX()<<", "<<A.getY()<<endl;
	cout<<"B = "<<B.getX()<<", "<<B.getY()<<endl;
	cout<<"A = "<<C.getX()<<", "<<C.getY()<<endl;
	return 0;
}
