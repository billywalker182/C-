#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int numero, dato = 5;
	
	cout<<"Ingrese un Numero del 1 al 5: ";
	cin>>numero;
	
	
	switch(numero){
		
		case 1:
			cout<<"Este es el numero 1"<<endl;
		case 2:
			cout<<"Este es el numero 2"<<endl;
			break;
		case 3:
			cout<<"Este es el numero 3"<<endl;
			break;
		case 4:
			cout<<"Este es el numero 4"<<endl;
			break;
		case 5:
			cout<<"Este es el numero 5"<<endl;
			break;
		default: cout<<"Ingreso un numero difernte entre 1 y 5"<<endl;
	}
	
	system("pause");
	return 0;
}
