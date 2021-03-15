#include <iostream>
#include "Punto.h"

using namespace std;


// implementacion de los operadores para la clase Pareja
//....................................
Punto::Punto(const Punto &p)
{
    *this=p;
}
//....................................
Punto& Punto::operator + (const Punto &p)
{
    this->x += p.x;
    this->y += p.y;
    return *this;
}
//....................................
Punto& Punto::operator - (const Punto &p)
{
    this->x -= p.x;
    this->y -= p.y;
    return *this;
}
//....................................
Punto& Punto::operator * (const Punto &p)
{
    this->x *= p.x;
    this->y *= p.y;
    return *this;
}
//....................................
Punto& Punto::operator / (const Punto &p)
{
    if (p.x != 0) this->x /= p.x;
    if (p.y != 0) this->y /= p.y;
    return *this;
}
//....................................
Punto& Punto::operator = (const Punto &p)
{
    if(this!=&p){ //Comprueba que no se esté intentanod igualar un objeto a sí mismo
        if (p.x != 0) this->x = p.x;
        if (p.y != 0) this->y = p.y;
    }
    return *this;
}

//....................................
Punto& Punto::operator ++ ()
{
    this->x ++;
    this->y ++;
    return *this;
}

//....................................
bool Punto::operator == (const Punto &p) const
{
    return this->x == p.x && this->y == p.y;
}
