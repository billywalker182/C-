#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

//	:::PROTOTIPO DE LA FUNCION:::
int suma(int x, int y);

int main(){
	int a,b,Resultado;
	cout<<"Ingreseme Numero 1: ";cin>>a;
	cout<<"Ingreseme Numero 2: ";cin>>b;
	Resultado = suma(a,b);
	
	cout<<"La Suma es: "<<Resultado<<endl;
	
	system("pause");
	return 0;
}

//	:::DEFINICION DE LA FUNCION
int suma(int x, int y){
	
	int Sumando;
	
	Sumando = x+y;
	
	return Sumando;
	
}

