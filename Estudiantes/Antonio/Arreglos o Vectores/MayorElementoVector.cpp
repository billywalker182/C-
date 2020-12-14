#include<iostream>//in out entrda y salida
#include<stdlib.h>// Evitar que el 

using namespace std;

int main(){
	
	int numeros[100];
	int n;
	int mayor;
	
	cout<<"Digite el numero de elementos que va tener el arreglo: ";
	cin>>n;
	
	for (int i = 0; i<n;i++){
		cout<<i+1<<". Digite un numero: ";
		cin>>numeros[i];//Guardando todos los elementos del vector
		
		
		if(numeros[i]>mayor){
			mayor = numeros[i];
		}
	}
	
	cout<<"\nEl Mayor elemento del vector es: "<<mayor<<endl;
	
	
	system("pause");
	return 0;
}
