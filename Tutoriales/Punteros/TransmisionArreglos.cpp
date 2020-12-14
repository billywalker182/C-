#include<iostream>// manejasr datos entradas y salidas
#include<conio.h>//utilizar getch que practicamente evita que se cierre la ventana

using namespace std;

//		:::PROTOTIPO DE FUNDIÓN:::
int hallarMax(int *,int);

int main(){
	
	const int nElementos = 5;
	int numeros[nElementos] = {3,5,7,8,1};
	
	cout<<"El mayor elemento es: "<<hallarMax(numeros,nElementos);
	
	
	getch();//evitar que se cierre la ventana
	return 0;
}

int hallarMax(int *dirVec, int nElementos){
	int max =0;
	for(int i=0;i<nElementos;i++){
		if(*(dirVec+i)>max){
			max = *(dirVec+i);
		}
	}
	
	return max;
	
}


