//jfksdhfkjdfgkdfgjdkfogj
/*
	kjhfksgjokid
	fjksakghjsdkg
	
		:::PUNTEROS:::
		
		&N -> la dirección
		*n -> puntero
*/

#include<iostream>//enmtrada y salida de datops
#include<conio.h>// getch()

using namespace std;


int main (){
	
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
