#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<fstream>

using namespace std;
//		:::VARIABLES GLOBALES:::

struct Usuario{
	char nombre[20];
	char apellido[20];
	char cedula[20];
	char celular[20];
	int edad;
	char Sexo;
}usuario;

char texto[30]="nomeimportaelnombre.txt";


//		:::LEER DATOS:::

void LeerDatos(char _texto[]){
	system("cls");
	fflush(stdin);
	char texto[255];
	
	ifstream archivo;
	archivo.open(_texto,ios::in);
	
	if(archivo.fail()){
		cout<<"\nNo se Pudo Leer el Archivo -> :( "<<endl<<endl;
	}
	
	cout<<"\t:::LEER USUARIO:::"<<endl<<endl;
	
	while(!archivo.eof()){
		archivo.getline(texto,255,'\n');
		cout<<texto<<endl; 
	}
	
	archivo.close();
}

//		:::BUSCAR INFORMACION:::
void BuscarInformacion(char _texto[]){
	system("cls");
	fflush(stdin);
	
	ifstream archivo;
	char texto[255];
	
	archivo.open(_texto,ios::in);
	
	if(archivo.fail()){
		cout<<"\nNo se Pudo Leer el Archivo"<<endl<<endl;
	}
	
	char celular[20];
	cout<<"\nIngrese El Numero Celular: ";
	cin.getline(celular,15,'\n');
	
	char dato[] = "Celular:  ";
	strcat(dato,celular);
	
	bool bandera = false;
	
	while(!archivo.eof()){
		archivo.getline(texto,255,'\n');
		//cout<<"\nDato del Documento: "<<texto<<endl;
		if(strcmp(texto,dato)==0){
			bandera = true;
		}
	}
	
	archivo.close();
	
	if(bandera){
		LeerDatos(_texto);
	}else{
		cout<<"\nEl Celular Ingresado NO existe en el Sistema -> :( "<<endl<<endl;
	}
	
}

//		:::GUARDAR INFORMACION:::

void GuardarDatos(char _texto[]){
	system("cls");
	fflush(stdin);
	
	ofstream archivo;
	archivo.open(_texto,ios::app);
	
	if(archivo.fail()){
		cout<<"\n No se Pudo Abrir el Atchivo"<<endl<<endl;
	}
	
	char rpt;
	do{
		system("cls");
		fflush(stdin);
		cout<<"\t:::CREAR USUARIO:::"<<endl<<endl;
		cout<<"Ingrese Nombre: ";
		cin.getline(usuario.nombre,20,'\n');
		cout<<"Ingrese Apellido: ";
		cin.getline(usuario.apellido,20,'\n');
		cout<<"Ingrese Cedula: ";
		cin.getline(usuario.cedula,20,'\n');
		cout<<"Ingrese Celular: ";
		cin.getline(usuario.celular,15,'\n');
		cout<<"Ingrese Edad: ";
		cin>>usuario.edad;
		cout<<"Ingrese Sexo(M/F): ";
		cin>>usuario.Sexo;
		
		archivo<<"Nombre:   "<<usuario.nombre<<endl;
		archivo<<"Apellido: "<<usuario.apellido<<endl;
		archivo<<"Cedula:   "<<usuario.cedula<<endl;
		archivo<<"Celular:  "<<usuario.celular<<endl;
		archivo<<"Edad:     "<<usuario.edad<<endl;
		archivo<<"Sexo:     "<<usuario.Sexo<<endl<<endl;
		
		cout<<"\nDesea Crear Otro Usuario(S/N): ";
		cin>>rpt;
		
	}while(rpt =='S' || rpt =='s');
	
	archivo.close();
}

//		:::CREAR ARCHIVOS:::
void CrearArchivo(){
	system("cls");
	fflush(stdin);
	cout<<"\nIngrese el Nombre como desea Guardar el Archivo: ";
	cin.getline(texto,20,'\n');//Guardamos Una cadena de caracteres despues del Enter
	
	strcat(texto,".txt");//Concatenamos o Unimos Una cadena de Caracteres
	//cout<<"\n"<<texto<<endl;
	
	ofstream archivo;//etiquetamos una variable
	archivo.open(texto,ios::out);//Creamos Archivo
	
	if(archivo.fail()){
		cout<<"\nNo se pudo crear el archivo"<<endl;
	}
	
	archivo.close();	
	
}

int main(){
	int opcion;
	do{
		system("cls");
		cout<<"\t:::MENU ARCHIVOS:::"<<endl<<endl;
		cout<<"1.Crear Archivo"<<endl;
		cout<<"2.Guardar Datos"<<endl;
		cout<<"3.Buscar Informacion"<<endl;
		cout<<"4.Salir"<<endl<<endl;
		
		cout<<"Ingrese Una Opcion de Menu: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				CrearArchivo();
				break;
			case 2:
				GuardarDatos(texto);
				break;
			case 3:
				BuscarInformacion(texto);
				break;
			case 4:
				break;
			default: cout<<"Ingreso Una Opcion Incorrecta";
			
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(opcion != 4);
	
	return 0;
}
