

#include <iostream>
#include <string.h>
#include "Reglas.h"
#include "Tablero.h"

using namespace std;

Tablero* tableroRegla = new Tablero();


bool Reglas::FichasJugador(int perfil,int fila,string *info){
	if(perfil==1){
		for(int i=0;i<6;i++){
			cout<<*(info+i)<<" | ";
			if(*(info+i)=="TN" ||*(info+i)=="PN" || *(info+i)=="RN"){
			return true;
			}
		}
	}
	if(perfil==2){
		
	}
	
}
