#include<iostream>// manejasr datos entradas y salidas
#include<conio.h>//utilizar getch que practicamente evita que se cierre la ventana
#include<stdlib.h>

using namespace std;

int **puntero_matriz,nFilas,nCol;//Puntero matriz; señala una matriz


//		:::PROTOTIPO DE FUNDIÓN:::
void pedirDatos();
void mostrarMatriz(int **,int,int);



int main(){
	
	pedirDatos();
	mostrarMatriz(puntero_matriz,nFilas,nCol);
	
	for(int i=0;i<nFilas;i++){
		delete[] puntero_matriz[i];
	}
	
	delete[] puntero_matriz;
	
	
	getch();//evitar que se cierre la ventana
	return 0;
}

void pedirDatos(){
	cout<<"Digite el numero de Filas: ";
	cin>>nFilas;
	cout<<"Digite el numero de columas: ";
	cin>>nCol;
	
	puntero_matriz = new int*[nFilas];//reservando memoria para las filas
	for(int i=0;i<nFilas;i++){
		puntero_matriz[i] = new int[nCol];//reservando memoria para las columnas
	}
	
	cout<<"\nDigitando elementos de la matriz: "<<endl;
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<"Digite un numero["<<i<<"]["<<j<<"]: ";
			cin>>*(*(puntero_matriz+i)+j);//puntero[i][j]
		}
	}
	
}

void mostrarMatriz(int **puntero_matriz,int nFilas,int nCol){
	cout<<"\nImprimiendo matriz: "<<endl;
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nCol;j++){
			cout<<*(*(puntero_matriz+i)+j);
		}
		cout<<endl;
	}
}
