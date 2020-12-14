#include <iostream> // entrada y salida de datos
#include <conio.h>	//para la función getch() para que no se cierren
#include <stdlib.h> // system("pause")
#include <string.h>	//cadenas de caracteres


using namespace std;// estandar de c++ std::cout

// 		:::VARIABLES GLOBALES:::
string claveAdmin[]={"12345678"};
string codigoEstudiante[255];
string NombreEstudiante[255];
string codigoProfesor[255];
string NombreProfesor[255];
string MateriaProfesor[255];
int ContadorEstudiante = 0;
int ContadorProfesor = 0;
int Posicion = 0;
//		:::FUNCIONES:::
//-------------------------------------------------------
//		:::MENU PRINCIPAL:::
void menuPrincipal(){
	cout<<endl;
	cout<<"\t:::PAGINA DISTRITAL:::"<<endl;
	cout<<"1.Estudiante."<<endl;
	cout<<"2.Profesor."<<endl;
	cout<<"3.Administrador."<<endl;
	cout<<"4.Salir"<<endl;
	cout<<"\nDigite Una Opcion de Menu: ";
}
void menuModificaciones(string TipoUsuario){
	cout<<endl;
	cout<<"\t:::CONFIGURACIONES: "<<TipoUsuario<<" :::"<<endl;
	cout<<"1.Crear."<<endl;
	cout<<"2.Leer."<<endl;
	cout<<"3.Actualizar."<<endl;
	cout<<"4.Eliminar"<<endl;
	cout<<"5.Salir"<<endl;
	cout<<"\nDigite Una Opcion de Menu: ";
}
//----------------------------------------------
//		:::FUNCION VERIFICAR CONTRASEÑA:::
bool VerificarPassword (string codigoSistema[]){
	string codigo;
	bool bandera;
	cout<<"Ingrese su Codigo: ";
	getline(cin,codigo);
	int numeroEstudiantes = sizeof(codigoSistema)/sizeof(codigoSistema[0]);
	for(int i=0;i<numeroEstudiantes;i++){
		if(codigoSistema[i]==codigo){
			bandera = true;
			Posicion = i;
			break;
		}
		else{
			bandera = false;
		}
	}
	return bandera;
}
//-----------------------------------------------------------------------
//----------------------------------------------------------------------
//		:::UNIDAD ESTUDIANTE:::
void Estudiante (){
	system("cls");
	fflush(stdin);
	bool bandera = VerificarPassword(codigoEstudiante);
	if(bandera){
		cout<<"\nBienvenido al sistema"<<endl;
	}
	else{
		cout<<"\nVerifique su Codigo Estudiantil y vuelva a intentar"<<endl;
	}
}
//-----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

//	:::UNIDAD DE ADMINISTRACIÓN:::
		//:::MENU UNIDADES:::
void menuUnidades(){
	cout<<"\t:::UNIDAD ADMINISTRATIVA:::"<<endl;
	cout<<"1.Estudiante."<<endl;
	cout<<"2.Profesor."<<endl;
	cout<<"3.Salir"<<endl;
	cout<<"\nDigite Una Opcion de Menu: ";
}

bool PosicionEliminado(string tempDato[]){
	int tamanio = sizeof(tempDato)/sizeof(tempDato[0]);
	bool bandera = false;
	for(int i=0;i<tamanio;i++){
		if(tempDato[i]=="ELIMINADO"){
			bandera = true;
			Posicion = i;
			break;
		}
		else{
			bandera = false;
		}
	}
	return bandera;
}

void Crear(string tipoUsuario){
	fflush(stdin);
	string nombre;
	string codigo;
	string materia;
	cout<<"\nIngrese el Nombre del "<<tipoUsuario<<": ";
	getline(cin,nombre);
	cout<<"Ingrese el Codigo del "<<tipoUsuario<<": ";
	getline(cin,codigo);
	if(tipoUsuario=="Estudiante"){
		int bandera = PosicionEliminado(NombreEstudiante);
		int aux = 0;
		if (bandera){
			aux = ContadorEstudiante;
			ContadorEstudiante = Posicion;
		}
		NombreEstudiante[ContadorEstudiante] = nombre;
		codigoEstudiante[ContadorEstudiante] = codigo;
		if(bandera){
			ContadorEstudiante = aux;
			Posicion = 0;
		}
		else{
			ContadorEstudiante ++;	
		}
		
	}else{
		cout<<"Ingrese la Materia del "<<tipoUsuario<<": ";
		getline(cin,materia);
		int bandera = PosicionEliminado(NombreProfesor);
		int aux1 = 0;
		if (bandera){
			aux1 = ContadorProfesor;
			ContadorProfesor = Posicion;
		}
		NombreProfesor[ContadorProfesor] = nombre;
		codigoProfesor[ContadorProfesor] = codigo;
		MateriaProfesor[ContadorProfesor] = materia;
		if(bandera){
			ContadorProfesor = aux1;
			Posicion = 0;
		}
		else{
			ContadorProfesor ++;	
		}
	}
}

void Leer(string tipoUsuario){
	fflush(stdin);
	if(tipoUsuario=="Estudiante"){
		cout<<endl;
		for(int i =0;i<255;i++){
			if(NombreEstudiante[i]!=""){
				cout<<"Nombre: "<<NombreEstudiante[i]<<" -> Codigo: "<<codigoEstudiante[i]<<endl;
			}else{
				break;
			}	
		}
	}else{
		cout<<endl;
		for(int i =0;i<255;i++){
			if(NombreProfesor[i]!=""){
				cout<<"Nombre: "<<NombreProfesor[i]<<" -> Codigo: "<<codigoProfesor[i]<<" -> Materia: "<<MateriaProfesor[i]<<endl;
			}else{
				break;
			}
		}	
	}
}

void Actualizar(string tipoUsuario){
	fflush(stdin);
	if(tipoUsuario=="Estudiante"){
		bool bandera = VerificarPassword(codigoEstudiante);
		if(bandera){
			int aux = ContadorEstudiante;
			ContadorEstudiante = Posicion;
			Crear("Estudiante");
			ContadorEstudiante = aux;
			Posicion = 0;
		}
		else{
			cout<<"\nVerifique el Codigo del estudiante y vuelva a intentar"<<endl;
		}
	}else{
		bool bandera = VerificarPassword(codigoProfesor);
		if(bandera){
			int aux = ContadorProfesor;
			ContadorProfesor = Posicion;
			Crear("Profesor");
			ContadorProfesor = aux;
			Posicion = 0;
		}
		else{
			cout<<"\nVerifique el Codigo del Profesor y vuelva a intentar"<<endl;
		}
	}
}

void Eliminar(string tipoUsuario){
	fflush(stdin);
	if(tipoUsuario=="Estudiante"){
		bool bandera = VerificarPassword(codigoEstudiante);
		if(bandera){
			int aux = ContadorEstudiante;
			ContadorEstudiante = Posicion;
			NombreEstudiante[ContadorEstudiante] = "ELIMINADO";
			codigoEstudiante[ContadorEstudiante] = "ELIMINADO";
			ContadorEstudiante = aux;
			Posicion = 0;
		}
		else{
			cout<<"\nVerifique el Codigo del estudiante y vuelva a intentar"<<endl;
		}
	}else{
		bool bandera = VerificarPassword(codigoProfesor);
		if(bandera){
			int aux = ContadorProfesor;
			ContadorProfesor = Posicion;
			NombreProfesor[ContadorProfesor] = "ELIMINADO";
			codigoProfesor[ContadorProfesor] = "ELIMINADO";
			MateriaProfesor[ContadorProfesor] = "ELIMINADO";
			ContadorProfesor = aux;
			Posicion = 0;
		}
		else{
			cout<<"\nVerifique el Codigo del Profesor y vuelva a intentar"<<endl;
		}
	}
}


void Usuario(string tipoUsuario){
	fflush(stdin);
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		system("cls");
		menuModificaciones(tipoUsuario);
		cin>>opcion;
		switch(opcion){
			case 1:
				Crear(tipoUsuario);
				break;
			case 2:
				Leer(tipoUsuario);
				break;
			case 3:
				Actualizar(tipoUsuario);
				break;
			case 4:
				Eliminar(tipoUsuario);
				break;
			case 5:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(opcion != 5);
}

void Administrador(){
	system("cls");
	fflush(stdin);
	bool bandera = VerificarPassword(claveAdmin);
	if(bandera){
		int opcion;// Variable local solo se podrá utilizar dentro de la función
		do{
			menuUnidades();
			cin>>opcion;
				switch(opcion){
					case 1:
						Usuario("Estudiante");
						break;
					case 2:
						Usuario("Profesor");
						break;
					case 3:
						break;
					default:cout<<"Se equivoco de opcion de Menu"<<endl;
				}
			cout<<endl;
			system("pause");
			system("cls");
		}while(opcion != 3);
	}
	else{
		cout<<"\nVerifique su Contraseña y vuelva a intentar"<<endl;
	}
}

//-------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------

int main(int argc, char *argv[]) {
	int opcion;// Variable local solo se podrá utilizar dentro de la función
	do{
		system("cls");
		menuPrincipal();
		cin>>opcion;
		switch(opcion){
			case 1:
				Estudiante();
				break;
			case 3:
				Administrador();
				break;
			case 4:
				break;
			default:cout<<"Se equivoco de opcion de Menu"<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(opcion != 4);
	return 0; // debe retornar un 0
}
