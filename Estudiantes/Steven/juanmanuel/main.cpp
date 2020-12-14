#include <iostream>
#include "FabricaJugador.h"

using namespace std;


int main(int argc, char** argv) {
	
	FabricaJugador * partida = new FabricaJugador();
	
	partida->crearPartida();
	return 0;
}
