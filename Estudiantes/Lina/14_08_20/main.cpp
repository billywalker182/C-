#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

#include "FuncionesSistema.h"
#include "Administrador.h"
#include "Profesor.h"


using namespace std;// estandar de c++ std::cout

//		:::NOMBRES DE LOS ARCHIVOS:::

//char txtProfesor[]="Profesores.txt";
///char txtMateria[]="Materias.txt";
//char txtEstudiante[]="Estudiantes.txt";

string codigoUsuario;//Guardar El codigo estudiante
string passwordAdmin = "12345";

//	:::MENU:::
void MenuUniversidadDistrital(){
	cout<<"\t:::PAGINA DISTRITAL:::"<<endl;
	cout<<"1.Estudiante."<<endl;
	cout<<"2.Profesor."<<endl;
	cout<<"3.Administrador."<<endl;
	cout<<"4.Salir"<<endl;
	cout<<"\nDigite Una Opcion de Menu: ";
}

//		:::VERIFICAR ADMIN:::
bool VerificarAdmin (string password){
	system("cls");
	fflush(stdin);
	string codigo;
	bool bandera;
	cout<<"\nIngrese su Codigo: ";
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

int main(int argc, char** argv) {
	//:::CREAR ARCHIVOS:::
	CrearArchivo(txtEstudiante);
	CrearArchivo(txtProfesor);
	CrearArchivo(txtMateria);
	CrearArchivo(txtFacultades);
	
	int opcion;
	bool bandera;
	
	do{
		MenuUniversidadDistrital();
		cin>>opcion;
		
		switch(opcion){
			case 1:
				system("cls");
				fflush(stdin);
				cout<<"\nIngrese Su Codigo: ";
				getline(cin,codigoUsuario);
				bandera = PreguntarCodigo(txtEstudiante,codigoUsuario);
				if(bandera){
					Leer(txtEstudiante,codigoUsuario);
				}
				else{
					cout<<"\nVerifique Su Codigo -> :("<<endl<<endl;
				}
				break;
			case 2:
				system("cls");
				fflush(stdin);
				cout<<"\nIngrese Su Codigo: ";
				getline(cin,codigoUsuario);
				bandera = PreguntarCodigo(txtProfesor,codigoUsuario);
				if(bandera){
					DatosProfesor(codigoUsuario);
				}
				else{
					cout<<"\nVerifique Su Codigo -> :("<<endl<<endl;
				}
				break;
			case 3:
				bandera = VerificarAdmin(passwordAdmin);
				if(bandera){
					Administrador();
				}else{
					cout<<"\nVerifique Su Password -> :("<<endl;
				}
				break;
			case 4:
				break;
			default:cout<<"\nSe equivoco de opcion de Menu"<<endl<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(opcion!=4);
	
	return 0;
}
