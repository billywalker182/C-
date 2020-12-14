#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int numeros[3][3]={{1,2,1},{2,1,2},{2,1,2}};
	int matriz[3][3]={{1,2,3},{1,1,1},{1,1,1}};;
	int resultado[3][3];
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<numeros[i][j]<<" ";
		}
		cout<<endl;
	}
	
	cout<<endl;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	cout<<"\nLa Multiplicacion de las matries son: "<<endl;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			resultado[i][j]=0;
			for(int k=0;k<3;k++){
				resultado[i][j] += numeros[i][k]*matriz[k][j];
			}
		}
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<resultado[i][j]<<" ";
		}
		cout<<endl;
	}
	
	system("pause");
	return 0;
}
