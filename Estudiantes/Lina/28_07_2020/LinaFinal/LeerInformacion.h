#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream


using namespace std;// estandar de c++ std::cout

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
