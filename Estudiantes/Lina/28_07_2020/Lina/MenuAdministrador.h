#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres

#include "Administrador.h"

using namespace std;// estandar de c++ std::cout

//		:::menu usuario:::
//		:::MENU USUARIO:::
void MenuUsuario(string usuario){
	int opcion;// Variable local solo se podr? utilizar dentro de la funci?n
	do{
		fflush(stdin);
		system("cls");
		cout<<"\t:::CONFIGURACIONES  -> "<<usuario<<" :::"<<endl;
		cout<<"1.Crear."<<endl;
		cout<<"2.Leer."<<endl;
		cout<<"3.Actualizar."<<endl;
		cout<<"4.Eliminar"<<endl;
		cout<<"5.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				CrearEstudiante();
				cout<<endl;
				system("pause");
				break;
			case 2:
				LeerEstudiante();
				cout<<endl;
				system("pause");
				break;
			case 3:
				ActualizarEstudiante();
				cout<<endl;
				system("pause");
				break;
			case 4:
				EliminarEstudiante();
				cout<<endl;
				system("pause");
				break;
			case 5:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
		system("cls");
	}while(opcion != 5);
}

//	:::MENU ADMINISTRADOR:::
void MenuAdministrador(){
	int opcion;
	do{
		fflush(stdin);
		system("cls");
		cout<<"\t:::MENU ADMINISTRADOR:::"<<endl;
		cout<<"1.Estudiante."<<endl;
		cout<<"2.Profesor."<<endl;
		//cout<<"3.Materias."<<endl;
		cout<<"3.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				MenuUsuario("Estudiante");
				break;
			case 2:
				MenuUsuario("Profesor");
				break;
			case 3:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 3);
	
}


