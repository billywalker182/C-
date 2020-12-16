#include <iostream>

class Punto{
	
	private:
		double x , y;
		
	//Constructor
	public:
		Punto(const double x , const double y){
			this->x = x;
			this->y = y;
		}
		
		double getX();
		double getY();
		
		friend Punto& operator +(const Punto &p1, const Punto &p2);
};


