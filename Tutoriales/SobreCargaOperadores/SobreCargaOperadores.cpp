#include <iostream>

using namespace std;

struct Punto{
	double x, y;
};

//Prototipo
Punto operator+(const Punto &p, const Punto &q);

int main(){
	
	Punto a, b, r;
	a.x = 0.0;
	a.y = -1.5;
	b.x = 2.4;
	b.y = 5.23;
	//r = suma(a,b);
	//:::SOBRE CARGA DE OPERADORES:::
	r = a + b;
	cout<<r.x<<", "<<r.y<<endl;
	
	return 0;
}

Punto operator+(const Punto &p, const Punto &q){
	Punto r;
	r.x = p.x + q.x;
	r.y = p.y + p.y;
}
