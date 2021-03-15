#include<iostream>//in out entrda y salida
#include<stdlib.h>// Evitar que el 

using namespace std;

int main(){
	
	int numero;
	
	do{
		cout<<"Digite un Numero: ";
		cin>>numero;
		
	}while((numero<1) || (numero>10));
	
	for(int i=1;i<=20;i++){
		cout<<numero<<" X "<<i<<" = "<<numero*i<<endl;
	}
	
	cout<<endl;
	
	system("pause");
	return 0;
}
