#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream


using namespace std;// estandar de c++ std::cout


void LeerAlumnosMaterias(char _txt[]){
	system("cls");
	ifstream archivo;
	string texto;
	string codMateria="";
	
	archivo.open(_txt,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	cout<<"\t:::LISTADO ESTUDIANTES:::"<<endl;
	cout<<"Ingrese el Cod. Materia: ";
	cin>>codMateria;
	
	codMateria = "Codigo:            "+codMateria;
	
	while(!archivo.eof()){
		getline(archivo,texto);//codigo
		if(codMateria==texto){
			getline(archivo,texto);//nombre materia
			getline(archivo,texto);//creditos
			getline(archivo,texto);//profesor
			getline(archivo,texto);//primer estudiante
			string temporal = "Codigo Estudiante: ";
			while(temporal=="Codigo Estudiante: "){
				temporal="";
				cout<<texto<<endl;
				getline(archivo,texto);
				for(int i=0;i<19;i++){
					temporal += texto[i];
				}
			}
			break;
			
		}
	}
	archivo.close();
}

void LeerInformacion(char _txt[],int perfil){
	system("cls");
	ifstream archivo;
	string texto;
	
	archivo.open(_txt,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	if(perfil==1){
		cout<<"\t:::LEER ESTUDIANTE:::"<<endl;
	}
	
	if(perfil==2){
		cout<<"\t:::LEER PROFESOR:::"<<endl;
	}
	
	if(perfil==3){
		cout<<"\t:::LEER MATERIA:::"<<endl;
	}
	
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		cout<<texto<<endl;
	}
	cout<<endl;
	
	archivo.close();
}

void LeerFacultad(string _facultad,string _perfil){
	system("cls");
	ifstream archivo;
	string texto;
	
	archivo.open("Facultades.txt",ios::in);
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	string tempFacultad="";
	for(int i=0;i<3;i++){
		tempFacultad += toupper(_facultad[i]);
	}
	
	if(tempFacultad=="TEC"){
		if(_perfil=="EST"){
			cout<<"\t:::ESTUDIANTES DE LA FACULTAD DE TECNOLOGIA:::"<<endl;
		}
		if(_perfil=="PRO"){
			cout<<"\t:::PROFESORES DE LA FACULTAD DE TECNOLOGIA:::"<<endl;
		}
	}
	
	if(tempFacultad=="ING"){
		if(_perfil=="EST"){
			cout<<"\t:::ESTUDIANTES DE LA FACULTAD DE INGENIERIA:::"<<endl;
		}
		if(_perfil=="PRO"){
			cout<<"\t:::PROFESORES DE LA FACULTAD DE INGENIERIA:::"<<endl;
		}
	}
	
	if(tempFacultad=="ART"){
		if(_perfil=="EST"){
			cout<<"\t:::ESTUDIANTES DE LA FACULTAD DE ARTES:::"<<endl;
		}
		if(_perfil=="PRO"){
			cout<<"\t:::PROFESORES DE LA FACULTAD DE ARTES:::"<<endl;
		}
	}
	
	if(tempFacultad=="CIE"){
		if(_perfil=="EST"){
			cout<<"\t:::ESTUDIANTES DE LA FACULTAD DE CIENCIAS Y EDUCACION:::"<<endl;
		}
		if(_perfil=="PRO"){
			cout<<"\t:::PROFESORES DE LA FACULTAD DE CIENCIAS Y EDUCACION:::"<<endl;
		}
	}
	
	if(tempFacultad=="MED"){
		if(_perfil=="EST"){
			cout<<"\t:::ESTUDIANTES DE LA FACULTAD DE MEDIO AMBIENTE Y RECURSOS NATURALES:::"<<endl;
		}
		if(_perfil=="PRO"){
			cout<<"\t:::PROFESORES DE LA FACULTAD DE MEDIO AMBIENTE Y RECURSOS NATURALES:::"<<endl;
		}
	}
	
	while(!archivo.eof()){
		getline(archivo,texto);
		//archivo<<"CIE -> EST -> "<<_codigo<<" -> "<<_nombre<<endl;
		string fac = "";
		string per = "";
		string inf = "";
		
		for(int i=0;i<3;i++){
			fac += toupper(texto[i]);
		}
		
		for(int i=7;i<10;i++){
			per += toupper(texto[i]);
		}
		
		for(int i=14;i<texto.length();i++){
			inf += toupper(texto[i]);
		}
		
		if(fac == tempFacultad){
			if(per==_perfil){
				cout<<inf<<endl;
			}
			
		}
	}
	
	archivo.close();
}
