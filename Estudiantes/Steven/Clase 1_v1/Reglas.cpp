

#include <iostream>
#include <string.h>
#include "Reglas.h"
#include "Tablero.h"

using namespace std;

//Tablero* tableroRegla = new Tablero();


bool Reglas::FichasDelJugador(int perfil,string *infoTablero){
	if(perfil==1){
		for(int i=0;i<6;i++){
			cout<<*(infoTablero+i)<<" | ";
			if(*(infoTablero+i)=="TN" ||*(infoTablero+i)=="PN" || *(infoTablero+i)=="RN"){
			return true;
			}
		}
	}
	if(perfil==2){
		
	}
	
}

bool Reglas::FichaExiste(string ficha){
	bool banderax = false;
	bool banderay = false;
	string x = "ABCDEF";
	string y = "123456";
	
	for(int i=0;i<6;i++){
		if(ficha[0]==x[i]){
			banderax = true;
		}
		if(ficha[1]==y[i]){
			filaPos = i;
			banderay = true;
		}
	}
	
	if(banderax && banderay){
		return true;
	}
	else{
		return false;
	}
}
