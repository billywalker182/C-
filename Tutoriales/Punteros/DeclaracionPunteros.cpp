/*
&n -> La dirección de n
*n -> la variable cuya dirección esta almacena en n.
*/

#include<iostream>// manejasr datos entradas y salidas
#include<conio.h>//utilizar getch que practicamente evita que se cierre la ventana

using namespace std;

int main(){
	
	int num;
	num = 20;
	
	
	cout<<"Numero: "<<num<<endl;
	cout<<"Direccion Memoria: "<<&num<<endl;
	
	
	int *dir_num;
	dir_num = &num;
	
	cout<<"Numero: "<<*dir_num<<endl;
	cout<<"Direccion Memoria: "<<dir_num<<endl;
	
	
	getch();//evitar que se cierre la ventana
	return 0;
}
