#include <iostream>
#include <string.h>
#include "Tablero.h"

using namespace std;

string tempFicha = "";

void Tablero::MostrarTablero(){
	system("cls");
	cout<<"\n\t           :::TRIMOK:::"<<endl;
	cout<<"\t  _______________________________"<<"\tJugador 1: "<<jugador1<<" -> Fichas: Negras"<<endl;
	for(int i = 0;i<6;i++){
		cout<<"\t"<<6-i<<" | ";
		for(int j = 0;j<6;j++){
			cout<<tablero[i][j]<<" | ";
		}
		cout<<"\n\t  |----|----|----|----|----|----|"<<endl;
	}
	cout<<"\t     A    B    C    D    E    F   "<<"\tJugador 2: "<<jugador2<<" -> Fichas: Blancas"<<endl;

}

void Tablero::InicializarTablero(){
	tablero[5][0] = tablero[4][0] = tablero[5][3] = tablero[4][3] = "TB";
	tablero[1][0] = tablero[0][0] = tablero[1][3] = tablero[0][3] = "TN";
			
	//Papel
	tablero[5][1] = tablero[4][1] = tablero[5][4] = tablero[4][4] = "PB";
	tablero[1][1] = tablero[0][1] = tablero[1][4] = tablero[0][4] = "PN";
			
	//Roca
	tablero[5][2] = tablero[4][2] = tablero[5][5] = tablero[4][5] = "RB";
	tablero[1][2] = tablero[0][2] = tablero[1][5] = tablero[0][5] = "RN";
			
	//Espacios
	tablero[3][0] = tablero[2][0] = tablero[3][1] = tablero[2][1] = "  ";
	tablero[3][2] = tablero[2][2] = tablero[3][3] = tablero[2][3] = "  ";
	tablero[3][4] = tablero[2][4] = tablero[3][5] = tablero[2][5] = "  ";
}

void Tablero::BorrarFicha(string Posicion){
	string x = "ABCDEF";
	string y = "654321";
	int fila,col;
	for(int i=0;i<6;i++){
		if(Posicion[0]==x[i]){
			col = i;
		}
		if(Posicion[1]==y[i]){
			fila = i;
		}
	}
	tempFicha = tablero[fila][col];
	tablero[fila][col]= "  ";
}

void Tablero::CorrerFicha(string Posicion){
	string x = "ABCDEF";
	string y = "654321";
	int fila,col;
	for(int i=0;i<6;i++){
		if(Posicion[0]==x[i]){
			col = i;
		}
		if(Posicion[1]==y[i]){
			fila = i;
		}
	}
	tablero[fila][col]= tempFicha;
	tempFicha = "";
}
//			:::28/08/20:::

void Tablero::setJugador1(string jugador1){
	for(int i=0;i<jugador1.length();i++){
		this->jugador1 += toupper(jugador1[i]);
	}
	
}
void Tablero::setJugador2(string jugador2){
	for(int i=0;i<jugador2.length();i++){
		this->jugador2 += toupper(jugador2[i]);
	}
}

string* Tablero::getTablero(int nFila){
	static string temp[1000];
	for(int i =0;i<6;i++){
		temp[i]=tablero[nFila][i];
	}
			
	return temp;
			
}
	

