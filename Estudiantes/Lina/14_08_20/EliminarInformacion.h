#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

//#include "ActualizarInformacion.h"

using namespace std;// estandar de c++ std::cout

void EliminarDatosUsuario(string _materia,char _file[]){
	ifstream archivo;
	string codigo;
	string texto;
	archivo.open(_file,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ofstream Temp;
	Temp.open("Temp2.txt",ios::out);//Abrimos en modo lectura
	if(Temp.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}


	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		string temporal="";
		for(int i = 19;i<texto.length();i++){
			if(texto[i] != ' '){
				temporal += texto[i]; 
			}
			else{
				break;
			}	
		}
		if(_materia==temporal){
			Temp<<"Materia:           "<<"NO REGISTRADA"<<endl;
			
		}else{
			Temp<<texto<<endl;
		}	
	}	

	Temp.close();
	archivo.close();
	
	remove(_file);
	rename("Temp2.txt",_file);
	
}


void EliminarMateria(string _codigo){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open("Materias.txt",ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ofstream Temp;
	Temp.open("Temp3.txt",ios::out);//Abrimos en modo lectura
	if(Temp.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	_codigo = "Codigo:            "+_codigo;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		if(_codigo==texto){
			getline(archivo,texto);//Nombre
			string Materia = "";
			for(int i = 19;i<texto.length();i++){
				Materia += texto[i]; 
			}
			getline(archivo,texto);//Creditos
			getline(archivo,texto);//CodProfsor
			EliminarDatosUsuario(Materia,txtProfesor);
			getline(archivo,texto);//primer estudiante
				
			string temporal="Codigo Estudiante: ";
			while(temporal=="Codigo Estudiante: "){
				temporal="";
				EliminarDatosUsuario(Materia,txtEstudiante);
				getline(archivo,texto);//primer estudiante
				for(int i = 0;i<19;i++){
					temporal += texto[i]; 
				}
			}
		}else{
			Temp<<texto<<endl;
		}
		
					
	}
	
	Temp.close();
	archivo.close();
	remove("Materias.txt");
	rename("Temp3.txt","Materias.txt");
	
}


void EliminarFacultad(string _codigo,string _perfil){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open("Facultades.txt",ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ofstream Temp;
	Temp.open("Temp4.txt",ios::out);//Abrimos en modo lectura
	if(Temp.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		string cod = "";
		for(int i=14;i<17;i++){//Indicar de cuanto es el codigo
			cod += toupper(texto[i]);
		}
		if(_codigo!=cod){
			Temp<<texto<<endl;
		}
	}
	
	Temp.close();
	archivo.close();
	remove("Facultades.txt");
	rename("Temp4.txt","Facultades.txt");
	
}





void EliminarInformacion(char _txt[],int perfil){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open(_txt,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ofstream Temp;
	Temp.open("Temp.txt",ios::out);//Abrimos en modo lectura
	if(Temp.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	//bool encontrado = true;
	
	
	cout<<"Ingrese el Codigo a Eliminar: ";
	getline(cin,codigo);
	string dato = "Codigo:            "+codigo;
	bool bandera = false;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		if(dato==texto){
			if(perfil==1){
				getline(archivo,texto);//Nombre
				getline(archivo,texto);//Sexo
				getline(archivo,texto);//carrera
				getline(archivo,texto);//semestre
				getline(archivo,texto);//facultad
				EliminarFacultad(codigo,"EST");
				getline(archivo,texto);//materia
				getline(archivo,texto);//materia
			}
			if(perfil==2){
				getline(archivo,texto);//Nombre
				getline(archivo,texto);//sEXO
				getline(archivo,texto);//fACULTAD
				getline(archivo,texto);//MATERIA
				EliminarFacultad(codigo,"PRO");
				getline(archivo,texto);//materia
			}
			bandera = true;
			
		}
		else{
			Temp<<texto<<endl;
		}
		
	}
	
	Temp.close();
	archivo.close();
	
	if(bandera){
		remove(_txt);
		rename("Temp.txt",_txt);
	
		cout<<"\nSE HA ELIMINADO SU REGISTRO"<<endl;
	}else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el sistema -> :("<<endl;
		remove("Temp.txt");
	}	
	
}




