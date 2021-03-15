#include<iostream>//in out entrda y salida
#include<stdlib.h>// Evitar que el 

using namespace std;

int main(){
	
	int numero[]={1,2,3,4,5};
	int suma = 0;
	
	for (int i = 0;i<=4;i++){
		suma = suma + numero[i];
		//suma += numero[i]
	}
	
	cout<<"La suma de los elementos del vector es: "<<suma<<endl;
	
	system("pause");
	return 0;
}
