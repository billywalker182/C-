#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la función getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

using namespace std;// estandar de c++ std::cout
//------------------------------------------

struct Estudiante{
	string semestre;
	string codigo,nombre,sexo,carrera,facultad;
	string materia;
}estudiante;

//		:::PEDIR DATOS:::

void PedirDatos(){
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
	cout<<"Digite La Facultad: ";
	getline(cin,estudiante.facultad);
	estudiante.materia = "NO REGISTRADA";
		
}

//		:::CREAR ARCHIVOS:::
void CrearEstudiante(){
	ofstream archivo; //o->out etiquitar como int variable = 5;
	archivo.open("Estudiantes.txt",ios::app); // abrimos el archivo en modo añadir
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	char rpt;
	do{	
		system("cls");
		fflush(stdin);
		cout<<"\t:::CREAR ESTUDIANTE:::"<<endl;
		PedirDatos();
		
		archivo<<"Codigo:     "<<estudiante.codigo<<endl;
		archivo<<"Nombre:     "<<estudiante.nombre<<endl;
		archivo<<"Sexo:       "<<estudiante.sexo<<endl;
		archivo<<"Carrera:    "<<estudiante.carrera<<endl;
		archivo<<"Semestre:   "<<estudiante.semestre<<endl;
		archivo<<"Facultad:   "<<estudiante.facultad<<endl;
		fflush(stdin);
		archivo<<"Materia:    "<<estudiante.materia<<endl<<endl;
		
		cout<<"\nDesea crear otro contacto(s/n): ";
		cin>>rpt;
		
	}while(rpt == 'S' || rpt == 's');
	
	archivo.close();//Cerramos el archivo
	
}

void LeerEstudiante(){
	system("cls");
	ifstream archivo;
	string texto;
	
	archivo.open("Estudiantes.txt",ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	cout<<"\t:::LEER ESTUDIANTE:::"<<endl;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		cout<<texto<<endl;
	}
	cout<<endl;
	
	archivo.close();
}

void ActualizarEstudiante(){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open("Estudiantes.txt",ios::in);//Abrimos en modo lectura
	
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
			cout<<"\n\t:::ACTUALIZAR ESTUDIANTE:::"<<endl<<endl;
			PedirDatos();
			Temp<<"Codigo:     "<<estudiante.codigo<<endl;
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			Temp<<"Nombre:     "<<estudiante.nombre<<endl;
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			Temp<<"Sexo:       "<<estudiante.sexo<<endl;
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			Temp<<"Carrera:    "<<estudiante.carrera<<endl;
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			Temp<<"Semestre:   "<<estudiante.semestre<<endl;
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			Temp<<"Facultad:   "<<estudiante.facultad<<endl;
			bandera = true;
		}else{
			Temp<<texto<<endl;
		}
	}
	
	Temp.close();
	archivo.close();
	
	if(bandera){
		remove("Estudiantes.txt");
		rename("Temp.txt","Estudiantes.txt");
	
		cout<<"\nSE HA ACTUALIZADO SU REGISTRO"<<endl;
	}else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el sistema -> :("<<endl;
		remove("Temp.txt");
	}	
	
}

void EliminarEstudiante(){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open("Estudiantes.txt",ios::in);//Abrimos en modo lectura
	
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
			getline(archivo,texto);//Sexo
			getline(archivo,texto);//carrera
			getline(archivo,texto);//semestre
			getline(archivo,texto);//facultad
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
		remove("Estudiantes.txt");
		rename("Temp.txt","Estudiantes.txt");
	
		cout<<"\nSE HA ELIMINADO SU REGISTRO"<<endl;
	}else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el sistema -> :("<<endl;
		remove("Temp.txt");
	}	
	
}

