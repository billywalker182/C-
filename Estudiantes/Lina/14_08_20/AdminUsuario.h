#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

#include "CrearInformacion.h"
#include "LeerInformacion.h"
#include "ActualizarInformacion.h"
//#include "EliminarInformacion.h"

using namespace std;// estandar de c++ std::cout

//char txtProfesor[]="Profesores.txt";
//char txtMateria[]="Materias.txt";
//char txtEstudiante[]="Estudiantes.txt";

//		:::MENU USUARIO:::
void AdminUsuario(int perfil){
	int opcion;// Variable local solo se podr? utilizar dentro de la funci?n
	do{
		fflush(stdin);
		system("cls");
		if(perfil==1){
			cout<<"\t:::CONFIGURACIONES  -> ESTUDIANTE:::"<<endl;
		}
		if(perfil==2){
			cout<<"\t:::CONFIGURACIONES  -> PROFESOR:::"<<endl;
		}
		cout<<"1.Crear."<<endl;
		cout<<"2.Leer."<<endl;
		cout<<"3.Actualizar."<<endl;
		cout<<"4.Eliminar"<<endl;
		cout<<"5.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				if(perfil==1){
					CrearInformacion(txtEstudiante,perfil);	
				}
				if(perfil==2){
					CrearInformacion(txtProfesor,perfil);
				}
				cout<<endl;
				system("pause");
				break;
			case 2:
				if(perfil==1){
					LeerInformacion(txtEstudiante,perfil);	
				}
				if(perfil==2){
					LeerInformacion(txtProfesor,perfil);
				}
				cout<<endl;
				system("pause");
				break;
			case 3:
				if(perfil==1){
					ActualizarInformacion(txtEstudiante,perfil);	
				}
				if(perfil==2){
					ActualizarInformacion(txtProfesor,perfil);
				}
				cout<<endl;
				system("pause");
				break;
			case 4:
				if(perfil==1){
					EliminarInformacion(txtEstudiante,perfil);	
				}
				if(perfil==2){
					EliminarInformacion(txtProfesor,perfil);
				}
				cout<<endl;
				system("pause");
				break;
			case 5:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 5);
}


void AdminMateria(int perfil){
	int opcion;// Variable local solo se podr? utilizar dentro de la funci?n
	string codigo;
	do{
		fflush(stdin);
		system("cls");
		cout<<"\t:::CONFIGURACIONES  -> MATERIA:::"<<endl;
		cout<<"1.Crear."<<endl;
		cout<<"2.Leer."<<endl;
		cout<<"3.Actualizar."<<endl;
		cout<<"4.Eliminar."<<endl;
		cout<<"5.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;
	
		switch(opcion){
			case 1:
				CrearInformacion(txtMateria,perfil);	
				cout<<endl;
				system("pause");
				break;
			case 2:
				LeerInformacion(txtMateria,perfil);
				cout<<endl;
				system("pause");
				break;
			case 3:
				ActualizarInformacion(txtMateria,perfil);	
				cout<<endl;
				system("pause");
				break;
			case 4:
				fflush(stdin);
				cout<<"Ingrese Codigo de la Materia: ";
				getline(cin,codigo);
				EliminarMateria(codigo);	
				cout<<endl;
				system("pause");
				break;
			case 5:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 5);
}

void AdminFacultad(){
	int opcion;// Variable local solo se podr? utilizar dentro de la funci?n
	string facultad;
	do{
		fflush(stdin);
		system("cls");
		cout<<"\t:::FACULTADES:::"<<endl;
		cout<<"1.Tecnologia."<<endl;
		cout<<"2.Ingenieria."<<endl;
		cout<<"3.Artes."<<endl;
		cout<<"4.Ciencias y Educacion."<<endl;
		cout<<"5.Medio Ambiente y Recursos Naturales."<<endl<<endl<<endl;
		
		cout<<"\t:::CONFIGURACIONES  -> FACULTAD:::"<<endl;
		cout<<"1.Lista de Estudiantes."<<endl;
		cout<<"2.Lista de Profesores."<<endl;
		cout<<"3.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				fflush(stdin);
				cout<<"Ingrese Nombre de La Facultad: ";
				getline(cin,facultad);
				LeerFacultad(facultad,"EST");	
				cout<<endl;
				system("pause");
				break;
			case 2:
				fflush(stdin);
				cout<<"Ingrese Nombre de La Facultad: ";
				getline(cin,facultad);
				LeerFacultad(facultad,"PRO");	
				cout<<endl;
				system("pause");
				break;
			case 3:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 3);
}
