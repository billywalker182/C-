#include <iostream>

#include "JugadorHumano.h"
#include "Maquina.h"
#include "FabricaJugador.h"
#include "Tablero.h"
#include "Ficha.h"
#include "Reglas.h"

using namespace std;

//	:::Variables locales:::
int perfil1 = 1;
int perfil2 = 2;

//Instanciar Clase
JugadorHumano* humano = new JugadorHumano[100];
Tablero* tablero = new Tablero();
Ficha* ficha = new Ficha();
Reglas* regla = new Reglas();

bool enviarPosicion(string _ficha,int _perfil){
	bool bandera;
	bool final;
	int fila = regla->getValFila();
	cout<<"esta es: "<<fila;
	bandera = regla->FichaExiste(_ficha);
	string * temp;
	if(bandera){
		temp = tablero->getTablero(fila);
		cout<<"Valor de bandera: "<<bandera<<endl;
		for(int i=0;i<6;i++){
			cout<<*(temp+i)<<" | ";
		}
		final = regla->FichasDelJugador(_perfil,temp);
	}
	return final;
}

void Play(){
	string _fichaPas,_fichaAct;
	bool banderaJuego = true;
	bool banderaJugador1 = true;
	bool banderaJugador2 = true;
	while(banderaJuego){
		while(banderaJugador1){
			cout<<endl;
			cout<<(humano+0)->getNombre()<<" -> Posicion de la Ficha que Desea Mover: ";
			getline(cin,_fichaPas);
			ficha->setFicha(_fichaPas);
			_fichaPas = ficha->getFicha();
			banderaJugador1 = enviarPosicion(_fichaPas,perfil1);
			while(banderaJugador1){
				cout<<(humano+0)->getNombre()<<" -> Posicion de la Ficha a Donde Desea Mover: ";
				getline(cin,_fichaAct);
				ficha->setFicha(_fichaAct);
				_fichaAct = ficha->getFicha();
				banderaJugador1 = enviarPosicion(_fichaAct,perfil1);
				if(banderaJugador1){
					tablero->BorrarFicha(_fichaPas);
					tablero->CorrerFicha(_fichaAct);
					break;
				}else{
					cout<<"Ingrese una posicion valida -> :("<<endl;
					banderaJugador1 = true;//para que se repita si no esta
				}
			}
			if(!banderaJugador1){
				cout<<"Ingrese una posicion valida -> :("<<endl;
				banderaJugador1 = true;
			}else{
				banderaJugador1 = false;
			}
		}
		
		tablero->MostrarTablero();
		system("pause");
		
	}
	
}


void FabricaJugador::crearPartida(){
	//Maquina* maquina = new Maquina[1];
	int opc;
	do{
		
		cout<<"\n\t:::TRIMOK:::"<<endl;
		cout<<"1. Humano VS Humano."<<endl;
		cout<<"2. Maquina VS Humano."<<endl;
		cout<<"3. Humano VS Maquina."<<endl;
		cout<<"4. Maquina VS Maquina."<<endl;
		cout<<"5. Salir."<<endl;
		cout<<"Ingrese una Opcion: ";
		cin>>opc;
		
		switch(opc){
			case 1:
				fflush(stdin);
				(humano+0)->Dato();
				tablero->setJugador1((humano+0)->getNombre());
				(humano+1)->Dato();
				tablero->setJugador2((humano+1)->getNombre());
				tablero->InicializarTablero();
				tablero->MostrarTablero();
				Play();
				system("pause");
				break;
			case 2:
				break;
				system("pause");
			case 3:
				break;
				system("pause");
			case 4:
				break;
			case 5:
				system("pause");
				break;
			default: cout<<"Ingrese una opcion valida"<<endl;break;
		}
		
		cout<<endl;
		
	}while(opc != 5);
}


