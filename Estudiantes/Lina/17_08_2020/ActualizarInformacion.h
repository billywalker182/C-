#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

#include "EliminarInformacion.h"

using namespace std;// estandar de c++ std::cout

//		:::MIS ESTRUCTURAS:::
/*struct Estudiante{
	string semestre;
	string codigo,nombre,sexo,carrera,facultad;
	string materia;
}estudiante;

struct Profesor{
	string codigo,nombre,sexo,facultad;
	string materia;
}profesor;*/

void PedirDatosA(int perfil){
	fflush(stdin);
	if(perfil==1){
		cout<<"\nDigite el Codigo: ";
		getline(cin,estudiante.codigo);
		cout<<"Digite el Nombre: ";
		getline(cin,estudiante.nombre);
		cout<<"Digite el Sexo: ";
		getline(cin,estudiante.sexo);
		cout<<"Digite la Carrera: ";
		getline(cin,estudiante.carrera);
		cout<<"Digite el Semestre: ";
		getline(cin,estudiante.semestre);
		fflush(stdin);
		
		bool bandFacultad = true;
		while(bandFacultad){
			cout<<"Digite La Facultad: ";
			getline(cin,estudiante.facultad);
			bandFacultad = GuardarFacultad("Estudiante",estudiante.facultad,estudiante.nombre,estudiante.codigo);
		}
		
		estudiante.materia = "NO REGISTRADA";	
	}
	if(perfil==2){
		cout<<"\nDigite el Codigo: ";
		getline(cin,profesor.codigo);
		cout<<"Digite el Nombre: ";
		getline(cin,profesor.nombre);
		cout<<"Digite el Sexo: ";
		getline(cin,profesor.sexo);
		
		//Add Informacion facultad
			
		bool bandFacultad = true;
		while(bandFacultad){
			cout<<"Digite La Facultad: ";
			getline(cin,profesor.facultad);
			bandFacultad = GuardarFacultad("Profesor",profesor.facultad,profesor.nombre,profesor.codigo);
		}
		
		profesor.materia = "NO REGISTRADA";		
	}
}

void ActualizarInformacion(char _text[],int perfil){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open(_text,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ofstream Temp;
	Temp.open("Temp1.txt",ios::out);//Abrimos en modo lectura
	if(Temp.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	bool encontrado = false;
	
	
	cout<<"Ingrese el Codigo Actualizar: ";
	getline(cin,codigo);
	EliminarFacultad(codigo);
	
	string dato = "Codigo:            "+codigo;
	bool bandera = false;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		if(dato==texto){
			if(perfil==1){
				cout<<"\n\t:::ACTUALIZAR ESTUDIANTE:::"<<endl<<endl;
				PedirDatosA(perfil);
				Temp<<"Codigo:            "<<estudiante.codigo<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<"Nombre:            "<<estudiante.nombre<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<"Sexo:              "<<estudiante.sexo<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<"Carrera:           "<<estudiante.carrera<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<"Semestre:          "<<estudiante.semestre<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<"Facultad:          "<<estudiante.facultad<<endl;
			}
			if(perfil==2){
				cout<<"\n\t:::ACTUALIZAR PROFESOR:::"<<endl<<endl;
				PedirDatosA(perfil);
				Temp<<"Codigo:            "<<profesor.codigo<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<"Nombre:            "<<profesor.nombre<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<"Sexo:              "<<profesor.sexo<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<"Facultad:          "<<profesor.facultad<<endl;
			}
			if(perfil==3){
				archivo.close();
				EliminarMateria(codigo);
				CrearInformacion(txtMateria,perfil);
				break;
			}
			bandera = true;
		}else{
			Temp<<texto<<endl;
		}
	}
	
	Temp.close();
	archivo.close();
	
	if(bandera){
		remove(_text);
		rename("Temp1.txt",_text);
	
		cout<<"\nSE HA ACTUALIZADO SU REGISTRO"<<endl;
	}else{
		if(perfil==3){
			cout<<"SE HA ACTUALIZADO SU REGISTRO"<<endl;
			remove("Temp1.txt");
		}
		else{
			cout<<"\n"<<dato;
			cout<<"\n\nNo existe en el sistema -> :("<<endl;
			remove("Temp.txt");
		}
		
	}	
	
}
