#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la funci�n getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres
#include <fstream> // file stream


using namespace std;// estandar de c++ std::cout

string _CodigoProfesor;
float nota[3];
float promedio;

string _Materia, _Profesor;

//	:::CAMBIAR NOTAS EN EL SISTEMA:::

void CambiarNotas(){
	system("cls");
	fflush(stdin);
	ifstream archivo;
	string codigo;
	string texto;
	string texto1;
	archivo.open(txtMateria,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ifstream archivo1;
	archivo1.open(txtEstudiante,ios::in);//Abrimos en modo lectura
	
	if(archivo1.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	ofstream Temp;
	Temp.open("Temp.txt",ios::out);//Abrimos en modo lectura
	if(Temp.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	bool bandera = false;
	string dato;
	char rpt;//->Variable que manifesta que tantas materias va ingresar
	//do{
		fflush(stdin);
		cout<<"Ingrese el Codigo Estudiante: ";
		getline(cin,codigo);
		dato = "Codigo Estudiante: "+codigo;
		//cout<<"\nEste es lo que voy a buscar"<<dato<<endl<<endl;
		while(!archivo.eof()){//Mientras no sea el final del archivo
			getline(archivo,texto);//copiame todo lo que encuentre archivo a texto por linea
			string temporal="";
			for(int i = 0;i<19;i++){
				temporal += texto[i]; 
			}
			temporal += codigo;
			//cout<<"\nMicadena formda: "<<temporal<<endl;
			if(dato==temporal){
				string dato1 = "Codigo:     "+codigo;
				
				//cout<<"\nMi dato: "<<dato1;
				while(!archivo1.eof()){//Mientras no sea el final del archivo
					fflush(stdin);
					getline(archivo1,texto1);//copiame todo lo que encuentre archivo a texto por linea
					//cout<<"\nMi texto: "<<texto1;
					if(dato1==texto1){
						//modificar nota
						Temp<<texto1<<endl;//Copiar en temp.txt e codigo
						getline(archivo1,texto1);//Nombre
						Temp<<texto1<<endl;// Nombre en txt
						getline(archivo1,texto1);//copiame todo lo que encuentre archivo a texto por linea
						Temp<<texto1<<endl;
						getline(archivo1,texto1);//copiame todo lo que encuentre archivo a texto por linea
						Temp<<texto1<<endl;
						getline(archivo1,texto1);//copiame todo lo que encuentre archivo a texto por linea
						Temp<<texto1<<endl;
						getline(archivo1,texto1);//copiame todo lo que encuentre archivo a texto por linea
						Temp<<texto1<<endl;
						//char nota[];
						cout<<"\nIngrese La Primer Nota: ";
						cin>>nota[0];
						cout<<"Ingrese La Segunda Nota: ";
						cin>>nota[1];
						cout<<"Ingrese La Tercer Nota: ";
						cin>>nota[2];
						promedio = (nota[0]+nota[1]+nota[2])/3;
						Temp<<"Materia:    "<<_Materia<<" -> "<<"Profesor: "<<_Profesor<<" -> Nota: "<<
							nota[0]<<"|"<<nota[1]<<"|"<<nota[2]<<" -> Total: "<<promedio<<endl;
						getline(archivo1,texto1);//copiame todo lo que encuentre archivo a texto por linea
						bandera = true;
					}else{
						Temp<<texto1<<endl;
					}
				}
			}		
			
		}	
		//cout<<"\nDesea Modificar Otro Codigo Estudiante(s/n): ";
		//cin>>rpt;	
	//}while(rpt == 's' || rpt == 'S');
	
	
	
	Temp.close();
	archivo.close();
	archivo1.close();
	
	
	if(bandera){
		remove(txtEstudiante);
		rename("Temp.txt",txtEstudiante);
	
		cout<<"\nSE HA ACTUALIZADO SU REGISTRO"<<endl;
	}else{
		cout<<"\n"<<dato;
		cout<<"\n\nNo existe en el sistema -> :("<<endl;
		remove("Temp.txt");
	}	
	
}





//-----------------------------------------------------
void LeerLaMateria(string _codigo){
	system("cls");
	ifstream archivo;
	string texto;
	
	
	archivo.open(txtMateria,ios::in);//Abrimos en modo lectura
	
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	
	_codigo = "Codigo:            "+_codigo;
	cout<<"\t:::MATERIA:::"<<endl<<endl;
	while(!archivo.eof()){
		getline(archivo,texto);
		if(_codigo==texto){
			cout<<texto<<endl;
			getline(archivo,texto);
			_Materia = texto;
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
	cout<<endl;
	
	archivo.close();
}

//---------------------------------------------------------------
void LecturaProfesor(string _codigo){
	system("cls");
	ifstream archivo;
	string texto;
	
	
	archivo.open(txtProfesor,ios::in);//Abrimos en modo lectura
	
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
			_Profesor = texto;
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
//---------------------------------------------------------------------------
bool PreguntarCodigoP(char _txt[],string _codMat){
	system("cls");
	LecturaProfesor(_CodigoProfesor);
	fflush(stdin);
	ifstream archivo;
	string texto;
	string _codigo;
	
	archivo.open(_txt,ios::in);//Abrimos en modo lectura
	if(archivo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
	}
	string dato = "Codigo:            "+_codMat;
	//cout<<"Ingrese Su Codigo: ";
	//getline(cin,_codigo);
	bool bandera = false;
	while(!archivo.eof()){
		getline(archivo,texto);
		if(dato==texto){
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
//--------------------------------------------------------------------
void ModificarNotas(){
	fflush(stdin);
	system("cls");
	string codMateria;
	LecturaProfesor(_CodigoProfesor);
	
	cout<<"Ingrese el Cod. Materia: ";
	getline(cin,codMateria);
	bool bandera = PreguntarCodigoP(txtMateria,codMateria);
	if(bandera){
		//LeerLaMateria(codMateria);
		CambiarNotas();
	}else{
		cout<<"\nEl Cod. Materia NO EXISTE"<<endl<<endl;
	}
	
}
//------------------------------------------------------------------------------
void DatosProfesor(string _codigo){
	_CodigoProfesor = _codigo;
	int opcion;// Variable local solo se podr� utilizar dentro de la funci�n
	do{
		fflush(stdin);
		system("cls");
		LecturaProfesor(_CodigoProfesor);
		cout<<"\t:::MENU PROFESOR:::"<<endl;
		cout<<"1.Modficar Notas."<<endl;
		cout<<"2.Salir."<<endl;
		cout<<"\nDigite Una Opcion de Menu: ";
		cin>>opcion;

		switch(opcion){
			case 1:
				ModificarNotas();
				system("pause");
				break;
			case 2:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
	}while(opcion != 2);
	
}
//-------------------------------------------------------------

