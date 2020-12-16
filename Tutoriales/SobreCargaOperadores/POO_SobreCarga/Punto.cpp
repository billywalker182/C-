#include<iostream>
#include"Punto.h"

using namespace std;

double Punto::getX(){
	return x;
} 

double Punto::getY(){
	return y;
} 

Punto& operator +(const Punto &p1, const Punto &p2){
	Punto res(p1.x + p2.x , p1.y + p2.y);
	return res;
}
