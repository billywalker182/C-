//Funciones externas a una clase, pero la clase les va permitir a los miembros protegidos o privados de la clase
#include <iostream>
#include "Personaje.h"

void modificar(Personaje &p, int at, int def){
	p.ataque = at;
	p.defensa = def;	
}


int main(int argc, char** argv) {
	
	Personaje * principal = new Personaje(100,90);
	principal->mostrarDatos();
	
	modificar(*principal,60,50);
	principal->mostrarDatos();
	
	return 0;
}
