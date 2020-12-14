#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int numeros[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	

	
	//Mostrando mtariz
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<numeros[i][j];
		}
		cout<<endl;
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i==j){
				cout<<numeros[i][j];
			}else{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
