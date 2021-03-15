#include <iostream>
#include <conio.h>
#include <stdlib.h> // atoi() y atof()
#include <string.h>

using namespace std;

int main(){
	
	/// TRANSFORMAR UNA CADENA A FLOTANTES:::
	char numero[] = "123.005";
	float num = atof(numero)+0.01;//sumar flotante
	cout<<num<<endl<<endl;
	
	/// TRANSFORMAR UNA CADENA A ENTEROS:::
	char numero1[] = "123";
	int num1 = atoi(numero1)+210;//sumar entero
	cout<<num1<<endl<<endl;
	
	getch();
	return 0;
}
