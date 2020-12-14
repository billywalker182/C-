#include "Persona.h"


void Persona::setNombre(string _nombre){
	nombre = _nombre;
}
void Persona::setEdad(int _edad){
	edad = _edad;
}
void Persona::setCedula(string _cedula){
	cedula = _cedula;
}
string Persona::getNombre(){
	return nombre;
}
int Persona::getEdad(){
	return edad;
}
string Persona::getCedula(){
	return cedula;
}

void Persona::pedirDatos(){
	cout<<"Ingrese el nombre: ";
	getline(cin,nombre);
	cout<<"Ingrese la Edad: ";
	cin>>edad;
	fflush(stdin);
	cout<<"Ingrese la Cedula: ";
	getline(cin,cedula);
}

void Persona::mostrarDatos(){
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Edad: "<<edad<<endl;
	cout<<"Cedula: "<<cedula<<endl;
}
