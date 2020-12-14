//Calculadora de operaciones vectoriales en R3
// Saul Rodríguez

#include<iostream>
#include<conio.h>


using namespace std;
float u[3];
float v[3];
float resultado[3];


//:::PEDIR DATOS:::
void pedirDatos(){
	cout<<"\n:::Vector U:::"<<endl;
	for(int i =0;i<3;i++){
		cout<<"Ingrese Valor["<<i<<"]: ";
		cin>>u[i];
	}
	
	cout<<"\n:::Vector V:::"<<endl;
	for(int i =0;i<3;i++){
		cout<<"Ingrese Valor["<<i<<"]: ";
		cin>>v[i];
	}
	
}

void mostrarDatos(){
	
	cout<<"\nU   -> ";
	for(int i=0;i<3;i++){
		cout<<u[i]<<"|";
	}
	cout<<endl;
	cout<<"V   -> ";
	for(int i=0;i<3;i++){
		cout<<v[i]<<"|";
	}
	cout<<endl;
	
}

void suma(){
	for(int i=0;i<3;i++){
		resultado[i]=u[i]+v[i];
	}
	
	cout<<"\nU+V -> ";
	for(int i=0;i<3;i++){
		cout<<resultado[i]<<"|";
	}
	cout<<endl<<endl;
}

void resta(){
	for(int i=0;i<3;i++){
		resultado[i]=u[i]-v[i];
	}
	
	cout<<"\nU-V -> ";
	for(int i=0;i<3;i++){
		cout<<resultado[i]<<"|";
	}
	cout<<endl<<endl;
}

void productoPunto(){
	float total = 0;
	for(int i=0;i<3;i++){
		resultado[i]=u[i]*v[i];
	}
	
	for(int i=0;i<3;i++){
		total += resultado[i];
	}
	cout<<"\nU.V -> "<<total;
	cout<<endl<<endl;
}

void productoCruz(){
	float total = 0;
	resultado[0] = (u[1]*v[2]) - (u[2]*v[1]);
	resultado[1] = (u[2]*v[0]) - (u[0]*v[2]);
	resultado[2] = (u[0]*v[1]) - (u[1]*v[0]);
	cout<<"\nUXV -> ";
	for(int i=0;i<3;i++){
		cout<<resultado[i]<<"|";
	}
	cout<<endl<<endl;
}

int main(){
	
	int opcion;
	
	do{
		cout<<"\n\t:::CALCULADORA DE OPERACIONES VECTORIALES EN R3:::"<<endl<<endl;
		cout<<"1. Suma"<<endl;
		cout<<"2. Resta"<<endl;
		cout<<"3. Producto Punto"<<endl;
		cout<<"4. Producto Cruz"<<endl;
		cout<<"5. Salir"<<endl;
		cout<<"\nIngrese una opcion: ";
		cin>>opcion;
		
		
		switch(opcion){
			case 1:
				pedirDatos();
				mostrarDatos();
				suma();
				break;
			case 2:
				pedirDatos();
				mostrarDatos();
				resta();
				break;
			case 3:
				pedirDatos();
				mostrarDatos();
				productoPunto();
				break;
			case 4:
				pedirDatos();
				mostrarDatos();
				productoCruz();
				break;
			case 5:
				break;
			default: cout<<"\nIngrese una Opcion de Menu Valida :( "<<endl<<endl;
		}
		system("pause");
		system("cls");	
		
	}while(opcion !=5);
	
	
	return 0;
}
