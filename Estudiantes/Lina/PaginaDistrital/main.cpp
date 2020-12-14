#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la función getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

#include "MenuAdmi.h"
#include "Estudiante.h"
#include "Profesor.h"


using namespace std;// estandar de c++ std::cout
//------------------------------------------

//		:::VARIABLES GLOBALES:::
string passwordAdmin = "12345";
string _codigo;

//		:::VERIFICAR PROFESOR Y ESTUDIANTE::::
//---------------------------------------------------
bool PreguntarCodigo(char _txt[]){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string texto;
	
	archivo.open(_txt,ios::in);//Abrimos en modo lectura
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	cout<<"Ingrese Su Codigo: ";
	getline(cin,_codigo);
	string dato = "Codigo:     "+_codigo;
	bool bandera = false;
	while(!archivo.eof()){
		getline(archivo,texto);
		if(dato==texto){
			bandera = true;
		}
	}
	
	archivo.close();
	if(bandera){
		return true;
	}
	else{
		return false;
	}
}

//		:::VERIFICAR ADMIN:::
bool VerificarAdmin (string password){
	system("cls");
	fflush(stdin);
	string codigo;
	bool bandera;
	cout<<"Ingrese su Codigo: ";
	getline(cin,codigo);
		if(password==codigo){
			bandera = true;
			return bandera;
		}
		else{
			bandera = false;
		}
	return bandera;
}


void CrearArchivos(){
	ofstream archivo; //o->out etiquitar como int variable = 5;
	archivo.open(txtEstudiante,ios::app); // abriendo el archivo
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	
	archivo.close();
	

	archivo.open(txtProfesor,ios::app); // abriendo el archivo
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	
	archivo.close();
	
		archivo.open(txtMateria,ios::app); // abriendo el archivo
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	
	archivo.close();
}

int main(int argc, char** argv) {

	CrearArchivos();
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	bool bandera;
	do{
		cout<<"\t:::PAGINA DISTRITAL:::"<<endl;
		cout<<"1.Estudiante."<<endl;
		cout<<"2.Profesor."<<endl;
		cout<<"3.Administrador."<<endl;
		cout<<"4.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;
		switch(opcion){
			case 1:
				bandera = PreguntarCodigo(txtEstudiante);
				if(bandera){
					DatosEstudiante(_codigo);
				}else{
					cout<<"\nVerifique Su Codigo -> :("<<endl;
				}
				
				break;
			case 2:
				bandera = PreguntarCodigo(txtProfesor);
				if(bandera){
					DatosProfesor(_codigo);
				}else{
					cout<<"\nVerifique Su Codigo -> :("<<endl;
				}
				break;
			case 3:
				bandera = VerificarAdmin(passwordAdmin);
				if(bandera){
					MenuAdministrador();
				}else{
					cout<<"\nVerifique Su Password -> :("<<endl;
				}
				break;
			case 4:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(opcion != 4);
	
	return 0;
}
