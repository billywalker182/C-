#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

using namespace std;// estandar de c++ std::cout

struct Estudiante{
	string codigo,nombre,sexo,carrera,facultad;
	int semestre;
}estudiante;

//		::::tarea 2 crear struct para Profesor::::

//	:::PEDIR DATOS ESTUDIANTE:::
void PedirDatosEstudiante(){
	cout<<"\nDigite el codigo: ";
	getline(cin,estudiante.codigo);
	cout<<"Digite el Nombre: ";
	getline(cin,estudiante.nombre);
	cout<<"Digite el Sexo: ";
	getline(cin,estudiante.sexo);
	cout<<"Digite la Carrera: ";
	getline(cin,estudiante.carrera);
	cout<<"Digite el Semestre: ";
	cin>>estudiante.semestre;// semestre entero
	fflush(stdin);//probar
	cout<<"Digite La Facultad: ";
	getline(cin,estudiante.facultad);
}
//	:::CREAR ESTUDIANTE:::
void CrearEstudiante(){
	ofstream archivo;
	
	archivo.open("Estudiante.txt",ios::app);//abrimor archivo modo modificar
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	char rpt;
	do{
		system("cls");
		fflush(stdin);
		cout<<"\t:::CREAR ESTUDIANTE:::"<<endl;
		PedirDatosEstudiante();// para que el usuario ingrese los datos
		
		archivo<<"\nCodigo:   "<<estudiante.codigo<<endl;
		archivo<<"Nombre:   "<<estudiante.nombre<<endl;
		archivo<<"Sexo:     "<<estudiante.sexo<<endl;
		archivo<<"Carrera:  "<<estudiante.carrera<<endl;
		archivo<<"Semestre: "<<estudiante.semestre<<endl;
		archivo<<"Facultad: "<<estudiante.facultad<<endl;
		
		cout<<"\nDesea crear otro contacto(s/n): ";
		cin>>rpt;
	}while(rpt == 'S' || rpt == 's');
	
	archivo.close();
}

//	:::CREAR PROFESOR:::
void LeerEstudiante(){
	system("cls");
	ifstream archivo;
	string texto;
	
	archivo.open("Estudiante.txt",ios::in);//abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	cout<<"\t:::LEER ESTUDIANTE:::"<<endl;
	while(!archivo.eof()){//Mientras no sea el final archivo
		getline(archivo,texto);//Copiame todo lo que encuentre archivo a texto, por  liena
		cout<<texto<<endl;
	}
	
	cout<<endl;
	
	archivo.close();
}

//	:::ACTUALIZAR ESTUDIANTE:::

void ActualizarEstudiante(){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;//eliminar todo por estudiante
	string texto;//guardar informacion del .txt
	
	archivo.open("Estudiante.txt",ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ofstream temp;
	temp.open("temp.txt",ios::out);//crear solo en el proceso
	
	if(temp.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	bool datoEncontrado = false;
	
	cout<<"\nIngrese el Codigo a Modificar: ";
	getline(cin,codigo);
	
	string dato = "Codigo:   "+codigo;
	
	bool bandera = false;
	
	
	
	while(!archivo.eof()){
		getline(archivo,texto);
		if(texto==dato){
			cout<<"\n\t:::ACTUALIZAR ESTUDIANTE:::"<<endl;
			PedirDatosEstudiante();
			temp<<"\nCodigo:   "<<estudiante.codigo<<endl;
			getline(archivo,texto);//Linea 1
			temp<<"Nombre:   "<<estudiante.nombre<<endl;
			getline(archivo,texto);//Linea 2
			temp<<"Sexo:     "<<estudiante.sexo<<endl;
			getline(archivo,texto);//Linea 3
			temp<<"Carrera:  "<<estudiante.carrera<<endl;
			getline(archivo,texto);//Linea 4
			temp<<"Semestre: "<<estudiante.semestre<<endl;
			getline(archivo,texto);//Linea 5
			temp<<"Facultad: "<<estudiante.facultad<<endl;
			bandera = true;
			
		}else{
			temp<<texto<<endl;
		}
	}
	
	temp.close();
	archivo.close();
	
	if(bandera){
		remove("Estudiante.txt");//eliminamos nuestro archivo txt
		rename("temp.txt","Estudiante.txt");
		cout<<"\nSE HA ACTUALIZADO SU REGISTRO"<<endl;
	}
	else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el Sistema -> :("<<endl;
		remove("temp.txt");
	}
}

void EliminarEstudiante(){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	
	archivo.open("Estudiante.txt",ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ofstream temp;
	temp.open("Temp.txt",ios::out);//Abrimos en modo lectura
	if(temp.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	//bool encontrado = false;
	
	
	cout<<"Ingrese el Codigo a Eliminar: ";
	getline(cin,codigo);
	string dato = "Codigo:   "+codigo;
	bool bandera = false;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		if(dato==texto){
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			bandera = true;
		}
		else{
			temp<<texto<<endl;
		}
		
	}
	
	temp.close();
	archivo.close();
	
	if(bandera){
		remove("Estudiante.txt");
		rename("Temp.txt","Estudiante.txt");
	
		cout<<"\nSE HA ELIMINADO SU REGISTRO"<<endl;
	}else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el sistema -> :("<<endl;
		remove("Temp.txt");
	}	
	
}


