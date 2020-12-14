#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci?n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream

using namespace std;// estandar de c++ std::cout

string NOMBRE;
string _Profesor,_Materia;

//----------------------------------------
//	:::FACULTADES PARA ESTUDIANTES:::

/*struct TecnologiaEst{
	string NomEst,CodEst;
	string NomProfe,CodProfe;
}tecnologiaEst;

struct IngenieriaEst{
	string NomEst,CodEst;
	string NomProfe,CodProfe;
}ingenieriaEst;

struct ArtesEst{
	string NomEst,CodEst;
	string NomProfe,CodProfe;
}artesEst;

struct CienciaEducacionEst{
	string NomEst,CodEst;
	string NomProfe,CodProfe;
}cienciaEducacionEst;

struct MedioAmbienteRecursosNaturalesEst{
	string NomEst,CodEst;
	string NomProfe,CodProfe;
}medioAmbienteRecursosNaturalesEst;*/
//------------------------------------------------


//		:::CREAR POR PRIMERA VEZ ARCHIVO:::
void CrearArchivo(char _txt[]){
	
	//		:::CREAR ARCHIVO:::
	ofstream archivo; //o->out etiquitar como int variable = 5;
	archivo.open(_txt,ios::app); // abriendo el archivo
	
	//		:::VERIFICAR SI EL ARCHIVO SE CREO:::
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	//:::CERRAR EL ARCHIVO
	archivo.close();
}

//	:::PREGUNTAR SI UN CODIGO EXISTE:::
bool PreguntarCodigo(char _txt[],string _codigo){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string texto;
	
	archivo.open(_txt,ios::in);//Abrimos en modo lectura
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
 	string dato = "Codigo:            "+_codigo;
 	
	bool bandera;
	NOMBRE="";
	while(!archivo.eof()){
		getline(archivo,texto);
		if(dato==texto){
			getline(archivo,texto);
			for(int i=19;i<texto.length();i++){
        		NOMBRE += texto[i];
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

void Leer(char _txt[],string _codigo ){
	system("cls");
	ifstream archivo;
	string texto;
	
	archivo.open(_txt,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	_codigo = "Codigo:            "+_codigo;
	

	cout<<"\t:::BIENVENIDO:::"<<endl<<endl;
	if(strcmp(_txt,"Estudiantes.txt")==0){
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
	}
	if(strcmp(_txt,"Profesores.txt")==0){
		_Profesor ="";
		while(!archivo.eof()){
			getline(archivo,texto);
			if(_codigo==texto){
				cout<<texto<<endl;
				getline(archivo,texto);
				for(int i=19;i<texto.length();i++){
        			_Profesor += texto[i];
    			}
				cout<<texto<<endl;
				getline(archivo,texto);
				cout<<texto<<endl;
				getline(archivo,texto);
				cout<<texto<<endl;
				getline(archivo,texto);
				cout<<texto<<endl;
			}
		}
	}
	if(strcmp(_txt,"Materias.txt")==0){
		_Materia ="";
		while(!archivo.eof()){
			getline(archivo,texto);
			if(_codigo==texto){
				cout<<texto<<endl;
				getline(archivo,texto);
				for(int i=19;i<texto.length();i++){
        			_Materia += texto[i];
    			}
				cout<<texto<<endl;
				getline(archivo,texto);
				cout<<texto<<endl;
				getline(archivo,texto);
				cout<<texto<<endl;
				getline(archivo,texto);
				cout<<texto<<endl;
				//AGREGAR ESTUDIANTES DE MAS
				getline(archivo,texto);
				cout<<texto<<endl;
				getline(archivo,texto);
				cout<<texto<<endl;
			}
		}
	}
	
	cout<<endl;
	
	archivo.close();
}


//Guardar facultad

bool GuardarFacultad(string _perfil,string _facultad,string _nombre,string _codigo){
	string tempfacultad = "";
	ofstream archivo; //o->out etiquitar como int variable = 5;
	archivo.open("Facultades.txt",ios::app); // abrimos el archivo en modo a?adir
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	for(int i=0;i<3;i++){
        	tempfacultad += toupper(_facultad[i]);
    	}
    	//cout<<tempfacultad<<endl;
	if(tempfacultad=="TEC"){
		if(_perfil=="Estudiante"){
			archivo<<"TEC -> "<<"EST -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad
		}
		if(_perfil=="Profesor"){
			archivo<<"TEC -> "<<"PRO -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad
		}	
	}
	else if(tempfacultad=="ING"){
		if(_perfil=="Estudiante"){
			archivo<<"ING -> "<<"EST -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad	
		}
		if(_perfil=="Profesor"){
			archivo<<"ING -> "<<"PRO -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad	
		}
			
	}
	else if(tempfacultad=="ART"){
		if(_perfil=="Estudiante"){
			archivo<<"ART -> "<<"EST -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad
		}
		if(_perfil=="Profesor"){
			archivo<<"ART -> "<<"PRO -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad
		}
			
	}
	else if(tempfacultad=="CIE"){
		if(_perfil=="Estudiante"){
			archivo<<"CIE -> "<<"EST -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad
		}
		if(_perfil=="Profesor"){
			archivo<<"CIE -> "<<"PRO -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad
		}
			
	}
	else if(tempfacultad=="MED"){
		if(_perfil=="Estudiante"){
			archivo<<"MED -> "<<"EST -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad
		}
		if(_perfil=="Profesor"){
			archivo<<"MED -> "<<"PRO -> "<<_codigo<<" -> "<<_nombre<<endl;
			return false;//Para romper el while que pregunta la facultad
		}
		
	}
	else{
			return true;//Para seguir preguntado e ingrese una facultad bien
	}					
	
	//return true;	
}


