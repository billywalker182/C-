#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main(){
	
	int numeros[100][100], nFilas, nColumnas;
	
	cout<<"Digite el Numero de Filas: ",
	cin>>nFilas;
	cout<<"Digite el Numero De Columnas: ";
	cin>>nColumnas;
	
	srand(time(NULL));
	
	//Almacenando elementos en la matriz
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nColumnas;j++){
			numeros[i][j] = 1+rand()%100;
		}
	}
	
	//Mostrando mtariz
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nColumnas;j++){
			cout<<numeros[i][j]<<" ";
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
