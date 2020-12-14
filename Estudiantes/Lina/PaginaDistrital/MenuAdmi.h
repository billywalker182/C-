#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la función getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres


#include "AdminEstdiante.h"
#include "AdminProfesor.h"
#include "AdminMateria.h"

using namespace std;// estandar de c++ std::cout
//------------------------------------------


//		:::MENU PROFESOR:::
void MenuMaterias(){
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		fflush(stdin);
		system("cls");
		cout<<"\t:::CONFIGURACIONES  -> MATERIAS:::"<<endl;
		cout<<"1.Crear."<<endl;
		cout<<"2.Leer."<<endl;
		//cout<<"3.Actualizar."<<endl;
		//cout<<"4.Eliminar"<<endl;
		cout<<"3.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				CrearMateria();
				cout<<endl;
				system("pause");
				break;
			case 2:
				LeerMateria();
				cout<<endl;
				system("pause");
				break;
			case 5:
				//ActualizarProfesor();
				cout<<endl;
				system("pause");
				break;
			case 4:
				//EliminarProfesor();
				cout<<endl;
				system("pause");
				break;
			case 3:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
		system("cls");
	}while(opcion != 3);
}


//		:::MENU PROFESOR:::
void MenuProfesor(){
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		fflush(stdin);
		system("cls");
		cout<<"\t:::CONFIGURACIONES  -> PROFESOR:::"<<endl;
		cout<<"1.Crear."<<endl;
		cout<<"2.Leer."<<endl;
		cout<<"3.Actualizar."<<endl;
		cout<<"4.Eliminar"<<endl;
		cout<<"5.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				CrearProfesor();
				cout<<endl;
				system("pause");
				break;
			case 2:
				LeerProfesor();
				cout<<endl;
				system("pause");
				break;
			case 3:
				ActualizarProfesor();
				cout<<endl;
				system("pause");
				break;
			case 4:
				EliminarProfesor();
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

//		:::MENU USUARIO:::
void MenuEstudiante(){
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		fflush(stdin);
		system("cls");
		cout<<"\t:::CONFIGURACIONES  -> ESTUDIANTE:::"<<endl;
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

//		:::MENU ADMINISTRADOR:::
void MenuAdministrador(){
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		fflush(stdin);
		system("cls");
		cout<<"\t:::MENU ADMINISTRADOR:::"<<endl;
		cout<<"1.Estudiante."<<endl;
		cout<<"2.Profesor."<<endl;
		cout<<"3.Materias."<<endl;
		cout<<"4.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				MenuEstudiante();
				break;
			case 2:
				MenuProfesor();
				break;
			case 3:
				MenuMaterias();
				break;
			case 4:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 4);
};






