// Sobrecarga de funciones miembro
//Funciones miembro -> Método
#include <iostream>
#include "Persona.h"

using namespace std;

int main(int argc, char** argv) {
	
	Persona* persona1 = new Persona("Jhon",21);
	persona1->correr();
	
	Persona* persona2 = new Persona("112312454");
	persona2->correr(4);
	return 0;
}
