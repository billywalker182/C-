#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la función getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

using namespace std;// estandar de c++ std::cout

struct Profesor{
	string codigo,nombre,sexo,facultad;
	string materia;
}profesor;

//		:::PEDIR DATOS:::

void PedirDatosP(){
	cout<<"\nDigite el Codigo: ";
	getline(cin,profesor.codigo);
	cout<<"Digite el Nombre: ";
	getline(cin,profesor.nombre);
	cout<<"Digite el Sexo: ";
	getline(cin,profesor.sexo);
	cout<<"Digite La Facultad: ";
	getline(cin,profesor.facultad);
	profesor.materia = "NO REGISTRADA";
		
}

//		:::CREAR ARCHIVOS:::
void CrearProfesor(){
	ofstream archivo; //o->out etiquitar como int variable = 5;
	archivo.open("Profesores.txt",ios::app); // abrimos el archivo en modo añadir
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	char rpt;
	do{	
		system("cls");
		fflush(stdin);
		cout<<"\t:::CREAR PROFESOR:::"<<endl;
		PedirDatosP();
		
		archivo<<"Codigo:     "<<profesor.codigo<<endl;
		archivo<<"Nombre:     "<<profesor.nombre<<endl;
		archivo<<"Sexo:       "<<profesor.sexo<<endl;
		archivo<<"Facultad:   "<<profesor.facultad<<endl;
		fflush(stdin);
		archivo<<"Materia:    "<<profesor.materia<<endl<<endl;
		
		cout<<"\nDesea crear otro contacto(s/n): ";
		cin>>rpt;
		
	}while(rpt == 'S' || rpt == 's');
	
	archivo.close();//Cerramos el archivo
	
}

void LeerProfesor(){
	system("cls");
	ifstream archivo;
	string texto;
	
	archivo.open("Profesores.txt",ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	cout<<"\t:::LEER PROFESOR:::"<<endl;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		cout<<texto<<endl;
	}
	cout<<endl;
	
	archivo.close();
}

void ActualizarProfesor(){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open("Profesores.txt",ios::in);//Abrimos en modo lectura
	
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
	
	bool encontrado = false;
	
	
	cout<<"Ingrese el Codigo Actualizar: ";
	getline(cin,codigo);
	string dato = "Codigo:     "+codigo;
	bool bandera = false;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		if(dato==texto){
			cout<<"\n\t:::ACTUALIZAR PROFESOR:::"<<endl<<endl;
			PedirDatosP();
			Temp<<"Codigo:     "<<profesor.codigo<<endl;
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			Temp<<"Nombre:     "<<profesor.nombre<<endl;
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			Temp<<"Sexo:       "<<profesor.sexo<<endl;
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			Temp<<"Facultad:   "<<profesor.facultad<<endl;
			bandera = true;
		}else{
			Temp<<texto<<endl;
		}
	}
	
	Temp.close();
	archivo.close();
	
	if(bandera){
		remove("Profesores.txt");
		rename("Temp.txt","Profesores.txt");
	
		cout<<"\nSE HA ACTUALIZADO SU REGISTRO"<<endl;
	}else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el sistema -> :("<<endl;
		remove("Temp.txt");
	}	
	
}

void EliminarProfesor(){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open("Profesores.txt",ios::in);//Abrimos en modo lectura
	
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
	string dato = "Codigo:     "+codigo;
	bool bandera = false;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		if(dato==texto){
			getline(archivo,texto);//Nombre
			getline(archivo,texto);//facultad
			getline(archivo,texto);//materia
			getline(archivo,texto);//materia
			getline(archivo,texto);//materia
			//getline(archivo,texto);//materia
			bandera = true;
		}
		else{
			Temp<<texto<<endl;
		}
		
	}
	
	Temp.close();
	archivo.close();
	
	if(bandera){
		remove("Profesores.txt");
		rename("Temp.txt","Profesores.txt");
	
		cout<<"\nSE HA ELIMINADO SU REGISTRO"<<endl;
	}else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el sistema -> :("<<endl;
		remove("Temp.txt");
	}	
	
}

