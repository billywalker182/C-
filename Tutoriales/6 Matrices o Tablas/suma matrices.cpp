#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int numeros[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int matriz[3][3]={{11,12,13},{14,15,16},{17,18,19}};;
	
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
	
	
	cout<<"\nLa suma de las matries son: "<<endl;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matriz[i][j]+numeros[i][j]<<" ";
		}
		cout<<endl;
	}
	
	system("pause");
	return 0;
}
