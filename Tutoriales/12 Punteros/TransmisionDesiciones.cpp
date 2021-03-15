#include<iostream>// manejasr datos entradas y salidas
#include<conio.h>//utilizar getch que practicamente evita que se cierre la ventana

using namespace std;

//		:::PROTOTIPO DE FUNDIÓN:::
void intercambio(float *,float *);

int main(){
	
	float num1 = 20.8, num2 = 6.78;
	
	cout<<"primer Numero: "<<num1<<endl;
	cout<<"Segundo numero: "<<num2<<endl;
	
	intercambio(&num1,&num2);//enviamos la dirección
	
	cout<<"\n\nDespues del intercambio: \n\n";
	cout<<"El nuevo valor de num1: "<<num1<<endl;
	cout<<"El nuevo valor de num2: "<<num2<<endl;
	
	
	getch();//evitar que se cierre la ventana
	return 0;
}

void intercambio(float *dirNm1, float *dirNm2){
	float aux;
	aux = *dirNm1;
	*dirNm1 = *dirNm2;
	*dirNm2 = aux;
}
