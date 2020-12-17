
# include <iostream>

using namespace std;

class Punto {
	
	//Operadores no miembros
	friend ostream& operator << (ostream &o, const Punto &p);
	friend istream& operator >> (istream &o, Punto &p);
	
	private:
		int x, y;
		
	public: 
		//Constructor base
		Punto() : x(0), y(0) {}
		
		//Constructor Parametrizado
		Punto(const int x, const int y){
			this->x = x;
			this->y = y;
		}
		
		//Constructor de Copia
		Punto(const Punto&);
		
		//Operadores Miembros
		Punto& operator + (const Punto &p);
    	Punto& operator - (const Punto &p);
    	Punto& operator * (const Punto &p);
    	Punto& operator / (const Punto &p);
    	Punto& operator = (const Punto &p);
    	Punto& operator ++();
    	bool   operator ==(const Punto &p) const;
};
