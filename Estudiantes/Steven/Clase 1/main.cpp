//Creaion de Objetos
#include<string.h>

#include "FabricaJugador.h"



int main(int argc, char** argv) {
	
	FabricaJugador* partida = new FabricaJugador();//Partida Objeto Dinamico
	
	
	partida->crearPartida();
	
	system("pause");
	return 0;
}
