#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	//tiene que ser cuadrada
	
	int numeros[100][100], nFilas, nColumnas;
	int contador = 0;
	
	cout<<"Digite el Numero de Filas: ",
	cin>>nFilas;
	cout<<"Digite el Numero De Columnas: ";
	cin>>nColumnas;
	
	//Almacenando elementos en la matriz
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nColumnas;j++){
			cout<<"Digite un Numero["<<i<<"]["<<j<<"]: ";
			cin>>numeros[i][j];
		}
		cout<<endl;
	}
	
	if(nFilas == nColumnas){
		for(int i=0;i<nFilas;i++){
			for(int j=0;j<nColumnas;j++){
				if(numeros[i][j]==numeros[j][i]){
					contador++;
				}
			}
		}
	}

	if(contador==(nFilas*nColumnas)){
		cout<<"La Matriz Es Simetrica"<<endl;
	}
	else{
		cout<<"La Matriz NO Es Simetrica"<<endl;
	}
	
	
	system("pause");
	return 0;
}
