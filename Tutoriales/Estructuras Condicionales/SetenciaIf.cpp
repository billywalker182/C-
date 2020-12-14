#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int numero, dato = 5;
	
	cout<<"Digite Un Numero: ";
	cin>>numero;
	
	if(numero==dato){
		cout<<"El numero es 5"<<endl;
	}
	else{
		cout<<"El Numero es Diferente de 5"<<endl;
	}
	
	system("pause");
	return 0;
}
