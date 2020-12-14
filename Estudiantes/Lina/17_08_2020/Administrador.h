#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

#include "AdminUsuario.h"

using namespace std;// estandar de c++ std::cout

//	:::MENU:::
void MenuAdministrador(){
	cout<<"\t:::MENU ADMINISTRADOR:::"<<endl;
	cout<<"1.Estudiante."<<endl;
	cout<<"2.Profesor."<<endl;
	cout<<"3.Materias."<<endl;
	cout<<"4.Facultades."<<endl;
	cout<<"5.Salir"<<endl;
	cout<<"\nDigite Una Opcion de Menu: ";
}

void Administrador(){
	
	int opcion;
	bool bandera;
	
	do{
		system("cls");
		fflush(stdin);
		opcion = 0;
		MenuAdministrador();
		cin>>opcion;
		
		switch(opcion){
			case 1:
				AdminUsuario(opcion);
				system("pause");
				break;
			case 2:
				AdminUsuario(opcion);
				system("pause");
				break;
			case 3:
				AdminMateria(opcion);
				break;
			case 4:
				AdminFacultad();
				break;
			case 5:
				break;
			default:cout<<"\nSe equivoco de opcion de Menu"<<endl<<endl;
		}
		cout<<endl;
	}while(opcion!=5);	
}
