#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	
	int competencia[5][5]={{68,56,78,67,34},{10,34,56,23,11},{16,17,14,17,19},{32,45,56,67,76},{34,42,56,43,34}};
	int sumaColumnas[5]={0,0,0,0,0};
	int menor = 9999999999999;
	int grupo = 0;
	
	
	cout<<"             |Grupo 1|Grupo 2|Grupo 3|Grupo 4|Grupo 5|"<<endl;
	cout<<"             |-------|-------|-------|-------|-------|"<<endl;
	for(int nFilas=0;nFilas<5;nFilas++){
		cout<<"Ejercicio["<<nFilas+1<<"] |";
		for(int nColumnas = 0;nColumnas<5;nColumnas++){
			cout<<competencia[nFilas][nColumnas]<<"     |";
			sumaColumnas[nFilas] += competencia[nColumnas][nFilas];
		}
		cout<<endl;
	}
	cout<<"             |-------|-------|-------|-------|-------|"<<endl;
	cout<<"Suma Minutos |";
	for(int i=0;i<5;i++){
		cout<<sumaColumnas[i]<<"    |";
		if(sumaColumnas[i]<menor){
			menor = sumaColumnas[i];
			grupo = i + 1;
		}
	}
	cout<<"\n             |-------|-------|-------|-------|-------|"<<endl;
	
	cout<<endl;
	
	
	cout<<"\nEl menor Tiempo fue: "<<menor<<" Minutos y Lo realizo el Grupo: "<<grupo<<endl;
	cout<<"FELICITACIONES!!!!!"<<endl<<endl;
	
	system("pause");
	return 0;
}
