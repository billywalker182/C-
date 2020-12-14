
#include<string>
#include "lista.h"
#include"nodo.h"
#include<fstream>
using std::string;
using std::stringstream;
/*
Nombre: Lina Marcela Bonill Rincon 
Grupo 304
Codigo 20201578111
*/
void menu(lista Mercado);
void Mostrar(lista Mercado);
void Lectura(lista Mercado);
void Insertar(lista Mercado,int);
void Eliminar(lista Mercado, int);
void Guardar(lista Mercado);



int main(){
	lista Mercado;
	menu(Mercado);
	return 0;
}
void menu(lista Mercado){
	int opc;
	int ref;
	int rof;
	
	
	do{
		system("cls");
		cout<<"\t::MENU::"<<endl<<endl;
		cout<<"\t1.Leer los datos de los productos de la lista "<<endl;
		cout<<"\t2.Mostrar los datos de los productos de la lista "<<endl;
		cout<<"\t3.Insertar al inicio de la lista"<<endl;
		cout<<"\t4 Insertar al Final de la lista"<<endl;
		cout<<"\t5.Eliminar del inicio de la lista "<<endl;
		cout<<"\t6.Eliminar del Final de la lista "<<endl;
		cout<<"\t7.Guardar los datos de los productos de la lista"<<endl;
		cout<<"\t8.Salida "<<endl;
		cout<<"\tDigite la opcion del menu: ";
		cin>>opc;
		switch(opc){
		case 1:
			system("cls");
			Lectura(Mercado);
		break;
		case 2:
			system("cls");
			Mostrar(Mercado);
			
		break;
		case 3:
			system("cls");
			ref=1;
			Insertar(Mercado, ref);
			//Insertar Inicio
		break;
		case 4:
		   system("cls");
            ref=2;
			Insertar(Mercado, ref);
			//Insertar Final
		break;
		case 5:
			system("cls");
			rof=3;
		    Eliminar(Mercado,rof);
			// Eliminar Inicio
		break;
		case 6:
			system("cls");
			rof=4;
			Eliminar(Mercado,rof);
		    //Eliminar Final
		break;
		case 7:
			system("cls");
			Guardar(Mercado);
			//Guardar 
		break;
		case 8:
			exit(0);
			//Salida
		break;
		}
		
		
	}while(opc!=8);	
}
void Lectura(lista Mercado){
	ifstream Leer("datosP.txt");
	
	
	string nom;
	int pre;
	while(Leer>>nom>>pre||!Leer.eof()){
		nodo *x= new nodo();
		Producto tem(nom,pre);
		x->setdato(tem);
		Mercado.InsertarInicio(x);
	}
	cout<<"\tARCHIVO LEIDO"<<endl;
	system("pause");
	menu(Mercado);
} 
void Mostrar(lista Mercado){
	nodo x;
	if(Mercado.getPrimerptr()==0){
		Mercado.InsertarInicio(&x);
		Mercado.Mostrar();
	}else{
		Mercado.Mostrar();
	}
	
}
void Insertar(lista Mercado, int ref){
	string m;
	int precio;
	cout<<"\tInsertar un nuevo producto "<<endl;
	cout<<"\t ingrese nuevo producto"<<endl;
	cin>>m;
	cout<<"\t ingrese el precio"<<endl;
	cin>>precio;
	nodo y;
	Producto tem(m,precio);
	y.setdato(tem);
	if(ref==1){
		Mercado.InsertarInicio(&y);
	}else if(ref==2){
		Mercado.InsertarFinal(&y);
	}
    menu(Mercado);
	
}
void Eliminar(lista Mercado, int rof){
	nodo xy;
	if(rof==3){
		Mercado.EliminarInicio(&xy);
		
	}else if(rof==4){
		Mercado.EliminarFinal(&xy);
	}
}

void Guardar(lista Mercado){
	ofstream Guardar("“datosLista.txt");
	if(Mercado.getPrimerptr()!=0){
		nodo *aux=new nodo();
		aux=Mercado.getUltimoptr();
		while(aux!=0){
			Guardar<<aux->getdato().getNombre()<<" "<<aux->getdato().getPrecio()<<endl;
			aux=aux->getSiguienteptr();
		}
	}
	cout<<"\t LISTA GUARDADA "<<endl;
	
	
}



