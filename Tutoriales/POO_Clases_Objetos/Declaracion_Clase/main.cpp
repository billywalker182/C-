#include <iostream>
// creacion objetos
#include "Persona.h"

using namespace std;

int main(int argc, char** argv) {
	
	Persona p1("Jhon",29);//Creacion de un objeto estatico
	
	cout<<"El nombre es: "<<p1.getNombre()<<endl;
	cout<<"La Edad es: "<<p1.getEdad()<<endl;
	
	Persona* p2 = new Persona();//Creacion objeto dinamico, todo lo que tiene punteros se relaciona con dinamico
	p2->setNombre("Katherine");
	p2->setEdad(22);
	
	cout<<"El nombre es: "<<p2->getNombre()<<endl;
	cout<<"La Edad es: "<<p2->getEdad()<<endl;
	
	
	
	//Arreglo de objetos
	Persona persona[4];//Creacion de un arreglo de objetos estaticos
	Persona* persona2 = new Persona[3];//Creacion de un arreglo de objetos dinamico
	
	string nombre,cedula;
	int edad;
	
	cout<<"\t::PEDIR DATOS:::"<<endl;
	for(int i=0;i<3;i++){
		(persona2+i)->pedirDatos();
		cout<<endl;
	}
	
	cout<<"\t::MOSTRAR DATOS:::"<<endl;
	for(int i=0;i<3;i++){
		(persona2+i)->mostrarDatos();
		cout<<endl;
	}
	//cuando son estaticos automaticamente lo hace
	delete persona2;//dinamico nos toca eliminarlo
	
	
	return 0;
}
