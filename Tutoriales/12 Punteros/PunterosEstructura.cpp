#include<iostream>// manejasr datos entradas y salidas
#include<conio.h>//utilizar getch que practicamente evita que se cierre la ventana

using namespace std;

struct Persona{
	char nombre[30];
	int edad;
}persona,*puntero_persona=&persona;

void pedirDatos();
void mostrarDatos(Persona *);

int main(){
	
	pedirDatos();
	mostrarDatos(puntero_persona);
	
	
	getch();//evitar que se cierre la ventana
	return 0;
}

void pedirDatos(){
	cout<<"Digite su nombre: ";
	cin.getline(puntero_persona->nombre,30,'\n');
	cout<<"Digite su edad: ";
	cin>>puntero_persona->edad;
	
}

void mostrarDatos(Persona *puntero_persona){
	cout<<"Nombre: "<<puntero_persona->nombre<<endl,
	cout<<"Edad: "<<puntero_persona->edad<<endl;
}
