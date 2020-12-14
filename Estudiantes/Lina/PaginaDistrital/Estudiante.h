#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la función getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream


using namespace std;// estandar de c++ std::cout



void DatosEstudiante(string _codigo){
	system("cls");
	ifstream archivo;
	string texto;
	
	
	archivo.open(txtEstudiante,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	_codigo = "Codigo:     "+_codigo;
	cout<<"\t:::BIENVENIDO:::"<<endl<<endl;
	while(!archivo.eof()){
		getline(archivo,texto);
		if(_codigo==texto){
			cout<<texto<<endl;
			getline(archivo,texto);
			cout<<texto<<endl;
			getline(archivo,texto);
			cout<<texto<<endl;
			getline(archivo,texto);
			cout<<texto<<endl;
			getline(archivo,texto);
			cout<<texto<<endl;
			getline(archivo,texto);
			cout<<texto<<endl;
			getline(archivo,texto);
			cout<<texto<<endl;
		}
	}
	cout<<endl;
	
	archivo.close();
}
