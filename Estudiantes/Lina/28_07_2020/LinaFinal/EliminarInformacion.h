#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream



using namespace std;// estandar de c++ std::cout


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
				getline(archivo,texto);//materia
				getline(archivo,texto);//materia
			}
			if(perfil==2){
				getline(archivo,texto);//Nombre
				getline(archivo,texto);//facultad
				getline(archivo,texto);//materia
				getline(archivo,texto);//materia
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
