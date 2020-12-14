#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int numeros[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int matriz[3][3];
	

	
	//Mostrando mtariz
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			matriz[i][j] = numeros[i][j];
		};
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<matriz[i][j];
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
