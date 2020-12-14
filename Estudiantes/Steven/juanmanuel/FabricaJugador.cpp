#include <iostream>
#include "FabricaJugador.h"
#include "JugadorHumano.h"
#include "Tablero.h"



using namespace std;

//Instanciar las Clases
JugadorHumano* humano = new JugadorHumano[100];//2
Tablero* tablero = new Tablero();

void Play(){
	string _fichaPas, _fichaAct;
	cout<<(humano+0)->getNombre()<<" -> Posicion de la Ficha que Desea Mover: ";
	getline(cin,_fichaPas);
	
}

void FabricaJugador::crearPartida(){
	
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
				fflush(stdin);//Vaciar buffer
				(humano+0)->Dato();
				tablero->setJugador1((humano+0)->getNombre());
				(humano+1)->Dato();
				tablero->setJugador2((humano+1)->getNombre());
				tablero->InicalizarTablero();
				tablero->MostrarTablero();
				Play();
				system("pause");
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default: cout<<"Ingrese una opcion valida"<<endl;break;
		}
		
		cout<<endl;
		
	}while(opc != 5);
}
