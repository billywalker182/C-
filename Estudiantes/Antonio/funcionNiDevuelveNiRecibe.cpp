#include<iostream>
#include<stdlib.h>

using namespace std;

//	:::PROTOTIPO DE LA FUNCION:::
int Suma(int x, int y);
void Hola(string Nombre);




int main(){
	
	int a,b,resultado;
	
	
	
	Hola("Jhon");
	Hola("Antonio");
	
	cout<<endl<<endl<<endl;
	
	cout<<"Ingrese Numero 1: ";cin>>a;
	cout<<"Ingrese Numero 2: ";cin>>b;
	
	resultado=Suma(a,b);
	
	cout<<"La suma de los Numeros es: "<<resultado<<endl;
	
	
	system("Pause");
	return 0;
}

//Dedinir Fu7ncion

void Hola(string Nombre){
	cout<<"Hola "<<Nombre<<endl;
	cout<<"Hola "<<Nombre<<endl;
	cout<<"Hola "<<Nombre<<endl;
	cout<<"Hola "<<Nombre<<endl;
	cout<<"Hola "<<Nombre<<endl;
	cout<<"Hola "<<Nombre<<endl;
	cout<<"Hola "<<Nombre<<endl;
	cout<<"Hola "<<Nombre<<endl;
	cout<<"Hola "<<Nombre<<endl;
}

int Suma(int x, int y){
	int resultado;
	resultado = x+y;
	return resultado;
}
