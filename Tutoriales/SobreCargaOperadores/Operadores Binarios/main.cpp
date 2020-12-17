#include <iostream>

#include "Punto.h"

// implemetaci¢n de operadores no miembros
ostream& operator << (ostream &o,const Punto &p)
{
    o << "(" << p.x << ", " << p.y << ")";
    return o;
}

istream& operator >> (istream &i, Punto &p)
{
    cout << "Introducir valores para ( a, b) :";
    i >> p.x >> p.y;
    i.ignore();
    return i;
}


int main(int argc, char** argv) {
	
	
	Punto A(50,  75);
    Punto B(100, 15);
    Punto C;

    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "........................." << endl;
    C = A * B;
    cout << "A = " << A << "\n";
    cout << "C = " << C << endl;
    cout << "........................." << endl;

    ++C;
    cout << "C = " << C << endl;
    cout << "A == B " << ( (A==B) ? "Si": "No" );
    cin.get();
	
	
	return 0;
}
