
#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

//#include "FuncionesSistema.h"

using namespace std;// estandar de c++ std::cout

char txtProfesor[]="Profesores.txt";
char txtMateria[]="Materias.txt";
char txtEstudiante[]="Estudiantes.txt";
char txtFacultades[]="Facultades.txt";

string _profesor;//Guardar si el dato existe en el sistema
string _alumno;

//		:::MIS ESTRUCTURAS:::
struct Estudiante{
	string semestre;
	string codigo,nombre,sexo,carrera,facultad;
	string materia;
}estudiante;

struct Profesor{
	string codigo,nombre,sexo,facultad;
	string materia;
}profesor;

struct Materia{
	string codigo,nombre,creditos;
	float nota[3];
	float promedio;
	string codEstudiante;
	string codProfesor;
}materia;
//	:::AGREGAR NOTAS:::
void AddNota(char _txt[],string _codigo){
	ifstream archivo;
	string codigo;
	string texto;
	if(strcmp(_txt,txtEstudiante)==0){
		archivo.open(txtEstudiante,ios::in);//Abrimos en modo lectura
	}
	if(strcmp(_txt,txtProfesor)==0){
		archivo.open(txtProfesor,ios::in);//Abrimos en modo lectura
	}
	
	
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
	
	string dato = "Codigo:            "+_codigo;
	bool bandera = false;
	while(!archivo.eof()){
		getline(archivo,texto);//Codigo
		if(dato==texto){
			if(strcmp(_txt,txtEstudiante)==0){
				Temp<<texto<<endl;//Copiar en temp.txt e codigo
				getline(archivo,texto);//Nombre
				Temp<<texto<<endl;// Nombre en txt
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<texto<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<texto<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<texto<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<texto<<endl;
				Temp<<"Materia:           "<<materia.nombre<<" -> "<<"Profesor: "<<_profesor<<" -> Nota: "<<
					materia.nota[0]<<"|"<<materia.nota[1]<<"|"<<materia.nota[2]<<" -> Total: "<<
					materia.promedio<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				bandera = true;
			}
			if(strcmp(_txt,txtProfesor)==0){//aqui voy
				Temp<<texto<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<texto<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<texto<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				Temp<<texto<<endl;
				Temp<<"Materia:           "<<materia.nombre<<" -> Cod. Materia: "<<materia.codigo<<endl;
				getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
				bandera = true;
			}
		}else{
			Temp<<texto<<endl;
		}
	}
	
	archivo.close();
	Temp.close();
		
	if(bandera){
		remove(_txt);
		rename("Temp.txt",_txt);	
	}else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el sistema -> :("<<endl;
		remove("Temp.txt");
	}
	
}


//	:::CREAR INFORMACION:::
//____________________________________________________________________________________
bool PedirDatos(int perfil){
	fflush(stdin);
	bool bandera;
	if(perfil==1){//Estudiante
		cout<<"\nDigite el Codigo: ";
		getline(cin,estudiante.codigo);
		bandera = PreguntarCodigo(txtEstudiante,estudiante.codigo);
		if(!bandera){
			cout<<"Digite el Nombre: ";
			getline(cin,estudiante.nombre);
			cout<<"Digite el Sexo: ";
			getline(cin,estudiante.sexo);
			cout<<"Digite la Carrera: ";
			getline(cin,estudiante.carrera);
			cout<<"Digite el Semestre: ";
			getline(cin,estudiante.semestre);
			fflush(stdin);
			
			//Add Información
			bool banFacultad = true;
			while(banFacultad){
				cout<<"Digite La Facultad: ";
				getline(cin,estudiante.facultad);
				banFacultad = GuardarFacultad("Estudiante",estudiante.facultad,estudiante.nombre,estudiante.codigo);
			}
			
			
			estudiante.materia = "NO REGISTRADA";
			return true;
		}else{
			cout<<endl<<estudiante.codigo<<endl;
			cout<<"\nEse Codigo YA EXISTE en el Sistema -> :("<<endl<<endl;
			return false;
		}	
	}
	if(perfil==2){//Profesor
		cout<<"\nDigite el Codigo: ";
		getline(cin,profesor.codigo);
		bandera = PreguntarCodigo(txtProfesor,profesor.codigo);
		if(!bandera){
			cout<<"Digite el Nombre: ";
			getline(cin,profesor.nombre);
			cout<<"Digite el Sexo: ";
			getline(cin,profesor.sexo);
			
			//Add Información
			bool banFacultad = true;
			while(banFacultad){
				cout<<"Digite La Facultad: ";
				getline(cin,profesor.facultad);
				banFacultad = GuardarFacultad("Profesor",profesor.facultad,profesor.nombre,profesor.codigo);
			}
			
			
			profesor.materia = "NO REGISTRADA";	
			return true;
		}else{
			cout<<endl<<profesor.codigo<<endl;
			cout<<"\nEse Codigo YA EXISTE en el Sistema -> :("<<endl<<endl;
			return false;
		}
		
	}
	
	//		:::DATOS DE LA MATERIA:::
	
	if(perfil==3){//Materia
		cout<<"\nDigite el Codigo: ";
		getline(cin,materia.codigo);
		bandera = PreguntarCodigo(txtMateria,materia.codigo);
		if(!bandera){
			cout<<"Digite el Nombre: ";
			getline(cin,materia.nombre);
			cout<<"Digite el # Creditos: ";
			getline(cin,materia.creditos);
			cout<<"Digite el Codigo Profesor: ";
			getline(cin,materia.codProfesor);
			return true;
		}else{
			cout<<endl<<materia.codigo<<endl;
			cout<<"\nEse Codigo YA EXISTE en el Sistema -> :("<<endl<<endl;
			return false;
		}
		
	}

		
}
void CrearInformacion(char _texto[],int perfil){
	ofstream archivo; //o->out etiquitar como int variable = 5;
	archivo.open(_texto,ios::app); // abrimos el archivo en modo a?adir
	bool bandera;
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	char rpt;
	do{	
		system("cls");
		fflush(stdin);
		if(perfil==1){
			cout<<"\t:::CREAR ESTUDIANTE:::"<<endl;
			bandera = PedirDatos(perfil);
			if(bandera){
				archivo<<"\nCodigo:            "<<estudiante.codigo<<endl;
				archivo<<"Nombre:            "<<estudiante.nombre<<endl;
				archivo<<"Sexo:              "<<estudiante.sexo<<endl;
				archivo<<"Carrera:           "<<estudiante.carrera<<endl;
				archivo<<"Semestre:          "<<estudiante.semestre<<endl;
				archivo<<"Facultad:          "<<estudiante.facultad<<endl;
				fflush(stdin);
				archivo<<"Materia:           "<<estudiante.materia<<endl;
			}
			
		}
		if(perfil==2){
			cout<<"\t:::CREAR PROFESOR:::"<<endl;
			bandera = PedirDatos(perfil);
			if(bandera){
				archivo<<"\nCodigo:            "<<profesor.codigo<<endl;
				archivo<<"Nombre:            "<<profesor.nombre<<endl;
				archivo<<"Sexo:              "<<profesor.sexo<<endl;
				archivo<<"Facultad:          "<<profesor.facultad<<endl;
				fflush(stdin);
				archivo<<"Materia:           "<<profesor.materia<<endl;
			}
		}
		
		//	:::CREAR MATERIA:::
		if(perfil==3){
			cout<<"\t:::CREAR MATERIA:::"<<endl;
			bandera = PedirDatos(perfil);
			if(bandera){
				bool PreguntaProfesor = PreguntarCodigo(txtProfesor,materia.codProfesor);
				_profesor = NOMBRE;
				if(PreguntaProfesor){
					archivo<<"Codigo:            "<<materia.codigo<<endl;
					archivo<<"Nombre:            "<<materia.nombre<<endl;
					archivo<<"Creditos           "<<materia.creditos<<endl;
					fflush(stdin);
					archivo<<"Codigo Profesor:   "<<materia.codProfesor<<" -> "<<_profesor<<endl;
					AddNota(txtProfesor,materia.codProfesor);
				}
				if(PreguntaProfesor){
				char rpt;//->Variable que manifesta que tantas materias va ingresar
				do{
					fflush(stdin);
					cout<<"Digite el Codigo Estudiante: ";
					getline(cin,materia.codEstudiante);
					bool preguntaEstudiante = PreguntarCodigo(txtEstudiante,materia.codEstudiante);
					_alumno = NOMBRE;
					if(preguntaEstudiante){
						materia.nota[0] = 0.0;
						materia.nota[1] = 0.0;
						materia.nota[2] = 0.0;
						materia.promedio = (materia.nota[0]+materia.nota[1]+materia.nota[2])/3.0;
						archivo<<"Codigo Estudiante: "<<materia.codEstudiante<<" -> "<<
							_alumno<<" -> Nota: "<<materia.nota[0]<<"|"<<materia.nota[1]<<"|"<<
							materia.nota[2]<<" -> Total: "<<materia.promedio<<endl;
						AddNota(txtEstudiante,materia.codEstudiante);
					}else{
						cout<<"\nEl Codigo del Estudiante NO Existe"<<endl;
						break;
					}	
					cout<<"\nDesea crear AGREGAR otro Codigo(s/n): ";
					cin>>rpt;
		
				}while(rpt == 's' || rpt == 'S');
			}else{
				cout<<"\nEl Codigo del Profesor NO Existe"<<endl;
				break;
			}
		}
			
		}
		
		
		cout<<"\nDesea crear otro DATO(s/n): ";
		cin>>rpt;
		
	}while(rpt == 'S' || rpt == 's');
	
	archivo.close();//Cerramos el archivo
	
}
//__________________________________________________________________________________________

