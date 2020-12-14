#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	//tiene que ser cuadrada
	
	int numeros[100][100], nFilas, nColumnas;
	
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
	
	//Mostrando mtariz
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nColumnas;j++){
			cout<<numeros[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<"\nSu Matriz Transpuesta es: "<<endl;
	for(int i=0;i<nFilas;i++){
		for(int j=0;j<nColumnas;j++){
			cout<<numeros[j][i]<<" ";
		}
		cout<<endl;
	}
	
	system("pause");
	return 0;
}
