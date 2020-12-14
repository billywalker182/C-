#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la función getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

using namespace std;// estandar de c++ std::cout

string _profesor;//Guardar si el dato existe en el sistema
string _alumno;

//Textos
char txtEstudiante[]="Estudiantes.txt";
char txtProfesor[]="Profesores.txt";
char txtMateria[]="Materias.txt";

struct Materia{
	string codigo,nombre,creditos;
	float nota[3];
	float promedio;
	string codEstudiante;
	string codProfesor;
}materia;
//-----------------------------------------------------
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
	
	string dato = "Codigo:     "+_codigo;
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
				Temp<<"Materia:    "<<materia.nombre<<" -> "<<"Profesor: "<<_profesor<<" -> Nota: "<<
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
				Temp<<"Materia:    "<<materia.nombre<<" -> Cod. Materia: "<<materia.codigo<<endl;
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

//---------------------------------------------------
bool PreguntarCodigo(string _codigo,char _txt[]){
	ifstream archivo;
	string codigo;
	string texto;
	if(strcmp(_txt,txtEstudiante)==0){
        _alumno = "";
	}else{
		_profesor="";
	}
	archivo.open(_txt,ios::in);//Abrimos en modo lectura
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	
	string dato = "Codigo:     "+_codigo;
	bool bandera = false;
	while(!archivo.eof()){
		getline(archivo,texto);
		if(dato==texto){
			getline(archivo,texto);
			for(int i=12;i<texto.length();i++){
        		if(strcmp(_txt,txtEstudiante)==0){
        			_alumno += texto[i];
				}
				if(strcmp(_txt,txtProfesor)==0){
					_profesor += texto[i];
				}
    		}
			bandera = true;
		}
	}
	
	archivo.close();
	if(bandera){
		return true;
	}
	else{
		return false;
	}
}
//------------------------------------------------------------------------------
	PedirDatosM(){
		system("cls");
		fflush(stdin);
		cout<<"\t:::CREAR MATERIA:::"<<endl;
		cout<<"Digite el Codigo: ";
		getline(cin,materia.codigo);
		cout<<"Digite el Nombre: ";
		getline(cin,materia.nombre);
		cout<<"Digite el # Creditos: ";
		getline(cin,materia.creditos);
		cout<<"Digite el Codigo Profesor: ";
		getline(cin,materia.codProfesor);
	}
//------------------------------------------------------------------------------

CrearMateria(){
	//->Abrimos nuestro archivo materia en modo modificar
	ofstream archivo; //o->out etiquitar como int variable = 5;
	archivo.open(txtMateria,ios::app); // abrimos el archivo en modo a?adir
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	char rpt;//->Variable que manifesta que tantas materias va ingresar
	do{
		PedirDatosM();
		
		bool bandera = PreguntarCodigo(materia.codProfesor,txtProfesor);
		if(bandera){
			archivo<<"Codigo:            "<<materia.codigo<<endl;
			archivo<<"Nombre:            "<<materia.nombre<<endl;
			archivo<<"Creditos           "<<materia.creditos<<endl;
			fflush(stdin);
			archivo<<"Codigo Profesor:   "<<materia.codProfesor<<" -> "<<_profesor<<endl;
			AddNota(txtProfesor,materia.codProfesor);
		}
		if(bandera){
			char rpt;//->Variable que manifesta que tantas materias va ingresar
			do{
				fflush(stdin);
				cout<<"Digite el Codigo Estudiante: ";
				getline(cin,materia.codEstudiante);
				bandera = PreguntarCodigo(materia.codEstudiante,txtEstudiante);
				if(bandera){
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
		
		
		cout<<"\nDesea crear otra MATERIA(s/n): ";
		cin>>rpt;
		
	}while(rpt == 's' || rpt == 'S');
}

void LeerMateria(){
	system("cls");
	ifstream archivo;
	string texto;
	
	archivo.open(txtMateria,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	cout<<"\t:::LEER MATERIAS:::"<<endl;
	while(!archivo.eof()){//Mientras no sea el final del archivo
		getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
		cout<<texto<<endl;
	}
	cout<<endl;
	
	archivo.close();
}

void ActualizarMateria(){
	
}
