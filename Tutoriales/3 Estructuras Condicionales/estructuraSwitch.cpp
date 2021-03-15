#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int numero;
	
	cout<<"Digite un numero entre 1-5: ";
	cin>>numero;
	
	switch(numero){
		case 1:
			cout<<"Es el Numero 1";
			break;
		case 2:
			cout<<"Es el Numero 2";
			break;
		case 3:
			cout<<"Es el Numero 3";
			break;
		case 4:
			cout<<"Es el Numero 4";
			break;
		case 5:
			cout<<"Es el Numero 5";
			break;
			
	}
	
	system("pause");
	return 0;
}
