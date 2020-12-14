#include <iostream> // Entrada y salida de datos
#include <conio.h>
#include <stdlib.h>// system("pause")
#include <string.h>// cadenas carecteres
#include <fstream>//file para archivos

//		:::MIS LIBRERIAS:::
#include "MenuAdministrador.h"

using namespace std; // Estandar de c++ std::cout

//	:::VARIABLES GLOBALES:::
string passwordAdmin = "12345";

//		::::VERIFICAR PASSWORD:::
bool VerificarPassword (string password){
	system("cls");
	fflush(stdin);//borarr buffer
	string codigo;//guardar datos del usurio
	bool bandera;//retornar valor 
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

//	:::CREAR ARCHIVOS:::
void CrearArchivos(){
	ofstream archivo;//etiquetando una variable
	
	archivo.open("Estudiante.txt",ios::app);// nombre archivo, crear archivo en modo modificar
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	archivo.close();
	
	//:::TAREA 1::: -> Crear un archivo Profesores.txt
}




int main(int argc, char** argv) {
	
	CrearArchivos();//Funcion que crea los .txt
	int opcion;
	bool bandera;// recibir informacion
	do{
		cout<<"\t:::PAGINA DISTRITAL:::"<<endl;
		cout<<"1.Estudiante."<<endl;
		cout<<"2.Profesor."<<endl;
		cout<<"3.Administrador."<<endl;
		cout<<"4.Salir"<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;
		switch(opcion){
			case 3:
				bandera = VerificarPassword(passwordAdmin);
				if(bandera){
					MenuAdministrador();
				}else{
					
					cout<<"Verifique su password -> :("<<endl;
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
