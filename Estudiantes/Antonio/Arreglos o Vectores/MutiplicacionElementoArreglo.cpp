#include<iostream>//in out entrda y salida
#include<stdlib.h>// Evitar que el 

using namespace std;

int main(){
	
	int numero[]={1,2,3,4,5};
	int mult = 1;
	
	for (int i = 0;i<=4;i++){
		mult = mult * numero[i];
		//mul *= numero[i]
	}
	
	cout<<"La multiplicacion de los elementos del vector es: "<<mult<<endl;
	
	system("pause");
	return 0;
}
