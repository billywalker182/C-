/*

New -> Reserva el numero de bytes solicitado.
Delete -> Libera la posción de memoria

*/


#include<iostream>// manejasr datos entradas y salidas
#include<conio.h>//utilizar getch que practicamente evita que se cierre la ventana
#include<stdlib.h>//para utilizar new y delete

using namespace std;

//	::VARIABLE LOCAL:::

int numCalif, *calif;

//	:::PROTOTIPO DE LA FUNCIÓN:::
void pedirNotas();
void mostrarNotas();

int main(){
	
	pedirNotas();
	mostrarNotas();
	
	delete[] calif;//liberando el espacio de memoria
	
	getch();//evitar que se cierre la ventana
	return 0;
}

void pedirNotas(){
	cout<<"Digite el numero de calificaciones: ";
	cin>>numCalif;
	
	calif = new int[numCalif];//Reservamos memoria para el arreglo
	
	for(int i=0;i<numCalif;i++){
		cout<<"Ingrese una Nota: ";
		cin>>calif[i];
	}
	
}

void mostrarNotas(){
	cout<<"\nMostrando notas del usuario:\n";
	for(int i=0;i<numCalif;i++){
		cout<<calif[i]<<endl;
	}
}
