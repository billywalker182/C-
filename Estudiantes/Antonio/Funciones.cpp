#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

void EstudianteCarrera(string Estudiante[],string Carrera[]){
	cout<<"\t:::ESTUDIANTES DE INGINERIA INDUSTRIAL:::"<<endl;
	for(int i=0;i<5;i++){
		if(Carrera[i]=="Industrial"){
			cout<<Estudiante[i]<<endl;
		}
	}
}

int main(){
	
	string Alumno[]={"Lina","Antonio","Mayra","Julian","Laura"};
	string Carrera[]={"Datos","Industrial","Biologia","Industrial","Industrial"};
	float Nota[]={3.6,4.1,3.9,4.2,4.6};
	EstudianteCarrera(Alumno,Carrera);
	
	system("pause");
	return 0;
}
