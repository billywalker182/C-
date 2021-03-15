#include<iostream>// manejasr datos entradas y salidas
#include<conio.h>//utilizar getch que practicamente evita que se cierre la ventana

using namespace std;

int main(){
	
	int numeros[] = {1,2,3,4,5};
	int *dir_numeros;
	
	dir_numeros = numeros;
	
	for(int i=0;i<5;i++){
		cout<<"Elemento del vector ["<<i<<"]: "<<*dir_numeros++<<endl;
	}
	
	
	getch();//evitar que se cierre la ventana
	return 0;
}
